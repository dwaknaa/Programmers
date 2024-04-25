#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    multiset<int, greater<int>> s;
    
    while(1)
    {
        if(answer >= enemy.size()) break;

        if(enemy[answer] <= n)
        {
            n -= enemy[answer];
            s.insert(enemy[answer]);
            answer++;
        }
        else
        {
            if(k==0) break;
            if(s.empty() || *s.begin() < enemy[answer])
            {
                k-=1;
                answer++;
            }
            else
            {
                n += *s.begin();
                s.erase(s.begin());
                k-=1;
            }
        }
    }
    
    return answer;
}
