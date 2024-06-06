#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <climits>
using namespace std;

vector<vector<string>> keypad = {{"1", "2", "3"},
                                 {"4", "5", "6"},
                                 {"7", "8", "9"},
                                 {"*", "0", "#"}};

vector<int> leftVec = {1, 4, 7};
vector<int> rightVec = {3, 6, 9};

int dx[] = {0, 0, -1, +1};
int dy[] = {+1, -1, 0, 0};

string leftStart = "";
string rightStart = "";

int bfs(string start, string dest)
{
    map<string, bool> m;
    m = {{"1", false}, {"2", false}, {"3", false}, {"4", false},
         {"5", false}, {"6", false}, {"7", false}, {"8", false},
         {"9", false}, {"*", false}, {"0", false}, {"#", false}};
    
    queue<pair<string, int>> q;
    q.push({start, 0});
    m[start] = true;
    
    int min = INT_MAX;
    
    while(!q.empty())
    {
        string next = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(next == dest && min > cnt) min = cnt;
        
        for(int i=0; i<keypad.size(); i++)
        {
            for(int j=0; j<3; j++)
            {
                if(keypad[i][j]==next)
                {
                    for(int k=0; k<4; k++)
                    {
                        int nx = j+dx[k];
                        int ny = i+dy[k];
                        if(nx<0 || ny<0 || nx>=3 || ny>=4) continue;

                        if(!m[keypad[ny][nx]])
                        {
                            m[keypad[ny][nx]] = true;
                            q.push({keypad[ny][nx], cnt+1});
                        }
                    }
                }
            }
        }

    }
    
    return min;
}

std::string getHand(int dest, string mainHand)
{
    if(binary_search(leftVec.begin(), leftVec.end(), dest))
    {
        leftStart = to_string(dest);
        return "L";
    }
    if(binary_search(rightVec.begin(), rightVec.end(), dest))
    {
        rightStart = to_string(dest);
        return "R";
    }

    int leftCnt = bfs(leftStart, to_string(dest));
    int rightCnt = bfs(rightStart, to_string(dest));
    
    if(leftCnt < rightCnt)
    {
        leftStart = to_string(dest);
        return "L";
    }
    else if(leftCnt > rightCnt)
    {
        rightStart = to_string(dest);
        return "R";
    }
    else
    {
        if(mainHand=="L") leftStart = to_string(dest);
        else rightStart = to_string(dest);
        
        return mainHand;
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    string mainHand = "";
    if(hand=="left") mainHand = "L";
    if(hand=="right") mainHand = "R";
        
    leftStart = "*";
    rightStart = "#";
    
    for(int i=0; i<numbers.size(); i++)
    {
        answer += getHand(numbers[i], mainHand);
    }
    
    return answer;
}
