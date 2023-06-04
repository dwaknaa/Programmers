#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int category = 0;
    int size = nums.size();
    
    while(1)
    {
        int num = nums.back();
        category++;
        nums.erase(remove(nums.begin(), nums.end(), num), nums.end());
        if(nums.size() == 0) break;
    }
    
    answer = size/2 > category ? category : size/2;
    
    return answer;
}
