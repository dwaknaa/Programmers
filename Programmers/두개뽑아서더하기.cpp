#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> temp;
    
    for(int i=0; i<numbers.size()-1; i++)
    {
        for(int j=1; j<numbers.size(); j++)
        {
            if(i == j) continue;
            temp.insert({numbers[i]+numbers[j]});
        }
    }

    for(auto i : temp)
    {
        answer.push_back(i);
    }
    
    return answer;
}
