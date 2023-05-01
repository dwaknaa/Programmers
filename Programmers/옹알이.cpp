#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> strVec = {"aya", "ye", "woo", "ma"};
    
    for(int i = 0; i < static_cast<int>(babbling.size()); i++)
    {
        string str = babbling[i];
        
        for(int j = 0; j < static_cast<int>(strVec.size()); j++)
        {
            int lastIndex = -2;
            while(1)
            {
                auto index = str.find(strVec[j]);
                if(index == string::npos) break;
                if(lastIndex+1 == index) break;
                lastIndex = index;
                str.replace(index, strVec[j].length(), " ");
            }
        }

        while(1)
        {
            auto index = str.find(" ");
            if(index == string::npos) break;
            else str.erase(index, 1);
        }
        
        if(str.length() == 0) answer++;
    }
    
    return answer;
}
