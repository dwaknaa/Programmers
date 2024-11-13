//
//  무인도여행.cpp
//  Programmers
//
//  Created by user on 2024/11/14.
//

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {+1, -1, 0, 0};


int bfs(const vector<string> &maps, int x, int y, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> que;
    
    que.push({y, x});
    visited[y][x] = true;
    int days = stoi(maps[y].substr(x, 1));
    
    while(!que.empty())
    {
        int curX = que.front().second;
        int curY = que.front().first;
        
        que.pop();
        
        // 상하좌우 식량이 있는지 탐색
        for(int i=0; i<4; i++)
        {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            
            if(nextX<0 || nextX>=maps.front().size() || nextY<0 || nextY>=maps.size()) continue;
            
            if(maps[nextY][nextX] == 'X' || visited[nextY][nextX]) continue;
            
            que.push({nextY, nextX});
            visited[nextY][nextX] = true;
            days += stoi(maps[nextY].substr(nextX, 1));
        }
    }
    
    return days;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps.front().size(), false));

    while(1)
    {
        int beforeSize = answer.size();
        int curSize = answer.size();
        for(int i=0; i<maps.size(); i++)
        {
            for(int j=0; j<maps.front().size(); j++)
            {
                if(maps[i][j]!='X' && !visited[i][j])
                {
                    answer.push_back(bfs(maps, j, i, visited));
                }
            }
        }
        // 더 이상 식량이 있는 곳이 없는 경우 종료
        if(beforeSize == curSize) break;
    }

    if(answer.empty()) answer.push_back(-1);
    else sort(answer.begin(), answer.end()); // 오름차순 정렬
    
    return answer;
}
