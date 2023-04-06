#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    answer.push_back(arr.front());
    int temp = arr.front();
    for(int i = 1; i < static_cast<int>(arr.size()); i++)
    {
        if(temp == arr[i])
        {
            continue;
        }
        
        answer.push_back(arr[i]);
        temp = arr[i];
    }
    
    return answer;
}
