#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int, int> sPosition;
    // Find S
    for(int i=0; i<park.size(); i++)
    {
        for(int j=0; j<park[i].length(); j++)
        {
            if(park[i].substr(j,1) == "S")
            {
                sPosition.first = i;
                sPosition.second = j;
            }
        }
    }
    
    for(int i=0; i<routes.size(); i++)
    {
        string route = routes[i];
        auto index = route.find(" ");
        if(index != string::npos)
        {
            string direction = route.substr(0, index);
            int step = stoi(route.substr(index+1));
            if(direction == "N")
            {
                if(sPosition.first-step >= 0)
                {
                    bool check = false;
                    for(int j=sPosition.first; j>=sPosition.first-step; j--)
                    {
                        if(park[j].substr(sPosition.second, 1) == "X")
                        {
                            check = true;
                            break;
                        }
                    }

                    if(!check) sPosition.first -= step;
                }
            }
            else if(direction == "S")
            {
                if(sPosition.first+step < park.size())
                {
                    bool check = false;
                    for(int j=sPosition.first; j<=sPosition.first+step; j++)
                    {
                        if(park[j].substr(sPosition.second, 1) == "X")
                        {
                            check = true;
                            break;
                        }
                    }

                    if(!check) sPosition.first += step;
                }
            }
            else if(direction == "W")
            {
                if(sPosition.second-step >= 0)
                {
                    bool check = false;

                    for(int j=sPosition.second; j>=sPosition.second-step; j--)
                    {
                        if(park[sPosition.first].substr(j, 1) == "X")
                        {
                            check = true;
                            break;
                        }
                    }
                    
                    if(!check) sPosition.second -= step;
                }
            }
            else
            {
                if(sPosition.second+step < park.front().length())
                {
                    bool check = false;
                    for(int j=sPosition.second; j<=sPosition.second+step; j++)
                    {
                        if(park[sPosition.first].substr(j, 1) == "X")
                        {
                            check = true;
                            break;
                        }
                    }

                    if(!check) sPosition.second += step;
                }
            }
        }
    }
    
    answer.push_back(sPosition.first);
    answer.push_back(sPosition.second);
    
    return answer;
}
