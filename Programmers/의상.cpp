#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, vector<string>> m;
    
    for(int i=0; i<clothes.size(); i++)
    {
        if(m.find(clothes[i][1]) != m.end())
        {
            m[clothes[i][1]].push_back(clothes[i][0]);
        }
        else
        {
            vector<string> vec;
            vec.push_back(clothes[i][0]);
            m.insert({clothes[i][1], vec});
        }
    }
    
    int multi=1;
    for(auto i=m.begin(); i!=m.end(); i++)
    {
        multi*= i->second.size()+1;
    }
    
    answer+=multi;
    answer--;
    
    return answer;
}
