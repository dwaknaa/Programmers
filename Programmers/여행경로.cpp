#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

vector<string> answerVec;
map<string, multiset<string>> m;

void dfs(multiset<string> &s, string depart)
{
    while(!s.empty())
    {
        string city = *s.begin();
        answerVec.push_back(city);
        s.erase(city);

        if(m.find(city)!=m.end() && !m.at(city).empty())
        {
            dfs(m.at(city), city);
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    for(int i=0; i<tickets.size(); i++)
    {
        std::string a = tickets[i][0];
        std::string b = tickets[i][1];
        if(m.find(a) == m.end())
        {
            multiset<string> s;
            s.insert(b);
            m[a] = s;
        }
        else
        {
            m[a].insert(b);
        }
    }
    
    answerVec.push_back("ICN");
    dfs(m.at("ICN"), "ICN");
    answer = answerVec;
    
    return answer;
}
