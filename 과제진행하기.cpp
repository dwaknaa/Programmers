#include <string>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

string getEndTimeStr(string start, int playtime)
{
    int hour = stoi(start.substr(0, 2));
    int min = stoi(start.substr(3, 2));
    
    if(playtime+min >= 60)
    {
        hour = hour+1;
        min = min+playtime-60;
        if(min == 0)
        {
            return to_string(hour) + ":00";
        }
    }
    else
    {
        min += playtime;
    }
    
    if(hour == 0) return "00:" + to_string(min);
    return to_string(hour) + ":" + to_string(min);
}

int getEndtime(string start, int playtime)
{
    int hour = stoi(start.substr(0, 2));
    int min = stoi(start.substr(3, 2));
    
    if(playtime+min >= 60)
    {
        hour = hour+1;
        min = min+playtime-60;
        if(min == 0)
        {
            return stoi(to_string(hour) + "00");
        }
    }
    else
    {
        min += playtime;
    }
    
    return stoi(to_string(hour) + to_string(min));
}

int getTheRestTime(string time1, string time2)
{
    int hour1 = stoi(time1.substr(0, 2));
    int hour2 = stoi(time2.substr(0, 2));
    
    int min1 = stoi(time1.substr(3, 2));
    int min2 = stoi(time2.substr(3, 2));
    
    if(min2 >= min1)
    {
        return (min2-min1) + (hour2-hour1)*60;
    }
    else
    {
        return (60+min2-min1) + (hour2-1-hour1)*60;
    }
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<pair<string, int>> unfinished;
    map<int, tuple<string, string, int>> plansMap;
    
    for(auto iter=plans.begin(); iter!=plans.end(); iter++)
    {
        string subject = iter->at(0);
        string start = iter->at(1);
        int startInt = stoi(start.substr(0, 2) + start.substr(3, 2));
        int playtime = stoi(iter->at(2));
        
        plansMap.insert({startInt, make_tuple(subject, start, playtime)});
    }
    
    for(auto iter=plansMap.begin(); iter!=plansMap.end(); iter++)
    {
        tuple<string, string, int> planInfo = iter->second;
        
        int endTime = getEndtime(get<1>(planInfo), get<2>(planInfo));
        if(next(iter, 1) == plansMap.end())
        {
            answer.push_back(get<0>(planInfo));
            break;
        }
        int nextPlanStartTime = next(iter, 1)->first;

        if(endTime == nextPlanStartTime)
        {
            answer.push_back(get<0>(planInfo));
        }
        else if(endTime > nextPlanStartTime)
        {
            unfinished.push_back(make_pair(get<0>(planInfo),
   getTheRestTime(get<1>(next(iter, 1)->second), getEndTimeStr(get<1>(planInfo) ,get<2>(planInfo)))));
        }
        else
        {
            answer.push_back(get<0>(planInfo));
            if(unfinished.empty()) continue;
            int theRestTime = getTheRestTime(get<1>(planInfo), get<1>(next(iter, 1)->second));
            while(!unfinished.empty())
            {
                if(unfinished.back().second < theRestTime)
                {
                    answer.push_back(unfinished.back().first);
                    theRestTime -= unfinished.back().second;
                    unfinished.pop_back();
                }
                else if(unfinished.back().second == theRestTime)
                {
                    answer.push_back(unfinished.back().first);
                    unfinished.pop_back();
                    break;
                }
                else
                {
                    unfinished.back().second -= theRestTime;
                    break;
                }
            }
        }
    }
    
    while(!unfinished.empty())
    {
        answer.push_back(unfinished.back().first);
        unfinished.pop_back();
    }
    
    return answer;
}
