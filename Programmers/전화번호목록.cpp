#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=1; i<phone_book.size()-1; i++)
    {
        string phoneNumber = phone_book[i];
        if(phoneNumber.size() > phone_book[i-1].size())
        {
            if(phoneNumber.find(phone_book[i-1]) == 0)
            {
                answer = false;
                break;
            }
        }
        else
        {
            if(phone_book[i-1].find(phoneNumber) == 0)
            {
                answer = false;
                break;
            }
        }
        
        if(phoneNumber.size() > phone_book[i+1].size())
        {
            if(phoneNumber.find(phone_book[i+1]) == 0)
            {
                answer = false;
                break;
            }
        }
        else
        {
            if(phone_book[i+1].find(phoneNumber) == 0)
            {
                answer = false;
                break;
            }
        }
    }

    return answer;
}
