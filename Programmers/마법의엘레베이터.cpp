#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int storey) {
    int answer = 0;
    int numLen = to_string(storey).size();
    
    while(1)
    {
        if(storey == 0) return answer;
        numLen -= 1;

        int mostBig = (int)pow(10, numLen);
        if(storey>mostBig && storey/mostBig > 5)
        {
            int temp = 10 - storey/mostBig;
            answer += temp;
            storey = storey + temp*mostBig;
        }
        else
        {
            answer += storey/mostBig;
            storey = storey - (storey/mostBig)*mostBig;
        }

        if(numLen == 0 || storey == 0) break;
    }
    
    if(storey > 5)
    {
        answer += 10-storey+1;
    }
    else
    {
        answer += storey;
    }
    
    return answer;
}
