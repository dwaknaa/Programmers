#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    vector<int> temp;
    
    // 기능별로 speed에 따른 완료일 계산
    for(int i = 0; i < static_cast<int>(progresses.size()); i++)
    {
        int days;
        if((100-progresses[i]) > speeds[i])
        {
            if(((100-progresses[i]) % speeds[i]) == 0)
            {
                days = (100-progresses[i]) / speeds[i];
            }
            else
            {
                // 남은 진도가 speed로 딱 맞게 나누어지지 않으면 며칠 하고도 몇시간이 더 소요 되는데
                // 배포는 하루의 끝에 이루어지므로 완료일까지 하루가 더 필요함
                days = ((100-progresses[i]) / speeds[i])+1;
            }
        }
        else // 기능별 남은 진도가 speed보다 작거나 같을 때는 최대 하루면 완료
        {
            days = 1;
        }
        
        temp.push_back(days);
    }
    
    int count = 1;
    int distributeDay = temp[0]; // 앞의 배포일과 비교해야 하므로 메모리에 저장해둬야 함
    for(int j = 1; j < static_cast<int>(temp.size()); j++)
    {
        if(temp[j] <= distributeDay)
        {
            count++;
        }
        else
        {
            answer.push_back(count);
            count = 1;
            distributeDay = temp[j];
        }
    }
    
    answer.push_back(count);
    
    return answer;
}
