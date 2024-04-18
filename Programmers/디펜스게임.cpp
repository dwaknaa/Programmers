#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> resultVec;

void func(int n, int k, vector<int> vec, int index)
{
    if(index < vec.size())
    {
        if(k > 0)
        {
            func(n, k-1, vec, index+1);
        }
        
        if(vec[index] <= n)
        {
            func(n-vec[index], k, vec, index+1);
        }
        else
        {
            if(k==0)
            {
                resultVec.push_back(index);
                return;
            }
        }
    }
    else
    {
        resultVec.push_back(index);
    }
}

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    func(n, k, enemy, 0);
    
    if(resultVec.size() > 0)
    {
        sort(resultVec.begin(), resultVec.end());
        answer = resultVec.back();
    }
    
    return answer;
}
