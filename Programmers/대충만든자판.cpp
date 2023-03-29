#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;

    for(int i = 0; i < static_cast<int>(targets.size()); i++)
    {
        vector<int> temp;
        std::string target = targets[i];
        for(int j = 0; j < target.length(); j++)
        {
            int min = 101;
            std::string str = target.substr(j, 1);
            
            for(int n = 0; n < static_cast<int>(keymap.size()); n++)
            {
                auto index = keymap[n].find(str);
                if(index == std::string::npos)
                {
                    continue;
                }
                
                if(min > (index+1)) min = index+1;
            }
            
            temp.push_back(min);
        }
        
        if(find(temp.begin(), temp.end(), 101) != temp.end())
        {
            answer.push_back(-1);
        }
        else
        {
            int sum = 0;
            for(int m = 0; m < static_cast<int>(temp.size()); m++)
            {
                sum += temp[m];
            }
            
            answer.push_back(sum);
        }
    }
    
    return answer;
}
