#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int storey) {
    int answer = 0;
    int length = to_string(storey).length();
    
    while(1)
    {
        int remainder = storey%10;
        int nextRemainder = storey%100 - remainder;

        if(remainder >= 6
          || (remainder==5 && nextRemainder>=50))
        {
            answer += (10-remainder);
            storey += 10;
        }
        else
        {
            answer += remainder;
        }
        
        string storeyStr = to_string(storey);
        storey = stoi(storeyStr.substr(0, storeyStr.length()-1));

        if(storey < 10) break;
    }
    
    if(storey >= 6) answer += (10-storey)+1;
    else answer += storey;
    
    return answer;
}
