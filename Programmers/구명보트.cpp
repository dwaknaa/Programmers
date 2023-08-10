#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), greater<>());
    
    int size = people.size();
    int startIndex = 0;
    int endIndex = size-1;
    while(1)
    {
        if(size==0) break;
        
        if(size==1)
        {
            answer++;
            break;
        }
        
        if(people.at(startIndex)+people.at(endIndex)<=limit)
        {
            size -= 2;
            startIndex++;
            endIndex--;
            answer++;
        }
        else
        {
            size -= 1;
            startIndex++;
            answer++;
        }
    }
    
    return answer;
}
