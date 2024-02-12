#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    vector<int> dp = vector<int>(n, 0);
    
    dp[0] = 1;
    dp[1] = 2;
    
    for(int i=2; i<n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
    
    answer = dp.back();
    
    return answer;
}
