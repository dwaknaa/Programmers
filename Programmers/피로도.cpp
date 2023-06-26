#include <string>
#include <vector>

using namespace std;

vector<bool> visited(9, false);
int answer = 0;

void dfs(int k, vector<vector<int>> dungeons, int cnt)
{
    for(int i=0; i<dungeons.size(); i++)
    {
        if(!visited[i] && k>=dungeons[i][0])
        {
            visited[i]=true;
            dfs(k-dungeons[i][1], dungeons, cnt+1);
            visited[i]=false;
        }
    }
    
    answer = max(answer, cnt);
}

int solution(int k, vector<vector<int>> dungeons)
{
    dfs(k, dungeons, 0);
    
    return answer;
}
