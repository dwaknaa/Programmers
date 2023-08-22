#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    for(int i=citations.size(); i>=0; i--)
    {
        int cnt = count_if(citations.begin(), citations.end(),
                          [&i](int elem) { return elem >= i; });
        
        if(cnt >= i)
        {
            answer = i;
            break;
        }
    }
    
    return answer;
}
