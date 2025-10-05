#include <iostream>
#include <vector>
using namespace std;


vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        int stRow = 0;
        int stCol = 0;
        int enRow = n-1;
        int enCol = m-1;
        while(stRow <= enRow && stCol <= enCol){
          for(int i = stCol ; i <= enCol ; i++ ){
            ans.push_back(mat[stRow][i]);
          }
          stRow++;
          for(int i = stRow ; i <= enRow ; i++ ){
            ans.push_back(mat[i][enCol]);
          }
          enCol--;

          if (stRow <= enRow) {
            for (int i = enCol; i >= stCol; i--)
                ans.push_back(mat[enRow][i]);
            enRow--;
        }
        
          if (stCol <= enCol) {
            for (int i = enRow; i >= stRow; i--)
                ans.push_back(mat[i][stCol]);
            stCol++;
        }


        }
        
        return ans;  
    }

int main(){
    vector<vector<int>> numbers = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};
    vector<int> output = spiralOrder(numbers);
    for(int num : output){
        cout<<num<<endl;
    }
    system("pause");
}