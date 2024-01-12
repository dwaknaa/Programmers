#include <string>
#include <vector>
using namespace std;

// 최대 공약수를 구하는 함수
int gcb(int a, int b)
{
    if(b==0) return a;
    return gcb(b, a%b);
}

// arrayA의 최대 공약수를 구해서
// arrayA의 최대 공약수로 나눠지는 arrayB 원소가 있는지 확인
int getNum(vector<int> &arrayA, vector<int> &arrayB)
{
    int gcbNum = arrayA[0];
    for(int i=0; i<arrayA.size()-1; i++)
    {
        int num = arrayA[i+1];
        
        gcbNum = gcb(gcbNum, num);
    }
    
    if(gcbNum == 1) return 0;
    
    bool isDivided = false;
    for(int i=0; i<arrayB.size(); i++)
    {
        if(arrayB[i]%gcbNum == 0) return 0;
    }
    
    return gcbNum;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

    int tempA = getNum(arrayA, arrayB);
    int tempB = getNum(arrayB, arrayA);
    
    answer = tempA>tempB ? tempA : tempB;
    
    return answer;
}
