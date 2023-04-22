#include <string>
#include <vector>
using namespace std;

using ULL = unsigned long long;
    
int solution(string t, string p) {
    int answer = 0;
    
    if(t.length() == p.length())
    {
        if(stoi(t) <= stoi(p)) return 1;
        else return 0;
    }
    
    for(int i = 0; i < t.length()-p.length()+1; i++)
    {
        string tempStr = t.substr(i, p.length());

        if(stoull(tempStr) <= stoull(p)) answer+= 1;
    }
    return answer;
}
