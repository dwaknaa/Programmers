#include <string>
#include <vector>
#include <map>
#include <bitset>
using namespace std;


map<int, map<int, vector<int>, greater<int>>> getSortedDataByCol(vector<vector<int>> &data, int &col)
{
    map<int, map<int, vector<int>, greater<int>>> sortedData;
    for(int i=0; i<data.size(); i++)
    {
        auto vec = data[i];
        int colValue = vec[col-1];
        
        if(sortedData.find(colValue)!=sortedData.end())
        {
            sortedData[colValue][vec.front()] = vec;
        }
        else
        {
            map<int, vector<int>, greater<int>> tempMap;
            tempMap[vec.front()] = vec;
            
            sortedData[colValue] = tempMap;
        }
    }
    
    return sortedData;
}

int getModSum(vector<int> &vec, int index)
{
    int modSum = 0;
    for(int j=0; j<vec.size(); j++)
    {
        modSum += (vec[j]%index);
    }
    
    return modSum;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    auto sortedMap = getSortedDataByCol(data, col);
    
    int index = 1;
    vector<int> modVec;
    for(auto mapByCol : sortedMap)
    {
        auto mapByPri = mapByCol.second;
        for(auto m : mapByPri)
        {
            if(index >= row_begin && index <= row_end)
            {
                vector<int> vec = m.second;
                modVec.push_back(getModSum(vec, index));
            }
            index++;
            if(index > row_end) break;
        }
        if(index > row_end) break;
    }
    
    auto num = bitset<32>(modVec.front());
    for(int i=1; i<modVec.size(); i++)
    {
        num = bitset<32>(num ^ bitset<32>(modVec[i])); // bitwise XOR
    }
    
    bitset<32> binary_to_decimal(num.to_string());
    answer = static_cast<int>(binary_to_decimal.to_ulong());
    
    return answer;
}
