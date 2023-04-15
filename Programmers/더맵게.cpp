#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    auto isUnder = [&K](int i) { return K > i; };
    make_heap(scoville.begin(), scoville.end(), greater<>{});
    
    while(1)
    {
        if(scoville.size() == 1 && scoville.front() < K) return -1;
        int under = count_if(scoville.begin(), scoville.end(), isUnder);

        if(under == 0)
        {
            return answer;
        }
        
        int first = scoville.front();
        pop_heap(scoville.begin(), scoville.end());
        scoville.pop_back();
        sort_heap(scoville.begin(), scoville.end());

        int second = scoville.front();
        pop_heap(scoville.begin(), scoville.end());
        scoville.pop_back();
        sort_heap(scoville.begin(), scoville.end());

        scoville.push_back(first + (second*2));
        push_heap(scoville.begin(), scoville.end());
        sort_heap(scoville.begin(), scoville.end());

        answer++;
    }
    
    return answer;
}
