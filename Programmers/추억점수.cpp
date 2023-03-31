#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    for(int i = 0; i < static_cast<int>(photo.size()); i++)
    {
        int sum = 0;

        for(int j = 0; j < static_cast<int>(photo[i].size()); j++)
        {
            auto it = std::find(name.begin(), name.end(), photo[i][j]);
            if(it != name.end())
            {
                sum += yearning[std::distance(name.begin(), it)];
            }
        }
        
        answer.push_back(sum);
    }
    
    return answer;
}
