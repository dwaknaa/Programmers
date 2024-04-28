#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

// 명함을 가로, 세로로 돌릴 수 있으므로
// 모든 가로 길이는 세로 길이가 될 수 있으며,
// 모든 세로 길이는 가로 길이가 될 수 있다.
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    multiset<int> widthSet;
    multiset<int> heightSet;
        
    for(int i=0; i<sizes.size(); i++)
    {
        int width = sizes[i][0] > sizes[i][1] ? sizes[i][0] : sizes[i][1];
        widthSet.insert(width);

        int height = sizes[i][0] < sizes[i][1] ? sizes[i][0] : sizes[i][1];
        heightSet.insert(height);
    }
    
    answer = *(widthSet.rbegin()) * *(heightSet.rbegin());
    
    return answer;
}
