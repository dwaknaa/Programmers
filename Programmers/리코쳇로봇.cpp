//
//  리코쳇로봇.cpp
//  Programmers
//
//  Created by user on 2024/12/05.
//

#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dx[] = {0, 0, -1, +1};
int dy[] = {+1, -1, 0, 0};

int func(int x, int y, const vector<string> &board)
{
    int xSize = board.front().size();
    int ySize = board.size();
    
    vector<vector<bool>> visited(ySize, vector<bool>(xSize, false));
    vector<vector<int>> cnt(ySize, vector<int>(xSize, 0));
    
    queue<pair<pair<int, int>, int>> que;
    que.push({{x, y}, 0});

    int minCnt = INT_MAX;
    while(!que.empty())
    {
        auto [curCoor, curCnt] = que.front();
        auto [curX, curY] = curCoor;
        que.pop();
        if(visited[curY][curX]) continue;
        visited[curY][curX] = true;
        
       for(int i=0; i<4; i++)
       {
           int tempX = curX;
           int tempY = curY;
           
           while(1)
           {
               tempX += dx[i];
               tempY += dy[i];

               if(tempX<0 || tempY<0 || tempX>=xSize || tempY>=ySize)
               {
                 if(tempX-dx[i]==curX && tempY-dy[i]==curY) break;

                   que.push({{tempX-dx[i], tempY-dy[i]}, curCnt+1});
                   break;
               }
               
               if(board[tempY][tempX]=='D')
               {
                  if(board[tempY-dy[i]][tempX-dx[i]]=='G')
                   {
                      if(minCnt > curCnt+1) minCnt = curCnt+1;
                      break;
                   }
                   que.push({{tempX-dx[i], tempY-dy[i]}, curCnt+1});
                   break;
               }
           }
       }
    }
    
    if(minCnt==INT_MAX) return -1;
    
    return minCnt;
}

int solution(vector<string> board) {
    int answer = 0;
    
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board.front().size(); j++)
        {
            if(board[i][j]=='R')
            {
                return func(j, i, board);
            }
        }
    }
    
    return answer;
}
