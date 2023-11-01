#include <string>
#include <vector>

using namespace std;

int getMateCnt(vector<int> weights, int index)
{
    int cnt=0;
    int weight = weights[index];
    
    for(int i=index+1; i<weights.size(); i++)
    {
        if(weight==weights[i])
        {
            cnt++;
            continue;
        }
        
        int mateWeight = weights[i];
        int big = weight>mateWeight ? weight:mateWeight;
        int small = weight>mateWeight? mateWeight:weight;
        
        if(big*2 == small*4
          || big*2 == small*3
          || big*3 == small*4)
        {
            cnt++;
        }
    }
    
    return cnt;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    
    for(int i=0; i<weights.size(); i++)
    {
        answer += getMateCnt(weights, i);
    }
    
    return answer;
}
