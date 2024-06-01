#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    // 순열 벡터 생성
    vector<bool> subVec(3, true); // 3개만 true
    subVec.insert(subVec.end(), number.size()-3, false); // 나머지는 false
    
    sort(subVec.begin(), subVec.end());
    
    do
    {
        int sum = 0;
        for(int i=0; i<number.size(); i++)
        {
            if(subVec[i]) sum += number[i];
        }

        if(sum==0) answer++;
    }while(next_permutation(subVec.begin(), subVec.end()));
    
    return answer;
}
