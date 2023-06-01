#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    multiset<int, greater<int>> s;
    
    while(1)
    {
        int num = tangerine.front();
        int cnt = count(tangerine.begin(), tangerine.end(), num);
        s.insert(cnt);
        tangerine.erase(remove(tangerine.begin(), tangerine.end(), num), tangerine.end());
        
        if(tangerine.size() == 0) break;
    }
    
    for(auto i=s.begin(); i!=s.end(); i++)
    {
        k -= *i;
        answer++;
        if(k <= 0) break;
    }
    
    return answer;
}
