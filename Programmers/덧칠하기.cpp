#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 0;
    int temp = section[0];
    answer++;
    
    for(int i = 1; i < static_cast<int>(section.size()); i++)
    {
        if(temp + m - 1 >= section[i])
        {
            continue;
        }
        else
        {
            temp = section[i];
            answer++;
        }
    }
    
    return answer;
}
