#include <string>
#include <vector>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int arr1ColSize = arr1.size();
    int arr2RowSize = arr2[0].size();
    
    for(int i=0; i<arr1ColSize; i++)
    {
        vector<int> row = arr1[i];
        vector<int> answerRow;
        
        for(int j=0; j<arr2RowSize; j++)
        {
            int sum=0;
            for(int k=0; k<row.size(); k++)
            {
                sum += row[k]*arr2[k][j];
            }
            
            answerRow.push_back(sum);
        }
        
        answer.push_back(answerRow);
    }
    
    return answer;
}
