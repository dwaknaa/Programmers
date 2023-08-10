#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    // 여벌 체육복이 있는 학생이 도난당한 경우를 고려하기 위해 lost와 reserve 교집합을 구함
    vector<int> interVec(reserve.size());
    auto it = set_intersection(reserve.begin(), reserve.end(), lost.begin(), lost.end(), interVec.begin());
    interVec.resize(it-interVec.begin());
    
    for(auto iter=interVec.begin(); iter!=interVec.end(); iter++)
    {
        int index = find(lost.begin(), lost.end(), *iter)-lost.begin();
        lost[index]=0;
        
        index = find(reserve.begin(), reserve.end(), *iter)-reserve.begin();
        reserve[index]=-1;
    }
    
    answer = n-lost.size()+interVec.size();

    for(auto iter=lost.begin(); iter!=lost.end(); iter++)
    {
        if(*iter==0) continue;
        
        if(find(reserve.begin(), reserve.end(), *iter-1)!=reserve.end())
        {
            int index = find(reserve.begin(), reserve.end(), *iter-1)-reserve.begin();
            reserve[index]=0;
            answer++;
            continue;
        }
        
        if(find(reserve.begin(), reserve.end(), *iter+1)!=reserve.end())
        {
            int index = find(reserve.begin(), reserve.end(), *iter+1)-reserve.begin();
            reserve[index]=0;
            answer++;
            continue;
        }
    }
    
    return answer;
}
