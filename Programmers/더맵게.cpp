#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    auto isUnder = [&K](int i) { return K > i; };
    
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while(1)
    {
        if(pq.top() >= K) return answer;
        if(pq.size() == 1 && pq.top() < K) return -1;
        
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        pq.push(first+(second*2));

        answer++;
    }
    
    return answer;
}
