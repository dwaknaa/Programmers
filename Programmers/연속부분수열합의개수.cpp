#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> answerSet;
    
    for(int i=1; i<=elements.size(); i++)
    {
        for(int j=0; j<elements.size(); j++)
        {
            queue<int> elementQue;

            for(auto iter = elements.begin(); iter!=elements.end(); iter++)
            {
                elementQue.push(*iter);
            }
            
            for(int n=0; n<j; n++)
            {
                int element = elementQue.front();
                elementQue.pop();
                elementQue.push(element);
            }
            
            int sum = 0;
            for(int k=j; k<j+i; k++)
            {
                int element = elementQue.front();
                sum += element;
                elementQue.pop();
                elementQue.push(element);
            }
            answerSet.insert(sum);
        }
    }
    
    answer = answerSet.size();
    
    return answer;
}
