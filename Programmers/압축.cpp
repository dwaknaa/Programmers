#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> strVec;
    queue<string> strQue;
    int num = 65;

    for(int i=1; i<=26; i++)
    {
        char ch = (char)num;
        string str(1, ch);
        strVec.push_back(str);
        num++;
    }
    
    for(int i=0; i<msg.length(); i++)
    {
        strQue.push(msg.substr(i, 1));
    }
    
    string str = "";
    while(!strQue.empty())
    {
        str += strQue.front();
        if(find(strVec.begin(), strVec.end(), str)!=strVec.end())
        {
            if(strQue.size()==1)
            {
                int index = find(strVec.begin(), strVec.end(), str)-strVec.begin();
                answer.push_back(index+1);
                break;
            }
            strQue.pop();
            continue;
        }
        strVec.push_back(str);
        string beforeStr = str.substr(0, str.length()-1);
        int index = find(strVec.begin(), strVec.end(), beforeStr)-strVec.begin();
        answer.push_back(index+1);
        
        str="";
    }

    
    return answer;
}
