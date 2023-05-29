#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    bitset<32> b(n);
    std::string nBit = b.to_string();
    int cnt = std::count(nBit.begin(), nBit.end(), '1');
    
    answer = n;
    while(1)
    {
        answer++;
        
        bitset<32> temp(answer);
        std::string tempBit = temp.to_string();
        int tempCnt = std::count(tempBit.begin(), tempBit.end(), '1');
        
        if(tempCnt == cnt) break;
    }
    
    return answer;
}
