#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    multiset<int, greater<int>> rankSet; // 자동으로 내림차순 정렬을 하기 위해 set 사용
    
    for(int i = 0; i < static_cast<int>(score.size()); i++)
    {
        rankSet.insert(score[i]);
        if(i+1 <= k) // 진행된 방송 횟수가 k번째 이내일 경우
        {
            auto it = rankSet.begin();
            std::advance(it, i);
            answer.push_back(*it);
        }
        else
        {
            auto it = rankSet.begin();
            std::advance(it, k-1);
            answer.push_back(*it);
        }
    }
    
    return answer;
}
