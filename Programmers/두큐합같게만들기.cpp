#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    vector<int> answerVec;
    
    long long sum = accumulate(queue1.begin(), queue1.end(), 0);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    long long totalSum = sum+sum2;
    
    if(sum == sum2) return 0;
    if(totalSum%2 != 0) return -1;
    
    vector<int> vec(queue1);
    vec.insert(vec.end(), queue2.begin(), queue2.end());
    int size = vec.size();
    vec.insert(vec.end(), queue1.begin(), queue1.end());

    int endIndex = size/2-1;
    
    totalSum /= 2;
    
    for(int i=0; i<size; i++)
    {
        if(sum > totalSum)
        {
            long long temp = sum;
            int tempIndex = endIndex;
            int cnt = size/2;
            while(1)
            {
                temp -= vec[tempIndex];
                tempIndex--;
                cnt--;
                if(temp < totalSum) break;
                else if(temp == totalSum)
                {
                    int ans = 0;
                    if(i < size/2)
                    {
                        ans = i + (tempIndex+1-size/2);
                    }
                    else
                    {
                        ans = size/2 + (size/2-cnt);
                    }
                    answerVec.push_back(ans);
                    break;
                }
            }
        }
        else if(sum == totalSum)
        {
            int ans = i*2;
            answerVec.push_back(ans);
        }
        // else
        // {
        //     long long temp = sum;
        //     int tempIndex = endIndex;
        //     while(1)
        //     {
        //         tempIndex++;
        //         temp += vec[tempIndex];
        //         if(temp > totalSum) break;
        //         else if(temp == totalSum)
        //         {
        //             int ans = (i+1) + ((tempIndex+1) - size/2);
        //             answerVec.push_back(ans);
        //             break;
        //         }
        //     }
        // }
        
        sum -= vec[i];
        endIndex++;
        sum += vec[endIndex];
    }
    
    if(!answerVec.empty())
    {
        sort(answerVec.begin(), answerVec.end());
        answer = answerVec.front();
    }
    
    return answer;
}
