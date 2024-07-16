#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    // <진출 지점, 진입 지점>
    multimap<int, int> routeMap;
    for(auto iter=routes.begin(); iter!=routes.end(); iter++)
    {
        int in = iter->at(0);
        int out = iter->at(1);
        routeMap.insert({out, in});
    }
    
    auto iter = routeMap.begin();
    int beforeOut = iter->first;
    answer++;
    iter++;

    while(iter != routeMap.end())
    {
        // '이전 진출 >= 다음 진입 && 이전 진출 <= 다음 진출' 을 만족해야 이전에 설치했던 카메라 이용 가능
        
        // 만족하지 않는 경우 카메라 추가 설치
        if(!(iter->second <= beforeOut && iter->first >= beforeOut))
        {
            beforeOut = iter->first;
            answer++;
        }
        
        iter++;
    }
    
    return answer;
}
