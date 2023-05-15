#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> check;
    int turn = 1;
    int person = 1;
    for(int i=0; i<words.size(); i++)
    {
        if(check.size() > 0 && check.back().back() != words[i].front())
        {
            cout << "check" << endl;
            answer.push_back(person);
            answer.push_back(turn);
            break;
        }
        
        if(find(check.begin(), check.end(), words[i]) == check.end())
        {
            check.push_back(words[i]);
        }
        else
        {
            answer.push_back(person);
            answer.push_back(turn);
            break;
        }
        
        if((i+1)%n == 0)
        {
            cout << "turn" << endl;
            turn++;
            person = 1;
        }
        else
        {
            person++;
        }
    }

    if(answer.size() == 0)
    {
        answer = {0, 0};
    }
    
    return answer;
}
