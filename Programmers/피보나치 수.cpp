#include <string>
#include <vector>
using namespace std;

vector<long long> fibonacciVec;

void func(int endIndex)
{
    int vecSize = fibonacciVec.size();
    if(vecSize==endIndex+1) return;
    
    long long fibonacciNum=
        (fibonacciVec[vecSize-2]+fibonacciVec[vecSize-1])%1234567;
    
    fibonacciVec.push_back(fibonacciNum);
    
    func(endIndex);
}

int solution(int n)
{
    int answer = 0;
    
    fibonacciVec.push_back(0);
    fibonacciVec.push_back(1);
    
    func(n);
    
    answer = fibonacciVec.back();
    
    return answer;
}
