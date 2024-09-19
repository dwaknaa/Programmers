#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    // arr의 첫 원소 처리를 위해 beforeNum을 arr 원소의 크기에서 벗어나는 수로 설정
    int beforeNum = -1;
    for(auto iter:arr)
    {
        // 연속적으로 나타나는 숫자들은 하나 빼고 모두 제거해야 하므로
        // 이전 숫자와 동일한지 비교
        if(iter != beforeNum)
        {
            answer.push_back(iter);
            beforeNum = iter;
        }
    }

    return answer;
}
