#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
using namespace std;

 vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        set<vector<int>> ans;
        for(int i = 0; i<n ; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    vector<int> trip = {nums[i] ,nums[j],nums[k]};
                    ans.insert(trip);
                    j++;
                    k--;

                }
                if(sum < 0){
                    j++;

                }
                if(sum > 0){
                    k--;

                }

            }
        }
        return vector<vector<int>>(ans.begin(),ans.end());
        
    }


int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum(nums);
    
    for (auto &triplet : ans) {
        for (auto &x : triplet) cout << x << " ";
        cout << endl;
    }
    system("pause");
}



