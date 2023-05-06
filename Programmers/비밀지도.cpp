#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;
    
    for(int i=0; i<n; i++)
    {
        string bit1 = bitset<16>(arr1[i]).to_string();
        string bit2 = bitset<16>(arr2[i]).to_string();

        string answerTemp;
        
        for(int j=bit1.length()-n;j<bit1.length();j++)
        {
            if(bit1.substr(j, 1) =="1" || bit2.substr(j, 1) == "1")
            {
                answerTemp += "#";
            }
            else
            {
                answerTemp += " ";
            }
        }
        
        answer.push_back(answerTemp);
    }
    
    return answer;
}
