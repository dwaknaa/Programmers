#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s)
{
    string answer = "";
    vector<int> numberVec;
    
    while(1)
    {
        auto index = s.find(" ");
        if(index == string::npos)
        {
            numberVec.push_back(stoi(s));
            break;
        }
        numberVec.push_back(stoi(s.substr(0, index)));
        
        s = s.substr(index+1);
    }
    
    sort(numberVec.begin(), numberVec.end());
    
    answer = to_string(numberVec.front()) + " " + to_string(numberVec.back());
    
    return answer;
}
