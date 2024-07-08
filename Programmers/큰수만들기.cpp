#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int size = number.size()-k;
    int startIndex = 0;
    for(int i=0; i<size; i++)
    {
        char max = number[startIndex];
        int maxIndex = startIndex;
        for(int j=startIndex; j<=k+i; j++)
        {
            if (max < number[j])
            {
                max = number[j];
                maxIndex = j;
            }
        }
        startIndex = maxIndex+1;
        answer += max;
    }
    
    return answer;
}
