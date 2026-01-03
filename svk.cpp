#include <bits/stdc++.h>
// void yesorno(vector<vector<int>> &test){


// }
int main(){
 int n;
 cin>>n;

 vector<int> length;
 vector<vector<int>> testcases;
 
 int a;
 for(int i = 0 ; i<n ; i++){
    cin>>length[i];
    for(int j = 0 ; j<i ; j++){
        cin>>testcases[i][j];
    }
 }
//   yesorno(testcases);
    return 0;
}