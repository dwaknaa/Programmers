#include <string>
#include <vector>
using namespace std;

int getNeedDays(int progresses, int speeds)
{
    int days = (100-progresses) / speeds;
    int hours = (100-progresses) % speeds;
        
    if(hours > 0) days+=1;
    
    return days;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int beforeDays = getNeedDays(progresses[0], speeds[0]);
    int count = 1;
    for(int i=1; i<progresses.size(); i++)
    {
        int days = getNeedDays(progresses[i], speeds[i]);
        
        if(beforeDays < days) // 이전 기능의 작업 종료일보다 이후에 끝날 때
        {
            // 이전 작업들 먼저 배포 진행
            answer.push_back(count);
            
            // 새로운 배포날이 정해졌으므로 각 값 초기화
            count = 1;
            beforeDays = days;
        }
        else // 이전 기능의 작업 종료일보다 이전에 끝날 때
        {
            count++;
        }
    }
    answer.push_back(count);
    
    return answer;
}
