#include <string>
#include <vector>
#include <climits>
using namespace std;

int answerCnt = INT_MAX;

void dfs(int x, int y, int n, int cnt)
{
    if(x == y && cnt <= answerCnt) answerCnt = cnt;

    if(x >= y) return;

    dfs(x*2, y, n, cnt+1);
    dfs(x*3, y, n, cnt+1);
    dfs(x+n, y, n, cnt+1);
}

int solution(int x, int y, int n) {
    int answer = 0;
    
    dfs(x, y, n, 0);
    
    if(answerCnt == INT_MAX)
    {
        answer = -1;
    }
    else
    {
        answer = answerCnt;
    }
    
    return answer;
}
