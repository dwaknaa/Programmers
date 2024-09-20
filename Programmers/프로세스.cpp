#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<int> indexQue;
    multiset<int, greater<int>> sortedSet;
    for(int i=0; i<priorities.size(); i++)
    {
        indexQue.push(i);
        sortedSet.insert(priorities[i]);
    }
    
    while(1)
    {
        int num = priorities.front();
        priorities.erase(priorities.begin());
        
        int index = indexQue.front();
        indexQue.pop();

        int maxNum = *(sortedSet.begin());
        if (num != maxNum)
        {
            // 이번에 꺼낸 프로세스의 우선순위가
            // 현재 기준 가장 높은 우선순위가 아닌 경우 실행하지 않고 다시 넣음
            priorities.push_back(num);
            indexQue.push(index);
            
            continue;
        }
        
        // 실행 횟수 +1
        answer++;

        // 목표 프로세스가 실행된 경우 반복문 종료
        if(index == location)
        {
            break;
        }
        
        // 실행한 프로세스의 우선순위 정보 삭제
        sortedSet.erase(sortedSet.begin());
    }
    
    return answer;
}
