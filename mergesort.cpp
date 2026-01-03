#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &arr , int start , int mid , int end){
    //o(n)
    vector<int> temp;
    int i = start;
    int j = mid + 1;
    //merge logic
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else if(arr[i]>arr[j]){
            temp.push_back(arr[j]);
            j++;
        }
        
    }
    //whichever elements are remaining in left or right side
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    //rewriting arr variables to match temp
    for(int idx = 0 ; idx<temp.size();idx++){
        arr[start+idx] = temp[idx];
    }


}

void mergeSort(vector<int> &arr , int start , int end){
    if(start<end){
     int mid = start + (end-start)/2;

     mergeSort(arr,start,mid);//left
     mergeSort(arr,mid+1,end);//right

     merge(arr,start,mid,end);
    }
}
int main(){

    vector<int> arr = {99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75};
    mergeSort(arr,0,arr.size()-1);

    for(int val : arr){
        cout<<val<<" ";
    }
    
}