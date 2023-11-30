#include<algorithm>
#include<vector>
using namespace std;

int getVectorMulti(vector<int>& A, vector<int>& B)
{
    if(A.size() != B.size()) return 0;
    
    int sum = 0;
    for(int i=0; i<A.size(); i++)
    {
        sum += A.at(i) * B.at(i);
    }
    
    return sum;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());

    answer = getVectorMulti(A, B);
    
    return answer;
}
