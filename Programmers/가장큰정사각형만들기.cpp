#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    if(board.size() == 1 || board[0].size() == 1)
    {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] == 1)
                {
                    return 1;
                }
            }
        }
    }
    
    for(int i=1; i<board.size(); i++)
    {
        for(int j=1; j<board[i].size(); j++)
        {
            if(!board[i][j]) continue;

            int side = min(min(board[i-1][j], board[i-1][j-1]), board[i][j-1]) + 1;
            board[i][j] = side;
            answer = max(answer, side);
        }
    }

    answer = pow(answer, 2);
    
    return answer;
}
