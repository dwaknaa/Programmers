#include <string>
#include <vector>

using namespace std;

long long getCaseCnt(int n)
{
    long long caseCnt = 1;
    for(int i=1; i<=n; i++)
    {
        caseCnt*=i;
    }
    
    return caseCnt;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> vec;
    for(int i=1; i<=n; i++)
    {
        vec.push_back(i);
    }
    
    int cnt = 1;
    long long now = k;
    while(cnt != n)
    {
        long long tmp = getCaseCnt(n-cnt);
        int idx = (now-1) / tmp;
        answer.push_back(vec[idx]);
        vec.erase(vec.begin()+idx);
        cnt++;
        now %= tmp;
        if (now == 0) now = tmp;
    }
    answer.push_back(vec.front());
    return answer;
}
