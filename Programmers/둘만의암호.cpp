#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";

    for(int i = 0; i < s.length(); i++)
    {
        string tempStr = "";
        
        int num = (int)s[i];
        int cnt = 0;
        int check = 1;
        while(1)
        {
            if(num+check <= 122)
            {
                if(skip.find((char)num+check) == string::npos)
                {
                    cnt++;
                }
            }
            else
            {
                int temp = num+check;
                while(1)
                {
                    temp = temp - 122 + 97 - 1;
                    if(temp <= 122) break;
                }
                
                if(skip.find((char)temp) == string::npos)
                {
                    cnt++;
                }
            }

            if(cnt == index) break;
            check++;
        }
        
        int ch = num+check;
        if(ch > 122)
        {
            while(1)
            {
                ch = ch - 122 + 97 - 1;
                if(ch <= 122) break;
            }
            answer += (char)ch;
        }
        else
        {
            answer += (char)ch;
        }
    }

    return answer;
}
