#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solution(string s)
{
    int answer = -1;

    while(1)
    {
        bool changed = false;
        if(s.length() < 2) break;
        
        for(int i=0; i<s.length()-1; i++)
        {
            if(s.substr(i, 1) == s.substr(i+1, 1))
            {
                s[i] = '0';
                s[i+1] = '0';
                changed = true;
            }
        }
        
        if(!changed) break;
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
    }
    
    answer = 1;
    if (s.length() > 0) answer = 0;
    
    return answer;
}
