#include <string>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int visited[11][11][4] = {0, };
    int currentX = 5, currentY = 5;
    int direction;

    for(int i=0; i<dirs.size(); i++)
    {
        if(dirs[i] == 'U' && currentY < 10)
        {
            visited[currentX][currentY][1] = 1;
            direction = 0;
            currentY++;
        }
        else if(dirs[i] == 'D' && currentY > 0)
        {
            visited[currentX][currentY][0] = 1;
            direction = 1;
            currentY--;
        }
        else if(dirs[i] == 'L' && currentX > 0)
        {
            visited[currentX][currentY][3] = 1;
            direction = 2;
            currentX--;
        }
        else if(dirs[i] == 'R' && currentX < 10)
        {
            visited[currentX][currentY][2] = 1;
            direction = 3;
            currentX++;
        }
        else
        {
            continue;
        }
        
        if(!visited[currentX][currentY][direction])
        {
            visited[currentX][currentY][direction]=1;
            answer++;
        }
    }
    
    return answer;
}
