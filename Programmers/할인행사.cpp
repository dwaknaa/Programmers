#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i=0; i<discount.size()-9; i++)
    {
        for(int k=0; k<want.size(); k++)
        {
            if(count(discount.begin()+i, discount.begin()+i+10, want[k])<number[k])
            {
                break;
            }
            
            if(k==want.size()-1) answer++;
        }
    }
    
    return answer;
}
