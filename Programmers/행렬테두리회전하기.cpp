//
//  행렬테두리회전하기.cpp
//  Programmers
//
//  Created by user on 2024/11/25.
//

#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    // 행렬 초기화
    int num = 1;
    vector<vector<int>> matrix;
    for(int i=0; i<rows; i++)
    {
        vector<int> temp;
        for(int j=0; j<columns; j++)
        {
            temp.push_back(num++);
        }
        matrix.push_back(temp);
    }
    
    // 회전 수행
    for(auto query : queries)
    {
        int y1 = query[0]-1;
        int x1 = query[1]-1;
        int y2 = query[2]-1;
        int x2 = query[3]-1;
        
        int curX = x1;
        int curY = y1;
        
        int beforeNum = matrix[curY][curX];
        int min = 10000; // 행렬이 최대 100x100이므로 10000으로 초기화
        while(1)
        {
            int nextX = curX;
            int nextY = curY;
            
            // 시계 방향 회전
            if(curX<x2 && curY==y1) nextX++;
            else if(curX==x2 && curY<y2) nextY++;
            else if(curX<=x2 && curX!=x1 && curY==y2) nextX--;
            else nextY--;
            
            // 한바퀴를 모두 돌았을 때 회전 종료
            if(nextX==x1 && nextY==y1)
            {
                int lastNum = exchange(matrix[y1][x1], beforeNum);
                if(min > lastNum) min = lastNum;
                break;
            }
            
            beforeNum = exchange(matrix[nextY][nextX], beforeNum);
            if(min > beforeNum) min = beforeNum;
            
            curX = nextX;
            curY = nextY;
        }
        
        answer.push_back(min);
    }
    
    return answer;
}
