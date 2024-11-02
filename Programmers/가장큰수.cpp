#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>
using namespace std;

bool cmp(string a, string b)
{
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    
    vector<string> numStr;
    
    transform(numbers.begin(), numbers.end(), back_inserter(numStr)
              , [](auto number)->string {return to_string(number);});
    
    sort(numStr.begin(), numStr.end(), cmp);
    
    // 원소가 모두 0인 경우
    if (numStr.front() == "0") return "0";

    ostringstream oss;
    std::copy(numStr.begin(), numStr.end(), std::ostream_iterator<string>(oss));
    
    string answer = oss.str();
    
    return answer;
}
