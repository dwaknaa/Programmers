#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    auto isUnder = [&K](int i) { return K > i; };

    while(1)
    {
        sort(scoville.begin(), scoville.end());

        if(scoville.size() == 1 && scoville.front() < K) return -1;
        int under = count_if(scoville.begin(), scoville.end(), isUnder);

        if(under == 0)
        {
            return answer;
        }
        
        int first = scoville.front();
        scoville.erase(scoville.begin());
        int second = scoville.front();
        scoville.erase(scoville.begin());

        scoville.push_back(first + (second*2));
        
        answer++;
    }
    
    return answer;
}
