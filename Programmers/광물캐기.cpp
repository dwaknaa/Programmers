#include <string>
#include <vector>
#include <map>
#include <numeric>
using namespace std;

const int DIA = 25;
const int IRON = 5;
const int STONE = 1;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    // 조건에 따라 처리할 광물 개수를 계산
    int maxPickCnt = accumulate(picks.begin(), picks.end(), 0) * 5;
    int maxCnt = maxPickCnt > minerals.size() ? minerals.size() : maxPickCnt;
    
    // 5개의 광물 묶음 별로 가중치를 저장할 map
    multimap<int, vector<string>, greater<int>> weightInfo;
    
    int cnt = 0;
    vector<string> vec;
    int weight = 0;
    for(int i=0; i<maxCnt; i++)
    {
        cnt++;
        std::string mineral = minerals[i];
        
        if(mineral == "diamond") weight+= DIA;
        else if(mineral == "iron") weight+=IRON;
        else weight+=STONE;
        
        vec.push_back(mineral);
        
        // 5개씩 묶어서 가중치 정보 저장
        if(cnt==5)
        {
            weightInfo.insert(make_pair(weight, vec));
            cnt = 0;
            weight = 0;
            vec.clear();
        }
    }
    
    if(cnt > 0)
    {
        weightInfo.insert(make_pair(weight, vec));
    }
    
    // 가중치 정보가 높은 묶음부터
    for(auto m : weightInfo)
    {
        // 피로도가 적은 광물부터 사용 (이미 가중치 내림차순으로 정렬했으므로)
        vector<string> mineralVec = m.second;
        string pick = "";
        if(picks[0] > 0)
        {
            pick = "diamond";
            picks[0] -= 1;
        }
        else if(picks[1] > 0)
        {
            pick = "iron";
            picks[1] -= 1;
        }
        else
        {
            pick = "stone";
            picks[2] -= 1;
        }
        
        for(auto min : mineralVec)
        {
            if(pick == "diamond")
            {
                answer += 1;
            }
            else if(pick == "iron")
            {
                if(min == "diamond") answer += 5;
                else answer += 1;
            }
            else
            {
                if(min == "diamond") answer += 25;
                else if(min == "iron") answer += 5;
                else answer += 1;
            }
        }
    }

    return answer;
}
