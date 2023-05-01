#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n)
{
    int answer = 0;
    int sum = n;
    
    while(1)
    {
        if(sum < a) break;
        answer += (sum/a)*b;
        sum = sum%a + (sum/a)*b; // 바꾸고 남은 병 + 바꾸고 받은 병
    }

    return answer;
}
