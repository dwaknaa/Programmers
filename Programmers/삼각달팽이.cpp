#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> snail;
    
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        cnt += i+1;
        vector<int> vec = vector<int>(n, 0);
        snail.push_back(vec);
    }
    
    int index = n-1;
    int height = 0;
    int num = 1;
    
    snail[height][index] = num;
    height++;
    index--;
    num++;
    
    while(1)
    {
        if(num > cnt || height+1 > n || index+1 > n) break;
        snail[height][index] = num;
        num++;
        
        if((index+1==n && snail[height-1][index]==0)
          || (index+1<n && height>0 && snail[height-1][index]==0 && snail[height][index+1]!=0))
        {
            height--;
            continue;
        }
        
        if(height+1 == n || (height+1<n && snail[height+1][index-1]!=0))
        {
            index++;
        }
        else
        {
            index--;
            height++;
        }
    }
    
    for(int i=0; i<snail.size(); i++)
    {
        for(int j=0; j<snail[i].size(); j++)
        {
            if(snail[i][j] != 0)
            {
                answer.push_back(snail[i][j]);
            }
        }
    }
    
    return answer;
}
