#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    stack<int> st;
    
    for(int i = static_cast<int>(numbers.size())-1; i >= 0 ; i--)
    {
        int number = numbers[i];
        
        while(1)
        {
            if(st.empty())
            {
                answer.push_back(-1);
                break;
            }
            
            if(st.top() <= number)
            {
                st.pop();
            }
            else
            {
                answer.push_back(st.top());
                break;
            }
        }
        
        st.push(number);
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
