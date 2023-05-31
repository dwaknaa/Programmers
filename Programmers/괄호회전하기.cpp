#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i=0; i<s.length()-1; i++)
    {
        string temp = s;
        while(1)
        {
            bool check = false;
            if(temp.find("{}") != string::npos)
            {
                temp.erase(temp.find("{}"), 2);
                check = true;
            }
            if(temp.find("[]") != string::npos)
            {
                temp.erase(temp.find("[]"), 2);
                check = true;
            }
            if(temp.find("()") != string::npos)
            {
                temp.erase(temp.find("()"), 2);
                check = true;
            }
            
            if(!check || temp.length() == 0) break;
        }
        
        if(temp.length() == 0) answer++;
     
        string last = s.substr(s.length()-1, 1);
        s = last + s.substr(0, s.length()-1);
    }
    
    return answer;
}
