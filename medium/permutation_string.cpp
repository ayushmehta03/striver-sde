#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void comb(int idx,vector<int>&nums,vector<vector<int>>&ans){

    // base case
    if(idx==nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=idx;i<nums.size();i++){
        swap(nums[idx],nums[i]);
        comb(idx+1,nums,ans);
        swap(nums[idx],nums[i]);
    }



}


vector<vector<int>>perm(vector<int>&nums){

    vector<vector<int>>ans;

    comb(0,nums,ans);

    return ans;



}




//driver code

int main(){


    vector<int>nums={1,2,3};
    vector<vector<int>>ad=perm(nums);

    for(int i=0;i<ad.size();i++){
    cout<<endl;
    for(auto it:ad[i]){
        cout<<" "<<it;
    }

    }



}