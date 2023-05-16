#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<string> strStack;
    
    int startCnt = count(s.begin(), s.end(), '(');
    int endCnt = count(s.begin(), s.end(), ')');

    if(startCnt != endCnt) return false;
    
    int startParen = 0;
    int endParen = 0;
    
    for(int i=s.length()-1; i>=0; i--)
    {
        if(s[i] == ')')
        {
            endParen++;
        }
        else
        {
            if(endParen == 0) return false;
            startParen++;

            if(startParen > endParen) return false;
        }
        
        if(startParen == endParen)
        {
            startParen = 0;
            endParen = 0;
        }
    }
    
    return answer;
}
