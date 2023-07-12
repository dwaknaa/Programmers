#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
using namespace std;

const string enterStr="님이 들어왔습니다.";
const string leaveStr="님이 나갔습니다.";

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> recordMap;
    map<string, string> nicknameMap;
    
    for(int i=0; i<record.size(); i++)
    {
        stringstream ss(record[i]);
        string move, id, nickName;
        ss >> move >> id >> nickName;
        
        if(move != "Change")
        {
            recordMap.push_back(make_pair(id, move));
        }

        if(!nickName.empty())
        {
            nicknameMap[id]=nickName;
        }
    }
    
    for(auto iter=recordMap.begin(); iter!=recordMap.end(); iter++)
    {
        string result="";
        result += nicknameMap[iter->first];
        
        if(iter->second == "Enter") result+=enterStr;
        else result+=leaveStr;
        
        answer.push_back(result);
    }
    
    return answer;
}
