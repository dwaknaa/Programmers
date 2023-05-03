#include <string>
#include <vector>
#include <algorithm> // For count_if
#include <map>
using namespace std;

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    multimap<double, int, greater<double>> tempMap;
    
    for(int i=1; i<=N; i++)
    {
        int allCnt = std::count_if(stages.begin(), stages.end(),
                            [i](int elem) { return elem >= i; });
        
        if(allCnt == 0)
        {
            tempMap.insert({0, i});
            continue;
        }
        
        int clearCnt = std::count_if(stages.begin(), stages.end(),
                            [i](int elem) { return elem == i; });
        
        tempMap.insert({(double)clearCnt/(double)allCnt, i});
    }
    
    for(auto i : tempMap)
    {
        answer.push_back(i.second);
    }
    
    return answer;
}
