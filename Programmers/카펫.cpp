#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> commonMultiples;
    
    int totalSpace = brown+yellow;
    
    for(int i=1; i<totalSpace; i++)
    {
        if(totalSpace%i==0)
        {
            int commonMultiple = i;
            int mateCommonMultiple = totalSpace/i;

            int num=totalSpace-commonMultiple*2-mateCommonMultiple*2+4;

            if(num==yellow)
            {
                if(commonMultiple>mateCommonMultiple)
                {
                    answer.push_back(commonMultiple);
                    answer.push_back(mateCommonMultiple);
                }
                else
                {
                    answer.push_back(mateCommonMultiple);
                    answer.push_back(commonMultiple);
                }

                break;
            }
        }
    }
        
    return answer;
}
