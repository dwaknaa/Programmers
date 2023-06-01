#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    for(int i=0; i<cities.size(); i++)
    {
        std::string city = cities[i];
        int count = std::count_if(cache.begin(), cache.end(),
                            [&city](string elem) { return !strcasecmp(elem.c_str(), city.c_str()); });
        
        if(count > 0)
        {
            answer++;
            
            for(int j=0; j<cache.size(); j++)
            {
                if(!strcasecmp(cache[j].c_str(), city.c_str()))
                {
                    cache.erase(find(cache.begin(), cache.end(), cache[j]));
                    break;
                }
            }
            
            cache.push_back(cities[i]);
        }
        else
        {
            answer += 5;
            
            cache.push_back(cities[i]);
            
            if(cache.size() > cacheSize)
            {
                cache.erase(cache.begin());
            }
        }
    }
    
    return answer;
}
