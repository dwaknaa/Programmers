#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

string answerWord="";
set<string> s;

void dfs(string str)
{
    s.insert(str);
    
    if(str.length()==5 || str==answerWord) return;
    
    dfs(str+"A");
    dfs(str+"E");
    dfs(str+"I");
    dfs(str+"O");
    dfs(str+"U");
}

int solution(string word) {
    int answer = 0;
    answerWord = word;
    dfs("");
    
    auto it = s.find(word);
    if(it!=s.end())
    {
        int index = std::distance(s.begin(), it);
        answer = index;
    }
    
    return answer;
}
