#include <string>
#include <vector>

using namespace std;

int getMax(vector<vector<int>> triangle)
{
    // 아래층부터 대각선에서 가장 큰 수(누적합)을 더하면서 위로 올라감
    for(int i=triangle.size()-2; i>=0; i--)
    {
        for(int j=0; j<=i; j++)
        {
            triangle[i][j] += max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    
    return triangle[0][0];
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    answer = getMax(triangle);
    
    return answer;
}
