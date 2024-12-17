//
//  전력망을둘로나누기.cpp
//  Programmers
//
//  Created by user on 2024/12/17.
//

#include <string>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;


int getNodeCnt(int node, int cutted, const vector<vector<int>> graph)
{
    int cnt = 0;
    
    vector<bool> visited(graph.size(), false);
    queue<int> que;
    que.push(node);
    
    while(!que.empty())
    {
        int cur = que.front();
        visited[cur] = true;
        que.pop();
        cnt++;
        
        for(auto i : graph[cur])
        {
            // 방문하지 않았거나 이어진 노드일 경우에
            if(i != cutted && !visited[i]) que.push(i);
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    vector<vector<int>> graph (n+1);
    
    for (auto wire : wires)
    {
        graph[wire[0]].push_back(wire[1]);
        graph[wire[1]].push_back(wire[0]);
    }
    
    for (auto wire : wires)
    {
        // 나뉘어진 두 그래프 조각의 노드 개수 차 계산
        int first = getNodeCnt(wire[0], wire[1], graph);
        int second = getNodeCnt(wire[1], wire[0], graph);

        // 최소 노드 차 갱신
        if (abs(first-second) < answer) answer = abs(first-second);
    }
    
    return answer;
}
