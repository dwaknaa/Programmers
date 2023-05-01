#include <string>
#include <vector>
#include <algorithm> // For vector find
#include <sstream>
using namespace std;
//1-2-3-1
int solution(vector<int> ingredient) {
    int answer = 0;
    std::stringstream ss;
    for (auto it = ingredient.begin(); it != ingredient.end(); it++)
    {
        ss << *it;
    }

    std::string str = ss.str();
    std::string findStr = "1231";
    int pos = 0;
    while(1)
    {
        size_t ret = str.find("1231", pos);
        if (ret == std::string::npos) break;
        str.erase(ret, 4);
        if (ret > 2)
            pos = ret - 3;
        answer++;
    }
    
    return answer;
}

