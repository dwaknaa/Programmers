#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 50;

bool isOneCharDiff(const string &criterion, const string &str)
{
    int diffCharCount = 0;
    for(int i=0; i<criterion.size(); i++)
    {
        if(criterion[i]!=str[i]) diffCharCount +=1;
        
        if(diffCharCount > 1) return false;
    }

    return true;
}

void dfs(const string& begin, const string& target, const vector<string>& words, const int& count)
{
    static vector<bool> visited(words.size(), false);

    if(answer <= count) return;
    
    if(begin==target)
    {
        answer = min(count, answer);
        return;
    }
    
    for(int i=0; i<words.size(); i++)
    {
        if(!visited[i] && isOneCharDiff(begin, words[i]))
        {
            visited[i] = true;

            dfs(words[i], target, words, count+1);

            visited[i] = false;
        }
    }

    return;
}

int solution(string begin, string target, vector<string> words) {
    // words에 target이 없는 경우
    if(find(words.begin(), words.end(), target)==words.end()) return 0;
    
    dfs(begin, target, words, 0);
        
    return answer;
}
