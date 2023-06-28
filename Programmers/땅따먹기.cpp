#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> cache;


void func(vector<vector<int>> land)
{
    cache.push_back(land[0]);

    for(int i=1; i<land.size(); i++)
    {
        vector<int> cacheTemp;
        for(int j=0; j<land[i].size(); j++)
        {
            vector<int> temp = cache.back();
            temp[j] = 0;
            sort(temp.begin(), temp.end());
            cacheTemp.push_back(land[i][j]+temp.back());
        }
        cache.push_back(cacheTemp);
    }
}

int solution(vector<vector<int>> land)
{
    int answer = 0;
    
    func(land);
    
    vector<int> result = cache.back();
    sort(result.begin(), result.end());
    answer = result.back();
    
    return answer;
}
