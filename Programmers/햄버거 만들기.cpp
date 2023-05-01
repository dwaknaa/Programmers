#include <string>
#include <vector>
#include <algorithm> // For vector find
#include <iostream>
#include <sstream>
using namespace std;
//1-2-3-1
int solution(vector<int> ingredient) {
    int answer = 0;
    
    std::stringstream ss;
    for (auto it = ingredient.begin(); it != ingredient.end(); it++)
    {
        ss << *it;
    }

    std::string str = ss.str();
    std::string findStr = "1231";
    while(1)
    {
        auto index = str.find(findStr);
        if(index == string::npos)
        {
            break;
        }
        else
        {
            answer++;
            string before = str.substr(0, index);
            string after = str.substr(index+findStr.length());
            str = before + after;
        }
    }
    
    return answer;
}
