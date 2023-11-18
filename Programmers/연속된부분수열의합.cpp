#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    map<int, vector<int>> candidateMap;
    
    for(int i=0; i<sequence.size(); i++)
    {
        int sum = 0;
        for(int j=i; j<sequence.size(); j++)
        {
            sum += sequence[j];
            if(sum > k) break;
            else if(sum == k)
            {
                if(candidateMap.find(j-i) != candidateMap.end()) break;
                candidateMap[j-i].push_back(i);
                candidateMap[j-i].push_back(j);
                break;
            }
        }
    }
    
    answer = candidateMap.begin()->second;
    
    return answer;
}
