#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int number)
{
    if(number==2) return true;
    if(number==1 | number%2==0) return false;
    
    for(int i=3; i<=sqrt(number); i+=2)
    {
        if(number%i==0) return false;
    }
    
    return true;
}

int solution(int n) {
    int answer = 0;
    
    for(int i=2; i<=n; i++)
    {
        if(isPrime(i)) answer++;
    }
    
    return answer;
}
