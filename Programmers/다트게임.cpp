#include <string>
#include <stack>
#include <cctype> // For isdigit
#include <cmath> // For pow

using namespace std;

int solution(string dartResult)
{
    int answer = 0;
    bool pass = false;
    stack<string> st;
    
    for(int i=0; i < dartResult.length(); i++)
    {
        if(pass)
        {
            pass = false;
            continue;
        }
        
        if(dartResult[i] > 47 && dartResult[i] < 58)
        {
            if(dartResult[i]==49 &&
                dartResult[i+1]==48 &&
                i+1 < dartResult.length())
            {
                st.push("10");
                pass = true;
            }
            else
            {
                st.push(to_string(dartResult[i]-48));
            }
        }
        else
        {
            if(i+1 < dartResult.length() &&
               dartResult[i+1] > 47 && dartResult[i+1] < 58)
            {
                string str = dartResult.substr(i, 1);
                st.push(str);
            }
            else
            {
                if(i+1 < dartResult.length())
                {
                    string str = dartResult.substr(i, 2);
                    st.push(str);
                    pass = true;
                }
                else
                {
                    string str = dartResult.substr(i, 1);
                    st.push(str);
                }
            }
        }
    }
    
    bool star = false;
    while (!st.empty())
    {
        string str = st.top();
        st.pop();
        int num = stoi(st.top());
        st.pop();
        
        int temp=1;
        
        if(str.find("T") != string::npos)
        {
            temp = pow(num, 3);
        }
        else if(str.find("D") != string::npos)
        {
            temp = pow(num, 2);
        }
        else if(str.find("S") != string::npos)
        {
            temp = num;
        }

        if(star) temp *= 2;
        
        if(str.find("*") != string::npos)
        {
            answer += temp*2;
            star = true;
            continue;
        }
        else if(str.find("#") != string::npos)
        {
            answer -= temp;
        }
        else
        {
            answer += temp;
        }

        star = false;
    }
    
    return answer;
}
