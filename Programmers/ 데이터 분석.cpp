#include <string>
#include <vector>
#include <map>
using namespace std;

int getIndex(string ext)
{
    if(ext=="code")
    {
        return 0;
    }
    else if(ext=="date")
    {
        return 1;
    }
    else if(ext=="maximum")
    {
        return 2;
    }
    else if(ext=="remain")
    {
        return 3;
    }
    
    return -1;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<int, vector<int>> sortedData;
    
    int extIndex = getIndex(ext);
    int sortIndex = getIndex(sort_by);
    
    if(extIndex < 0 || sortIndex < 0) return answer;
    
    for(auto iter : data)
    {
        int iterExt = iter[extIndex];
        if(iterExt < val_ext)
        {
            int iterSort = iter[sortIndex];
            sortedData[iterSort] = iter;
        }
    }
    
    for(auto m : sortedData)
    {
        answer.push_back(m.second);
    }
    
    return answer;
}
