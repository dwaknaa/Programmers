#include <vector>
#include <map>
using namespace std;

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;

    vector<int> cntVec;

    // 가중치 순으로 정렬하여 map 구성
    multimap<int, pair<int, int>> costMap;
    // root 섬 정보를 저장할 map 구성
    map<int, int> rootMap;
    for(auto iter : costs)
    {
        auto cost = iter;
        costMap.insert({cost[2], make_pair(cost[0], cost[1])});
        
        rootMap[cost[0]] = -1;
        rootMap[cost[1]] = -1;
    }

    for(auto iter : costMap)
    {
        auto aIsland = iter.second.first;
        auto bIsland = iter.second.second;

        answer += iter.first;

        if(rootMap[aIsland]==-1 && rootMap[bIsland]==-1)
        {
            rootMap[aIsland] = aIsland;
            rootMap[bIsland] = aIsland;
        }
        else if(rootMap[aIsland]==-1 && rootMap[bIsland]!=-1)
        {
            rootMap[aIsland] = rootMap[bIsland];
        }
        else if(rootMap[aIsland]!=-1 && rootMap[bIsland]==-1)
        {
            rootMap[bIsland] = rootMap[aIsland];
        }
        else
        {
            if(rootMap[aIsland] == rootMap[bIsland])
            {
                answer -= iter.first;
                continue;
            }

            int bIsLandRoot = rootMap[bIsland];
            for(auto i = rootMap.begin(); i!=rootMap.end(); i++)
            {
                if(i->second == bIsLandRoot)
                {
                    i->second = rootMap[aIsland];
                }
            }
        }
    }
        
    return answer;
}
