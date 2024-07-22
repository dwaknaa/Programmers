#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    // 각 인물별 선물을 준 횟수 map<준 사람, 준 횟수>
    map<string, int> giveCnt;
    // 각 인물별 선물을 받은 횟수 map<받은 사람, 받은 횟수>
    map<string, int> recvCnt;
    // 각 인물별 특정인에게 선물을 준 횟수 map<준 사람, map<누구에게, 몇번>>
    map<string, map<string, int>> giftInfo;
    
    // 기본값 생성
    for(int i=0; i<friends.size(); i++)
    {
        string friendName = friends[i];
        giveCnt[friendName] = 0;
        recvCnt[friendName] = 0;
        
        for(int j=0; j<friends.size(); j++)
        {
            if(i==j) continue;
            map<string, int> m;
            m[friends[j]] = 0;
            giftInfo[friendName] = m;
        }
    }
    
    // gift 정보 설정
    for(int i=0; i<gifts.size(); i++)
    {
        auto index = gifts[i].find(" ");
        string giver = gifts[i].substr(0, index);
        string taker = gifts[i].substr(index+1);
        
        giveCnt[giver] += 1;
        recvCnt[taker] += 1;
        
        giftInfo[giver][taker] += 1;
    }
    
    int max = 0;
    for(auto iter=giftInfo.begin(); iter!=giftInfo.end(); iter++)
    {
        int giftCnt = 0;
        string aInfo = iter->first;
        for(auto it = iter->second.begin(); it!=iter->second.end(); it++)
        {
            string bInfo = it->first;
            
            if(giftInfo[aInfo][bInfo] > giftInfo[bInfo][aInfo])
            {
                giftCnt++;
            }
            else if(giftInfo[aInfo][bInfo] < giftInfo[bInfo][aInfo])
            {
                
            }
            else
            {
                int aNum = giveCnt[aInfo] - recvCnt[aInfo];
                int bNum = giveCnt[bInfo] - recvCnt[bInfo];
                
                if(aNum > bNum) giftCnt++;
            }
        }
        
        if(giftCnt > max) max = giftCnt;
    }
    
    answer = max;
    
    return answer;
}
