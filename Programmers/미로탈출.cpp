//
//  미로탈출.cpp
//  Programmers
//
//  Created by user on 2024/11/11.
//

#include <string>
#include <vector>
#include <queue>
#include <utility> // For pair
using namespace std;

int dx[] = {0, 0, -1, +1};
int dy[] = {+1, -1, 0, 0};

pair<int, int> bfs(const vector<string> &maps, int x, int y, const char find, int &dis)
{
    // 방문 경로
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps.front().size(), false));
    // 시간 계산
    vector<vector<int>> dist(maps.size(), vector<int>(maps.front().size(), 0));

    queue<pair<int, int>> que;
    que.push({x, y});
    visited[y][x] = true;
    dist[y][x] = 0;
    
    while(!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();
        int curX = cur.first;
        int curY = cur.second;
        
        if(maps[curY][curX]==find)
        {
            dis = dist[curY][curX];
            return {curY, curX};
        }

        for(int i=0; i<4; i++)
        {
            int nextX = cur.first+dx[i];
            int nextY = cur.second+dy[i];
            
            if(nextX < 0 || nextX >= maps.front().size() || nextY < 0 || nextY >= maps.size()) continue;
            
            if(visited[nextY][nextX] || maps[nextY][nextX]=='X') continue;
            
            visited[nextY][nextX] = true;
            que.push({nextX, nextY});
            dist[nextY][nextX] = dist[curY][curX] + 1;
        }
    }
    
    return {0, 0};
}

int solution(vector<string> maps) {
    int answer = 0;
    
    for(int i=0; i<maps.size(); i++)
    {
        // 1. 출발 지점 찾기
        int index = maps[i].find('S');
        if(index != string::npos)
        {
            // 2. 레버까지의 거리 계산
            int dist = -1;
            auto res = bfs(maps, index, i, 'L', dist);
            
            // 2-1. 레버까지 도달하지 못했으면 -1 리턴
            if(dist==-1) return -1;
            answer += dist;
            
            // 3. 도착지까지의 거리 계산
            dist = -1;
            res = bfs(maps, res.second, res.first, 'E', dist);

            // 3-1. 도착지까지 도달하지 못했으면 -1 리턴
            if(dist==-1) return -1;
            answer += dist;
        }
    }
    
    return answer;
}
