#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i=0; i<s.length()-1; i++)
    {
        stack<char> st;
        bool right = true;
        for(int j=0; j<s.length(); j++)
        {
            if(s[j] == '[' || s[j] == '{' || s[j] == '(')
            {
                st.push(s[j]);
            }
            else if(s[j] == ']')
            {
                if(st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    right = false;
                    break;
                }
            }
            else if(s[j] == '}')
            {
                if(st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    right = false;
                    break;
                }
            }
            else if(s[j] == ')')
            {
                if(st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    right = false;
                    break;
                }
            }
        }
        
        if(right && st.empty()) answer++;
     
        string first = s.substr(0, 1);
        s.erase(s.begin());
        s += first;
    }
    
    return answer;
}
