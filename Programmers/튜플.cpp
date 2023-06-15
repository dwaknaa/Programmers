#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool compare(string a, string b)
{
    return a.size() < b.size();
}


vector<int> solution(string s) {
    vector<int> answer;
    vector<string> strVec;
    
    string temp = s.substr(1, s.length()-2);
    
    while(1)
    {
        auto index = temp.find("},");
        if(index != string::npos)
        {
            strVec.push_back(temp.substr(0, index));
            temp = temp.substr(index+2);
        }
        else
        {
            auto index2 = temp.find("}");
            strVec.push_back(temp.substr(0, index2));
            break;
        }
    }
    
    sort(strVec.begin(), strVec.end(), compare);
    
    for(auto iter : strVec)
    {
        string numStr = iter.substr(1, s.length()-2);
        while(1)
        {
            auto index = numStr.find(",");
            if(index != string::npos)
            {
                int num = stoi(numStr.substr(0, index));
                if(find(answer.begin(), answer.end(), num) == answer.end())
                {
                    answer.push_back(num);
                }
                numStr = numStr.substr(index+1);
            }
            else
            {
                int num = stoi(numStr);
                if(find(answer.begin(), answer.end(), num) == answer.end())
                {
                    answer.push_back(num);
                }

                break;
            }
        }
    }
    
    return answer;
}
