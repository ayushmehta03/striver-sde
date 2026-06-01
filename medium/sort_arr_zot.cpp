//sort an array of zero one and two

// sort colors
#include<iostream>
#include<vector>
using namespace std;


void setColors(vector<int>&nums){

    int low=0,mid=0,high=nums.size()-1;

    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }

        else if(nums[mid]==1){
            mid++;
        }

        else{
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}

int main(){

    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    setColors(nums);

    cout<<"updated array: ";
    for(int i=0;i<n;i++){
     cout<<nums[i]<<" ";
        
    }


}
