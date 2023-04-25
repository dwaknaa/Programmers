#include <string>
#include <vector>
using namespace std;

int solution(string s) {
    int answer = 0;
    char ch = s[0];
    int chCnt = 1;
    int otherCnt = 0;
    bool reset = false;
    
    for(int i = 1; i < s.length(); i++)
    {
        if(reset)
        {
            ch = s[i];
            reset = false;
            chCnt++;
            continue;
        }
        
        if(s[i] == ch)
        {
            chCnt++;
        }
        else
        {
            otherCnt++;
        }
        
        if(chCnt == otherCnt)
        {
            answer++;
            reset = true;
            chCnt = 0;
            otherCnt = 0;
        }
    }
    
    if(!reset) answer++;
    
    return answer;
}
