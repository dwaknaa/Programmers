#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(auto iter=skill_trees.begin(); iter!=skill_trees.end(); iter++)
    {
        queue<string> que;
        for(int i=0; i<skill.length(); i++)
        {
            que.push(skill.substr(i, 1));
        }
        
        bool ret = true;
        std::string skillStr = *iter;
        for(int i=0; i<skillStr.length(); i++)
        {
            string frontStr = skillStr.substr(i,1);
            if(skill.find(frontStr)==string::npos)
            {
                continue;
            }
            
            if(que.front()==frontStr) que.pop();
            else
            {
                ret = false;
                break;
            }
        }
        
        if(ret) answer++;
    }
    
    return answer;
}
