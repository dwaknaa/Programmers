#include <string>
#include <vector>
using namespace std;

int solution(int x, int y, int n) {
    int answer = 0;
    vector<int> vec;
    vec.push_back(y);
    while(1)
    {
        vector<int> temp;
        for(auto iter=vec.begin(); iter!=vec.end(); iter++)
        {
            if(*iter==x)
            {
                return answer;
            }
            
            if(*iter-n >= x) temp.push_back(*iter-n);
            if(*iter/2 >= x && *iter%2==0) temp.push_back(*iter/2);
            if(*iter/3 >= x && *iter%3==0) temp.push_back(*iter/3);
        }
        
        if(temp.empty()) return -1;

        answer++;
        vec.clear();
        vec.assign(temp.begin(), temp.end());
    }
    
    return answer;
}
