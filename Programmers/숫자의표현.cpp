#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int temp =1;
    while(1)
    {
        int sum = 0;
        for(int i=temp; i <= n; i++)
        {
            sum+=i;

            if(sum == n)
            {
                answer++;
                break;
            }
            else if (sum > n) break;
        }
        
        temp++;
        if(temp > n) break;
    }
    
    return answer;
}
