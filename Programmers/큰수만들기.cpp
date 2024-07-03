#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<string> combineVec;
    
    vector<int> numVec;
    for(int i=0; i<number.size(); i++)
    {
        numVec.push_back(stoi(number.substr(i, 1)));
    }
    
    int len = numVec.size();
    vector<bool> temp;
    temp.assign(len, true);
    for(int i=0; i<k; i++)
    {
        temp[i] = false;
    }
    
    string max = "";
    do {
        string num = "";
        for (int i = 0; i<numVec.size(); i++)
        {
            if(temp[i])
            {
                num += to_string(numVec[i]);
            }
        }
        
        if(max.empty())
        {
            max = num;
        }
        else if(!max.empty() && max < num)
        {
            max = num;
        }

    } while (next_permutation(temp.begin(),temp.end()));
    
    answer = max;
    
    return answer;
}
