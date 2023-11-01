#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<int, map<string, int>> comb;


void getComb(string order, vector<int> &course)
{
    int len = order.length();
        
    for(int i=0; i<course.size(); i++)
    {
        if(course[i] > len) break;
        
        vector<bool> temp(len);
        fill(temp.end() - course[i], temp.end(), true);
        
        do {
            string str = "";
            for (int j = 0; j < len; ++j)
            {
                if(temp[j]) str+= order[j];
            }

            sort(str.begin(), str.end());
            
            if(comb[str.length()].find(str)!=comb[str.length()].end())
            {
                comb[str.length()][str]++;
            }
            else
            {
                comb[str.length()].insert({str, 1});
            }
        } while (next_permutation(temp.begin(),temp.end()));
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i=0; i<course.size(); i++)
    {
        map<string, int> temp;
        comb[course[i]]=temp;
    }
    
    for(int i=0; i<orders.size(); i++)
    {
        getComb(orders[i], course);
    }
    
    for(auto iter=comb.rbegin(); iter!=comb.rend(); iter++)
    {
        int maxCnt = 0;
        for(auto it=iter->second.begin(); it!=iter->second.end(); it++)
        {
            if(it->second >= 2 && maxCnt <= it->second)
            {
                maxCnt = it->second;
            }
        }
        
        if(maxCnt == 0) continue;
        
        for(auto it=iter->second.begin(); it!=iter->second.end(); it++)
        {
            if(it->second >= maxCnt)
            {
                answer.push_back(it->first);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
