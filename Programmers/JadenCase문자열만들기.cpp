#include <string>
#include <vector>
#include <cctype> // For isupper
using namespace std;

string solution(string s) {
    string answer = "";
    bool afterSpace = true;
    
    for(int i=0; i<s.length(); i++)
    {
        if(s.substr(i, 1) == " ")
        {
            afterSpace = true;
            continue;
        }
        
        if(afterSpace)
        {
            if(s[i] <= 122 && s[i] >= 97)
            {
                s[i] = toupper(s[i]);
            }
            
            afterSpace = false;
            continue;
        }
        else
        {
            if(isdigit(s[i]) == 0 && isupper(s[i]))
            {
                s[i] = tolower(s[i]);
            }
        }
    }
    
    answer = s;
    
    return answer;
}
