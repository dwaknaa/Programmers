#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // 반복되는 답 vec
    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> second = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> third = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    // 3명의 정답 개수를 0으로 초기화
    vector<int> answerCntVec(3, 0);
    
    for (int i=0; i<answers.size(); i++)
    {
        int temp = answers[i];
        
        // 각자의 답을 반복하기 위해 나머지 연산으로 인덱스 설정
        if(first[i%5]==temp) answerCntVec[0]++;
        if(second[i%8]==temp) answerCntVec[1]++;
        if(third[i%10]==temp) answerCntVec[2]++;
    }
    
    // 최다 정답 개수
    int maxCnt = *max_element(answerCntVec.begin(), answerCntVec.end());
    
    for(int i=0; i<3; i++)
    {
        if(answerCntVec[i]==maxCnt) answer.push_back(i+1);
    }
    
    return answer;
}
