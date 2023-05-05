#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    
    if(completion.size() > 1)
    {
        sort(participant.begin(), participant.end());
        sort(completion.begin(), completion.end());
        
        auto ret = mismatch(participant.begin(), participant.end(), completion.begin());
    
        if(!(*ret.first).empty())
        {
            answer = *ret.first;
        }
    }
    else
    {
        answer = participant.back();
    }

    return answer;
}
