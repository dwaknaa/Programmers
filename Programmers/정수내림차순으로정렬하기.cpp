#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> vec;
    string nStr = to_string(n);
    for(int i=0; i<nStr.length(); i++)
    {
        vec.push_back(stoi(nStr.substr(i, 1)));
    }
    
    sort(vec.begin(), vec.end(), greater<>());
    
    string temp;
    for(int i=0; i<vec.size(); i++)
    {
        temp += to_string(vec[i]);
    }
    
    answer = stoll(temp);
    
    return answer;
}
