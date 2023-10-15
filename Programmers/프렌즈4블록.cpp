#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(1)
    {
        set<pair<int, int>> s;

        for(int i=0; i<m-1; i++)
        {
            string xStr = board[i];

            for(int j=0; j<n-1; j++)
            {
                if(xStr[j]=='@') continue;
                
                if(xStr[j]!=xStr[j+1]) continue;
                if(xStr[j]!=board[i+1][j]) continue;
                if(xStr[j]!=board[i+1][j+1]) continue;

                s.insert(make_pair(i, j));
                s.insert(make_pair(i, j+1));
                s.insert(make_pair(i+1, j));
                s.insert(make_pair(i+1, j+1));
            }
        }

        if(s.size()==0) break;
        
        for(auto iter=s.begin(); iter!=s.end(); iter++)
        {
            auto p = *iter;
            board[p.first][p.second] = '@';
        }

        answer += s.size();

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[j][i]=='@')
                {
                    for(int k=j; k>0; k--)
                    {
                        board[k][i] = board[k-1][i];
                    }
                    
                    board[0][i] = '@';
                }
            }
        }
    }
    
    return answer;
}
