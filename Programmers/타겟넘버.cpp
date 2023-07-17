#include <string>
#include <vector>

using namespace std;

int targetNumber;
int targetCnt = 0;

void dfs(vector<int> numbers, bool sign, int sum, int index)
{
    if(sign)
    {
        sum += numbers[index];
    }
    else
    {
        sum -= numbers[index];
    }
    
    if(index == numbers.size()-1)
    {
        if(sum == targetNumber) targetCnt++;
        return;
    }
    
    dfs(numbers, true, sum, index+1);
    dfs(numbers, false, sum, index+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    targetNumber = target;
    
    dfs(numbers, true, 0, 0);
    dfs(numbers, false, 0, 0);
    
    answer = targetCnt;
    
    return answer;
}
