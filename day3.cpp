#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<vector<int>> printallsubsets(vector<int> &arr , vector<int> &ans , int i){
    vector<vector<int>> finalans;
    if(i == arr.size()){
        finalans.push_back(ans);
        return finalans;
    }

    ans.push_back(arr[i]);
    printallsubsets(arr , ans , i+1);

    ans.pop_back();
    printallsubsets(arr , ans, i+1);
}


int main() {
    vector<int> arr = {1,2,3};
    vector<int> ans;
    
    printallsubsets(arr,ans,0);
    system("pause");
    
    
    
    return 0;
}