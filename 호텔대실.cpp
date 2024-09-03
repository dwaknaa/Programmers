#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

long getMin(std::string time)
{
    auto index = time.find(":");
    
    int hour = stoi(time.substr(0, index));
    int min = stoi(time.substr(index+1));
    
    return hour*60 + min;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    multimap<long, long> minMap;
    
    for(int i=0; i<book_time.size(); i++)
    {
        // 입실 시간으로 스케줄을 정렬하기 위함
        minMap.insert({getMin(book_time[i][0]), getMin(book_time[i][1])});
    }
    
    multiset<long> chkoutTime;
    
    for(auto iter=minMap.begin(); iter!=minMap.end(); iter++)
    {
        // 가장 먼저 체크아웃하는 방의 퇴실 시간보다
        // 입실 시간이 빠를 때
        if(chkoutTime.empty()
           || *chkoutTime.begin() > iter->first)
        {
            // 청소가 끝나는 시간으로 계산하여 set에 insert
            chkoutTime.insert(iter->second + 10);
        }
        else
        {
            // 가장 먼저 체크아웃하는 방의 퇴실 시간보다
            // 입실 시간이 늦을 때
            // 기존 방을 이어서 사용(재활용) 가능
            chkoutTime.erase(chkoutTime.begin());
            chkoutTime.insert(iter->second + 10);
        }
    }
    
    answer = chkoutTime.size();
    
    return answer;
}
