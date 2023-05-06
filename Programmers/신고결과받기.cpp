#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

// 각 유저별로 신고한 사람(중복x) 리스트가 필요
// map -> 신고당한사람(key), 신고한 사람(value)
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, set<string>> listMap;
    
    for(int i=0; i<id_list.size(); i++)
    {
        set<string> s;
        listMap.insert({id_list[i], s});
    }
    
    for(int i=0; i<report.size(); i++)
    {
        auto index = report[i].find(" ");
        if(index != string::npos)
        {
            string user = report[i].substr(0, index);
            string id = report[i].substr(index+1);
            listMap[id].insert(user);
        }
    }
    
    for(int i=0; i<id_list.size(); i++)
    {
        int cnt = 0;
        for(int j=0; j<id_list.size(); j++)
        {
            if(listMap.at(id_list[j]).size() >= k &&
              listMap.at(id_list[j]).find(id_list[i]) != listMap.at(id_list[j]).end())
            {
                cnt++;
            }
        }
        
        answer.push_back(cnt);
    }
    
    return answer;
}
