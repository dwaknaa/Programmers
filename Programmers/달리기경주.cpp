#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer;
    
    map<int, string> rankKeyMap; // rank, player_name
    map<string, int> nameKeyMap; // player_name, rank
    
    for(int i = 0; i < static_cast<int>(players.size()); i++)
    {
        rankKeyMap.insert({i, players[i]});
        nameKeyMap.insert({players[i], i});
    }
    
    for(int j = 0; j < static_cast<int>(callings.size()); j++)
    {
        string name = callings[j]; // 추월한 선수의 이름
        int rank = nameKeyMap[name]; // 추월한 선수의 순위
        string tempName = rankKeyMap[rank-1];
        rankKeyMap[rank-1] = name;
        rankKeyMap[rank] = tempName;
        nameKeyMap[name] = rank-1;
        nameKeyMap[tempName] = rank;
    }
    
    for(int k = 0; k < static_cast<int>(rankKeyMap.size()); k++)
    {
        answer.push_back(rankKeyMap[k]);
    }
    
    return answer;
}
