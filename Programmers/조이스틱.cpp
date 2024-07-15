#include <string>
#include <vector>

using namespace std;


int getAlphaIndex(char ch)
{
    auto frontAlpha = ch - 'A';
    auto backAlhpa = 26 - ch + 'A';

    return (frontAlpha < backAlhpa ? frontAlpha : backAlhpa);
}

pair<int, int> getLeftMoveInfo(string str, int index)
{
    int cnt = 0;
    int i = index;
    while(1)
    {
        if(i == 0) i = str.size()-1;
        else i--;
        
        cnt++;

        if(str[i] != 'A')
        {
            break;
        }
    }
    
    return make_pair(cnt, i);
}

pair<int, int> getRightMoveInfo(string str, int index)
{
    int cnt = 0;
    int i = index;
    while(1)
    {
        if(i == str.size()-1) i = 0;
        else i++;

        cnt++;

        if(str[i] != 'A')
        {
            break;
        }
    }
    
    return make_pair(cnt, i);
}

int solution(string name) {
    int answer = 0;
    if(name.find_first_not_of("A") == string::npos)
    {
        return answer;
    }

    int i = 0;
    while(1)
    {
        if(name[i] != 'A')
        {
            answer += getAlphaIndex(name[i]);
            name[i] = 'A';
        }
        
        if(i+1 < name.size() && name[i+1] != 'A')
        {
            i += 1;
            answer += 1;
            continue;
        }
       
         // A가 아닌 값이 존재하는지 확인
        if(name.find_first_not_of("A") == string::npos) break;
        
        auto leftMove = getLeftMoveInfo(name, i);
        auto rightMove = getRightMoveInfo(name, i);
        
        if(leftMove.first < rightMove.first)
        {
            i = leftMove.second;
            answer += leftMove.first;
        }
        else
        {
            i = rightMove.second;
            answer += rightMove.first;
        }
    }
    
    return answer;
}
