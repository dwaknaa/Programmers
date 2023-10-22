#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    long long cnt = 0;
    
    for(int i=0; i<n; i++)
    {
        if(left/n > i)
        {
            cnt += n;
            continue;
        }
        
        for(int j=0; j<n; j++)
        {
            cnt++;
            
            if(cnt < left+1) continue;
            if(cnt > right+1) return answer;
            
            if(i==j) answer.push_back(i+1);
            else if(i>j) answer.push_back(i+1);
            else answer.push_back(j+1);
        }
    }
    
    return answer;
}
