#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> passingQue;
    for(int i=0; i<bridge_length; i++)
    {
        // 각 차들의 현재 위치를 파악하기 위해서
        // 무게 제한으로 인해 트럭이 다리에 오르지 못하는 시간에는
        // 0으로 채우기 위함
        passingQue.push(0);
    }
    
    int curWeightSum = 0; // 현재 다리 위에 있는 트럭들의 무게 합
    int passedCnt = 0; // 지나간 트럭의 대수
    int passingIndex = 0; // 다음으로 지나가야 하는 트럭의 index
    while(passedCnt < truck_weights.size())
    {
        answer++;
        int passedTruckWeight = passingQue.front();
        passingQue.pop();
        
        if(passedTruckWeight > 0)
        {
            passedCnt++;
            curWeightSum -= passedTruckWeight;
        }
        
        int nextTruckWeight = truck_weights[passingIndex];
        if(curWeightSum+nextTruckWeight <= weight)
        {
            passingQue.push(nextTruckWeight);
            passingIndex++;
            curWeightSum += nextTruckWeight;
        }
        else
        {
            passingQue.push(0);
        }
    }
    
    return answer;
}
