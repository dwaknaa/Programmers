#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt = 0;
    int times = 0;
    
    while(1)
    {
        times++;
        int zeroCnt = count(s.begin(), s.end(), '0');
        cnt += zeroCnt;
        if(zeroCnt > 0) s.erase(remove(s.begin(), s.end(), '0'), s.end());
        
        bitset<32> bs(s.length());
        string bsstring = bs.to_string();
        
        auto index = bsstring.find("1");
        if(index == string::npos) break;
        s = bsstring.substr(index);
        
        if(s == "1") break;
    }
    
    answer.push_back(times);
    answer.push_back(cnt);
    
    return answer;
}
