#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int start = 0;
    int end = 0;
    int sum = sequence[start];
    int minLength = sequence.size()+1;
    int answerStart = 0;
    int answerEnd = 0;
    
    while(start <= end && end < sequence.size())
    {
        if(sum < k)
        {
            end++;
            sum += sequence[end];
            continue;
        }
        else if(sum == k
          && end-start < minLength)
        {
            answerStart = start;
            answerEnd = end;
            minLength = end-start;
        }
        
        sum -= sequence[start];
        start++;
    }
    
    answer.push_back(answerStart);
    answer.push_back(answerEnd);
    
    return answer;
}
