#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr , int start , int end){
 int idx = start-1,piv = arr[end];
 
 for(int j = start;j<end;j++){
   if(arr[j]<piv){
    idx++;
    swap(arr[j],arr[idx]);
   }
 }
 idx++;
 swap(arr[end],arr[idx]);
 return idx;
}

void quicksort(vector<int> &arr , int start , int end){
    if(start<end){
       int pivIdx = partition(arr , start , end);
       quicksort(arr,start,pivIdx-1);
       quicksort(arr,pivIdx+1,end);
    }

}
int main(){
vector<int> arr = {5,2,6,4,1,3};
quicksort(arr,0,arr.size()-1);
for(int val: arr){
    cout<<val<<" ";
}

}