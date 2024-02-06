#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<bool> visited;

void bfs(int start, int size, vector<vector<int>>& computers)
{
    queue<int> que;
    
    que.push(start);
    visited[start] = true;
    
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        
        for(int i=0; i<size; i++)
        {
            if(computers[cur][i] && !visited[i])
            {
                que.push(i);
                visited[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    visited = vector<bool>(n, false);
    
    for(int i=0; i<computers.size(); i++)
    {
        if(!visited[i])
        {
            answer++;
            bfs(i, n, computers);
        }
    }
    
    return answer;
}
