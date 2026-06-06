#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


vector<int>twoSum(vector<int>&nums,int target){

    unordered_map<int,int>mpp;

    for(int i=0;i<nums.size();i++){
        int diff=target-nums[i];

        if(mpp.count(diff)){
            return {mpp[diff],i};

        }

        mpp[nums[i]]=i;
    }

    return {-1,-1};



}

int main(){

    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i=0;i<n;i++)cin>>nums[i];

    int t;

    cin>>t;

    vector<int>ans=twoSum(nums,t);

    if(ans[0]==-1) cout<<"no pair possible";

    else{
        cout<<"pair1:"<<ans[0]<<",pair2:"<<ans[1];
    }

    return 0;


}