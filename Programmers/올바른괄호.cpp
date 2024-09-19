#include<string>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    // 여는 괄호 개수 확인을 위한 변수
    int openParenCnt = 0;
    
    // 문자열 s를 맨 앞글자부터 검토
    for(int i=0; i<s.length(); i++)
    {
        // 여는 괄호보다 닫는 괄호가 많이 나온 부분 문자열일 경우
        if(openParenCnt < 0)
        {
            answer = false;
            break;
        }
        
        if(s.substr(i, 1)=="(") openParenCnt++;
        else openParenCnt--;
    }
    
    // 괄호들이 바르게 짝지어져 있지 않은 경우
    if(openParenCnt != 0) answer = false;
    
    return answer;
}
