#include <cmath>
using namespace std;

long long solution(long long n)
{
    long long answer = 0;
    
    double sqrtNum = sqrt(n);
    
    
    if(abs(sqrtNum - (int)sqrtNum < 1e-12))
    {
        answer = pow((sqrtNum+1), 2);
    }
    else
    {
        answer = -1;
    }
    
    return answer;
}
