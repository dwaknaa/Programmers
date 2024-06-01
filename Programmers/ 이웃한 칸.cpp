#include <string>
#include <vector>

using namespace std;

int dx[] = {0, 0, -1, +1};
int dy[] = {+1, -1, 0, 0};

int getSameColorCnt(const vector<vector<string>> &board, const int h, const int w)
{
    int cnt = 0;
    // 주어진 칸의 상하좌우를 탐색
    for(int i=0; i<4; i++)
    {
        int nx = w+dx[i];
        int ny = h+dy[i];
        
        if(nx < 0 || ny < 0 || nx >= board[h].size() || ny >= board.size()) continue;
        
        if(board[ny][nx] == board[h][w]) cnt++;
    }
    
    return cnt;
}

int solution(vector<vector<string>> board, int h, int w) {
    
    int answer = getSameColorCnt(board, h, w);
    
    return answer;
}
