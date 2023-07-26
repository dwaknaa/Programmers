#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> subCont;
    vector<int> vec;
    
    for(int i=0; i<order.size(); i++)
    {
        vec.push_back(i+1);
    }
    
    int vecIndex=0;
    int orderIndex=0;
    while(1)
    {
        if(vec[vecIndex]!=order[orderIndex])
        {
            subCont.push(vec[vecIndex]);
            vecIndex++;
        }
        else
        {
            orderIndex++;
            vecIndex++;
            answer++;
        }
        
        while(!subCont.empty())
        {
            if(order[orderIndex]==subCont.top())
            {
                answer++;
                orderIndex++;
                subCont.pop();
            }
            else
            {
                break;
            }

            if(orderIndex >= order.size()) break;
        }
        
        if(orderIndex >= order.size() || vecIndex >= order.size())
        {
            break;
        }
    }
    
    while(!subCont.empty())
    {
        if(order[orderIndex]==subCont.top())
        {
            answer++;
            orderIndex++;
            subCont.pop();
        }
        else
        {
            break;
        }
        
        if(orderIndex >= order.size()) break;
    }
    
    return answer;
}
