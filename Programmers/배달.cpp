//
//  배달.cpp
//  Programmers
//
//  Created by user on 2024/11/18.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

vector<int> dijkstra(vector<pair<int, int>> road[], int N)
{
    priority_queue<pair<int, int>> que;
    vector<int> time(N+1, INT_MAX);

    // 항상 1번 마을에서 출발
    time[1] = 0;
    que.push({0, 1});
    
    while(!que.empty())
    {
        int curTime = -que.top().first;
        int curNode = que.top().second;
        que.pop();
        
        if (curTime > time[curNode]) continue;
        
        for (auto [nextNode, nextTime] : road[curNode])
        {
              nextTime += curTime;
         
            if(nextTime < time[nextNode])
            {
                time[nextNode] = nextTime;
                que.push({-nextTime, nextNode});
            }
        }
    }
    
    return time;
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;

    vector<pair<int, int>> graph[N+1];
    
    for(int i=0; i<road.size(); i++)
    {
        graph[road[i][0]].push_back({road[i][1], road[i][2]});
        graph[road[i][1]].push_back({road[i][0], road[i][2]});
    }

    vector<int> timeVec = dijkstra(graph, N);
    for(auto time : timeVec)
    {
        if(time <= K) answer++;
    }
    
    return answer;
}
