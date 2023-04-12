#include<string>
#include <iostream>
#include <algorithm>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    if(s.at(s.length()-1) == '('
      || s.length() % 2 != 0) return false;
    
    while(1)
    {
        if(s.at(0) == ')'  ||
           count(s.begin(), s.end(), '(') != count(s.begin(), s.end(), ')'))
        {
            return false;
        }
        
        auto index = s.find(")(");

        if(index == string::npos)
        {
            if(count(s.begin(), s.end(), '(') != count(s.begin(), s.end(), ')'))
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        
        string temp = s.substr(0, index+1);
        
        if(temp.length() % 2 != 0 ||
           count(temp.begin(), temp.end(), '(') !=
           count(temp.begin(), temp.end(), ')'))
        {
            return false;
        }
        else
        {
            temp = s.substr(index+1);
            s = temp;
        }
    }

    return answer;
}
