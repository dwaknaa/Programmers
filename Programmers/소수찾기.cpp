#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if(n<=1) return false;
    
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            return false;
        }
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    set<string> nums;
    set<int> answers;
    int n = numbers.size();
    string sub;
    do {
        for (int i = 1; i <= n; i++)
        {
            sub = numbers.substr(0, i);
            nums.insert(sub);
            
            int num = stoi(sub);
            if(answers.find(num)==answers.end() && isPrime(num))
            {
                answers.insert(num);
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    answer = answers.size();
    
    return answer;
}
