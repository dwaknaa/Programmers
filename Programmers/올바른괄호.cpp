#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int endCnt = 0;
    
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i] == ')') endCnt++;
        else endCnt--;
        
        if(endCnt < 0) return false;
    }

    if(endCnt > 0) answer = false;
    return answer;
}
