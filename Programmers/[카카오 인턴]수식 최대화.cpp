#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
using namespace std;

vector<string> getAllExpression(string expression)
{
    vector<string> exprVec;
    for(int i=0; i<expression.size(); i++)
    {
        string str = expression.substr(i, 1);
        if((str == "*" || str == "+" || str == "-")
          && find(exprVec.begin(), exprVec.end(), str) == exprVec.end())
        {
            exprVec.push_back(str);
        }
    }
    
    return exprVec;
}

vector<string> getExprPrioityComb(vector<string> exprVec)
{
    vector<string> vec;
    
    if(exprVec.size() == 1)
    {
        vec.push_back(exprVec.front());
        return vec;
    }
    
    sort(exprVec.begin(), exprVec.end());
    
    do{
        string str = "";
        for(int i=0; i<exprVec.size(); i++)
        {
            str += exprVec[i];
        }

        vec.push_back(str);
    }while(next_permutation(exprVec.begin(), exprVec.end()));
    
    return vec;
}


int getNum(string str, bool isBefore)
{
    string result;
    
    if(isBefore)
    {
        for(int i=str.size()-1; i>=0; i--)
        {
            try
            {
                if(i==0 && str.substr(i, 1) == "-")
                {
                    reverse(result.begin(), result.end());
                    return stol(result)*-1;
                }
                 result += to_string(stol(str.substr(i, 1)));
            }
            catch (const std::invalid_argument&)
            {
                reverse(result.begin(), result.end());
                return stol(result);
            }
        }
        reverse(result.begin(), result.end());
        return stol(result);
    }
    
    bool minus = false;
    for(int i=0; i<str.size(); i++)
    {
        try
        {
            if(i==0 && str.substr(i, 1) == "-")
            {
                minus = true;
                continue;
            }
             result += to_string(stol(str.substr(i, 1)));
        }
        catch (const std::invalid_argument&)
        {
            long long ans = stol(result);
            if(minus) ans *= -1;
            return ans;
        }
    }
    
    long long ans = stol(result);
    if(minus) ans *= -1;
    return ans;
}

long long calculate(string expr, long long a, long long b)
{
    if(expr == "*") return a*b;
    else if(expr == "+") return a+b;
    else return a-b;
}

int findMinusIndex(string str)
{
    for(int i=1; i<str.length(); i++)
    {
        if(str.substr(i, 1) == "-")
        {
            if(str.substr(i-1, 1) != "*" && str.substr(i-1, 1) != "+")
                return i;
        }
    }
    
    return 0;
}

long long getResult(string expr, string str)
{
    string temp = str;
    for(int i=0; i<expr.size(); i++)
    {
        string e = expr.substr(i, 1);
        while(1)
        {
            auto index = temp.find(e);
            if(index == string::npos) break;

            if(e == "-")
            {
                index = findMinusIndex(temp);
                if(index == 0) break;
            }
            
            string before = temp.substr(0, index);
            long long beforeNum = getNum(before, true);
            string after = temp.substr(index+1);
            long long afterNum = getNum(after, false);
            
            long long result = calculate(e, beforeNum, afterNum);
           
            int size = before.size()-to_string(beforeNum).size();
            
            string st = "";
            if(size > 0) st += before.substr(0, size);
            st += to_string(result);
            if(after.size() > to_string(afterNum).size())
            {
                st += after.substr(to_string(afterNum).size());
            }
            temp = st;
        }
    }
    
    return abs(stol(temp));
}


vector<long long> getResultVec(vector<string> exprComb, string str)
{
    vector<long long> resultVec;
    for(int i=0; i<exprComb.size(); i++)
    {
        try
        {
            resultVec.push_back(getResult(exprComb[i], str));
        }
        catch(...)
        {
        }
    }
    
    return resultVec;
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<string> exprVec = getAllExpression(expression);
    vector<string> exprComb = getExprPrioityComb(exprVec);
    vector<long long> resultVec = getResultVec(exprComb, expression);
    
    sort(resultVec.begin(), resultVec.end());
    answer = resultVec.back();
    
    return answer;
}
