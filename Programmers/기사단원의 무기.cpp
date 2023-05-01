#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power)
{
    int answer = 1; // 1은 약수가 무조건 1개 이므로 1로 초기화
    
    for(int i = 2; i <= number; i++) // 1의 약수는 이미 고려하였으므로 2부터 순회
    {
        int temp = 2; // 1과 자기 자신(i)을 고려하였으므로
        for(int j = 2; j <= i/2; j++) // 약수는 절반까지만 구하면 됨
        {
            if(i % j == 0) temp++;
        }
        
        if(temp <= limit) answer += temp;
        else answer += power;
    }
    
    return answer;
}
