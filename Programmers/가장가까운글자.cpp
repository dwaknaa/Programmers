#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int arr[26]; // 알파벳의 개수가 26개 이므로 배열의 크기를 26으로 설정
    fill_n(arr, 27, -2); // 배열을 끝까지 초기화 하고싶으면 배열의 크기+1을 두번째 파라미터에 넣어줘야함
    
    for(int i = 0; i < s.length(); i++)
    {
        int temp = (int)s[i] - 97;
        if(arr[temp] == -2)
        {
            arr[temp] = i;
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i-arr[temp]);
            arr[temp] = i;
        }
    }
    
    return answer;
}
