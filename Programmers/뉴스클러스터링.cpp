#include <string>
#include <vector>
#include <cctype> // for isalpha
#include <algorithm> // for transform
#include <math.h> // for trunc
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> str1Vec;
    vector<string> str2Vec;
    
    for(int i=0; i<str1.size()-1; i++)
    {
        if(isalpha(str1[i])!=0 && isalpha(str1[i+1])!=0)
        {
            string str = str1.substr(i, 2);
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            str1Vec.push_back(str);
        }
    }
    
    for(int i=0; i<str2.size()-1; i++)
    {
        if(isalpha(str2[i])!=0 && isalpha(str2[i+1])!=0)
        {
            string str = str2.substr(i, 2);
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            str2Vec.push_back(str);
        }
    }
    
    sort(str1Vec.begin(), str1Vec.end());
    sort(str2Vec.begin(), str2Vec.end());
    
    vector<string> unionVec;
    set_union(str1Vec.begin(), str1Vec.end(), str2Vec.begin(), str2Vec.end(),
             back_inserter(unionVec));
    
    vector<string> symDiffVec;
    set_symmetric_difference(str1Vec.begin(), str1Vec.end(), str2Vec.begin(), str2Vec.end(), back_inserter(symDiffVec));
    
    if(symDiffVec.size()==0 && unionVec.size()==0)
    {
        answer = 65536;
    }
    else if(unionVec.size()-symDiffVec.size()==0
            &&unionVec.size()>0)
    {
        answer = 0;
    }
    else
    {
        float temp = (float)(unionVec.size()-symDiffVec.size())/(float)(unionVec.size());
        answer = trunc(temp*65536);
    }
    
    return answer;
}
