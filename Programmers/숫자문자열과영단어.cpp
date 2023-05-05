#include <string>
#include <vector>
#include <algorithm> // For find
#include <cctype>
using namespace std;

int solution(string s) {
    int answer = 0;
    string answerStr;
    string temp;
    
    vector<string> numString =
        {"zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"};
    
    for(int i=0; i<s.length(); i++)
    {
        if(isdigit(s[i]) != 0)
        {
            temp = "";
            answerStr += s[i];
        }
        else
        {
            temp += s[i];
        }
        
        if(!temp.empty() && temp.size() >= 3)
        {
            auto index = find(numString.begin(), numString.end(), temp);
            if(index != numString.end())
            {
                answerStr += to_string(distance(numString.begin(), index));
                temp = "";
            }
        }
    }
    
    answer = stoi(answerStr);
    
    return answer;
}
