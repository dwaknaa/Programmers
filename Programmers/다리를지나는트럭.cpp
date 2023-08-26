#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    reverse(truck_weights.begin(), truck_weights.end());
    vector<pair<int, int>> onBridgeVec;
    int onBridgeWeight = 0;
    
    while(1)
    {
        answer++; // 1초에 한 번 while문을 실행한다고 가정
        if(truck_weights.size()==0 && onBridgeWeight==0) break;

        if(!truck_weights.empty() &&
           onBridgeWeight+truck_weights.back() <= weight)
        {
            onBridgeWeight+=truck_weights.back();
            onBridgeVec.push_back(make_pair(truck_weights.back(), 0));
            truck_weights.pop_back();
        }
        
        for(auto it=onBridgeVec.begin(); it!=onBridgeVec.end(); it++)
        {
            it->second++;
        }
        
        if(onBridgeVec.front().second == bridge_length)
        {
            onBridgeWeight-=onBridgeVec.front().first;
            onBridgeVec.erase(onBridgeVec.begin());
        }
    }
    
    return answer;
}
