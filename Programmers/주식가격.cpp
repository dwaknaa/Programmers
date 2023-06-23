#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i=0; i<prices.size(); i++)
    {
        int num = prices[i];
        queue<int> que;

        for(int j=i+1; j<prices.size(); j++)
        {
            if(num <= prices[j])
            {
                que.push(prices[j]);
            }
            else
            {
                que.push(prices[i]);
                break;
            }
        }
        
        answer.push_back(que.size());
    }

    return answer;
}
