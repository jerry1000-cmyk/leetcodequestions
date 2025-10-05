#include <iostream>
#include <vector>
using namespace std;


bool searchMatrix(vector<vector<int> > &mat , int target) {
        int n = mat.size();
        int m = mat[0].size();
        //Binary Search on rows
        int startRow = 0;
        int endRow = n-1;
        
        while(startRow <= endRow){
            int mid = startRow + (endRow-startRow)/2;
            if(target<=mat[mid][m-1] && target >= mat[mid][0]){
                //Binary Search on Columns
                int startColumn = 0;
                int endColumn = m-1;
                
             while(startColumn<=endColumn)
             {
              int mid1 = startColumn + (endColumn - startColumn)/2;
              if(target == mat[mid][mid1]){
                return true;
              }
              else if(target < mat[mid][mid1]){
                endColumn = mid1-1;
              }
              else if(target > mat[mid][mid1]){
                startColumn = mid1+1;
              }
             }
             return false;
                
            }
            else if(target > mat[mid][m-1]){
               startRow = mid +1;
            }
            else if(target< mat[mid][0]){
                endRow = mid -1;
            }
        }
        return false;
    }


int main(){
  vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
  int target = 5;
  cout << searchMatrix(mat , target) << endl;
  system("pause");
}