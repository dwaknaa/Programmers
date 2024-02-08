#include <string>
#include <vector>

using namespace std;

int answerCnt = 0;

void func(int n, int sum)
{
    if(sum==n) answerCnt++;
    if(sum>=n) return;
    
    func(n, sum+1);
    func(n, sum+2);
}

int solution(int n) {
    int answer = 0;
    
    if(n%2!=0)
    {
        answer++;
        n-=1;
    }
    
    func(n, 0);
    
    answer += answerCnt;
    
    return answer;
}
