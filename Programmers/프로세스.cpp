#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> que;
    queue<int> indexQue;
    for(int i=0; i<priorities.size(); i++)
    {
        que.push(priorities[i]);
        indexQue.push(i);
    }
    
    sort(priorities.begin(), priorities.end());

    while(1)
    {
        if(que.front() == priorities.back())
        {
            que.pop();
            answer++;
            if(indexQue.front() == location)
            {
                break;
            }
            indexQue.pop();
            priorities.pop_back();
        }
        else
        {
            int num = que.front();
            que.pop();
            que.push(num);
            int index = indexQue.front();
            indexQue.pop();
            indexQue.push(index);
        }
    }
    
    return answer;
}
