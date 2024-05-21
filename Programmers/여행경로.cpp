#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> ticket;
vector<string> ans;
vector<bool> visited;
bool check = false;

void dfs(string depart)
{
    if(ans.size()==ticket.size()) check = true;

    for(int i=0; i<ticket.size(); i++)
    {
        if(!visited[i] && ticket[i][0]==depart)
        {
            ans.push_back(ticket[i][1]);
            visited[i] = true;
            dfs(ticket[i][1]);
            
            if(!check)
            {
                ans.pop_back();
                visited[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end());
    ticket = tickets;
    
    visited.assign(tickets.size(), false);
    
    ans.push_back("ICN");
    dfs("ICN");
    
    answer = ans;
    
    return answer;
}
