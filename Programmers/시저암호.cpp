#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(char c : s)
    {
        if(isspace(c))
        {
            answer += c;
        }
        else
        {
            int temp = (int)c+n;
            if(islower(c)) // 소문자일 때
            {
                if(temp > 122)
                {
                    while(1)
                    {
                        temp = temp-122+97-1;
                        if(temp <= 122) break;
                    }
                }
            }
            else // 대문자일 때
            {
                if(temp > 90)
                {
                    while(1)
                    {
                        temp = temp-90+65-1;
                        if(temp <= 90) break;
                    }
                }
            }

            answer += (char)temp;
        }
    }
    
    return answer;
}
