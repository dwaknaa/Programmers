#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> arr;
    int numChar[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int numCnt = 0;
    for(int i=0; i<=9; i++)
    {
        int xCnt = count(X.begin(), X.end(), numChar[i]);
        int yCnt = count(Y.begin(), Y.end(), numChar[i]);

        if(xCnt==0 || yCnt==0) continue;
        numCnt++;
        if(xCnt==yCnt)
        {
            for(int j=0; j<xCnt; j++)
            {
                arr.push_back(i);
            }
        }
        else if(xCnt>yCnt)
        {
            for(int j=0; j<yCnt; j++)
            {
                arr.push_back(i);
            }
        }
        else
        {
            for(int j=0; j<xCnt; j++)
            {
                arr.push_back(i);
            }
        }
    }
    
    if(arr.size()==0)
    {
        answer = "-1";
    }
    else
    {
        if(numCnt == 1)
        {
            answer = to_string(arr.front());
        }
        else
        {
            sort(arr.begin(), arr.end(), greater<>());

            for(int i=0; i<arr.size(); i++)
            {
                answer += to_string(arr[i]);
            }
        }
    }
    
    return answer;
}
