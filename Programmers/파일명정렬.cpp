#include <string>
#include <vector>
#include <map>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    map<string, map<int, queue<tuple<string, string, string>>>> fileNameInfo;

    for(auto iter=files.begin(); iter!=files.end(); iter++)
    {
        string str=*iter;
        string head="", tail="", number="";
        int headIndex;
        for(int i=0;i<str.length();i++)
        {
            if(head.empty() && isdigit(str[i])!=0)
            {
                headIndex=i;
                head=str.substr(0, i);
            }
            
            if(!head.empty() && number.empty())
            {
                if(isdigit(str[i])==0 || i-headIndex >= 5)
                {
                    number=str.substr(headIndex, i-headIndex);
                }
            }
            
            if(!head.empty() && !number.empty())
            {
                tail = str.substr(i);
                break;
            }
        }
        
        if(number.empty() && !head.empty())
        {
            number = str.substr(headIndex);
        }
        
        string headTemp = head;
        std::transform(headTemp.begin(), headTemp.end(), headTemp.begin(), ::tolower);
        
        auto it = fileNameInfo.find(headTemp);
        int num = stoi(number);
        if(it == fileNameInfo.end())
        {
            map<int, queue<tuple<string, string, string>>> tempMap;
            
            queue<tuple<string, string, string>> tempQueue;
            tempQueue.push(make_tuple(number, tail, head));
            tempMap[num]=tempQueue;
            
            fileNameInfo[headTemp]=tempMap;
        }
        else
        {
            if(it->second.find(num)==it->second.end())
            {
                queue<tuple<string, string, string>> tempQueue;
                tempQueue.push(make_tuple(number, tail, head));
                it->second[num]=tempQueue;
            }
            else
            {
                it->second[num].push(make_tuple(number, tail, head));
            }
        }
    }

    for(auto iter=fileNameInfo.begin(); iter!=fileNameInfo.end(); iter++)
    {
        for(auto it=iter->second.begin(); it!=iter->second.end(); it++)
        {
            while (!it->second.empty())
            {
                string fileFullName="";
                fileFullName+=get<2>(it->second.front())+
                    get<0>(it->second.front())+get<1>(it->second.front());
                answer.push_back(fileFullName);
                
                it->second.pop();
            }
        }
    }
    
    return answer;
}
