#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, map<int, vector<int>, greater<int>>> songInfo;
    map<string, int> genresPlayingInfo;
    
    for(auto i=0; i<genres.size(); i++)
    {
        string genre = genres[i];
        int playingCnt = plays[i];
        
        if(genresPlayingInfo.find(genre)==genresPlayingInfo.end())
        {
            genresPlayingInfo[genre] = 0;
        }
        
        genresPlayingInfo[genre] += playingCnt;
        
        if(songInfo.find(genre)==songInfo.end())
        {
            map<int, vector<int>, greater<int>> m;
            vector<int> v;
            v.push_back(i);
            m[playingCnt] = v;
            songInfo[genre] = m;
        }
        else
        {
            songInfo[genre][playingCnt].push_back(i);
        }
    }
    
    map<int, string, greater<int>> playingGenresInfo;
    for(auto iter : genresPlayingInfo)
    {
        playingGenresInfo[iter.second] = iter.first;
    }
    
    for(auto iter : playingGenresInfo)
    {
        string genre = iter.second;
        int genreSongCnt = 0;
        
        auto sInfo = songInfo[genre];
        for(auto siter : sInfo)
        {
            vector<int> vec = siter.second;
            for(int i=0; i<vec.size(); i++)
            {
                answer.push_back(vec[i]);
                genreSongCnt++;
                if(genreSongCnt>=2) break;
            }
            if(genreSongCnt>=2) break;
        }
    }
    
    return answer;
}
