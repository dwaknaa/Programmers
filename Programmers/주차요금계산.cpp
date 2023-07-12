#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int getParkingTime(string startTime, string endTime)
{
    int sum = 0;
    auto index = startTime.find(":");
    int startHour = stoi(startTime.substr(0, index));
    int startMin = stoi(startTime.substr(index+1));
    
    index = endTime.find(":");
    int endHour = stoi(endTime.substr(0, index));
    int endMin = stoi(endTime.substr(index+1));
    
    if(endMin >= startMin)
    {
        sum += (endHour-startHour)*60;
        sum += endMin-startMin;
    }
    else
    {
        sum += (endHour-1-startHour)*60;
        sum += (60-startMin)+endMin;
    }
    return sum;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> recordMap;
    map<string, int> tempMap;
    
    for(int i=0; i<records.size(); i++)
    {
        stringstream ss(records[i]);
        string time, carNum, type;
        
        ss >> time >> carNum >> type;
        
        auto ret = recordMap.insert({carNum, time});
        if(!ret.second)
        {
            int parkingTime = getParkingTime(recordMap[carNum], time);
            auto ret2 = tempMap.insert({carNum, parkingTime});
            if(!ret2.second) tempMap[carNum] += parkingTime;
            recordMap.erase(carNum);
        }
    }
    
    for(auto iter=recordMap.begin(); iter!= recordMap.end(); iter++)
    {
        int parkingTime = getParkingTime(iter->second, "23:59");
        auto ret2 = tempMap.insert({iter->first, parkingTime});
        if(!ret2.second) tempMap[iter->first] += parkingTime;
    }
    
    for(auto iter=tempMap.begin(); iter!=tempMap.end(); iter++)
    {
        if(iter->second > fees[0])
        {
            if(iter->second-fees[0] > fees[2])
            {
                if((iter->second-fees[0])%fees[2]==0)
                {
                   answer.push_back(fees[1]+((iter->second-fees[0])/fees[2])*fees[3]);
                }
                else
                {
                   answer.push_back(fees[1]+(((iter->second-fees[0])/fees[2])+1)*fees[3]);
                }
            }
            else
            {
                answer.push_back(fees[1]+fees[3]);
            }
        }
        else
        {
            answer.push_back(fees[1]);
        }
    }
    
    return answer;
}
