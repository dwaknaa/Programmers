#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    map<string, vector<string>> alphaStringMap;
    
    for(auto iter : strings)
    {
        string alphabet = iter.substr(n, 1);
        if(alphaStringMap.find(alphabet) != alphaStringMap.end())
        {
            alphaStringMap[alphabet].push_back(iter);
        }
        else
        {
            vector<string> vec;
            vec.push_back(iter);
            alphaStringMap.insert({alphabet, vec});
        }
    }
    
    for(auto iter : alphaStringMap)
    {
        if(iter.second.size() == 1)
        {
            answer.push_back(iter.second.back());
        }
        else
        {
            sort(iter.second.begin(), iter.second.end());
            for(auto it : iter.second)
            {
                answer.push_back(it);
            }
        }
    }
    
    return answer;
}
