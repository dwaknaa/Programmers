#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> getLeftCntVec(vector<int> topping)
{
    set<int> leftCntSet;
    vector<int> leftCntVec;
    
    for(int i=0; i<topping.size(); i++)
    {
        leftCntSet.insert(topping[i]);
        leftCntVec.push_back(leftCntSet.size());
    }
    
    return leftCntVec;
}

vector<int> getRightCntVec(vector<int> topping)
{
    set<int> rightCntSet;
    vector<int> rightCntVec;
    
    for(int i=topping.size()-1; i>=0; i--)
    {
        rightCntSet.insert(topping[i]);
        rightCntVec.push_back(rightCntSet.size());
    }
    
    reverse(rightCntVec.begin(), rightCntVec.end());
    
    return rightCntVec;
}

int solution(vector<int> topping) {
    int answer = 0;
    
    vector<int> leftVec = getLeftCntVec(topping);
    vector<int> rightVec = getRightCntVec(topping);
    
    for(int i=0; i<topping.size(); i++)
    {
        if(leftVec[i]==rightVec[i+1]) answer++;
    }
    
    return answer;
}
