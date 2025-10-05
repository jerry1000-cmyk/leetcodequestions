#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int piv = -1;
      for( int i = n-2; i>=0 ; i--){
        if(nums[i] < nums[i+1]){
            piv = i;
            break;

        }
      }
      if(piv == -1){
        reverse(nums.begin() ,nums.end());
        return;
      }
      for (int j = n - 1; j > piv; j--) {
        if (nums[j] > nums[piv]) {
            swap(nums[j], nums[piv]);
            break;
        }
    }
      int i = piv+1;
      int j = n-1;

      while( i != j && i<j){
        swap(nums[i] , nums[j]);
        i++;
        j--;
      }

    }

int main(){
    vector<int> nums = {1,2,3};
    nextPermutation(nums);
    for(int i = 0; i<nums.size();i++){
        cout<<nums[i]<<endl;
    }
    system("pause");
    return 0;
}