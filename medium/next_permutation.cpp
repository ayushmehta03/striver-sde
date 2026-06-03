#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// function to find enxt permutation using stl inbuilt feature

vector<int>NextP(vector<int>&nums){

    vector<vector<int>>all;

    sort(nums.begin(),nums.end());
    do{
        all.push_back(nums);
    }while(next_permutation(nums.begin(),nums.end()));


    // traverse the list to find current permutation


    for(int i=0;i<all.size();i++){

        if(all[i]==nums){
            if(i==all.size()-1) return all[0];
            return all[i+1];
        }
    }

    return nums;
}


// using algorithm

void findNextP(vector<int>&nums){
    int idx=-1;

    int n=nums.size();

 //1. Find the first decreasing element from end

    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            idx=i;
            break;
        }
    }

    // if no such point found it means the given input is the last permutation return the first one by reversing it
    if(idx==-1){
        reverse(nums.begin(),nums.end());
        return;
    }

    //2. replace the idx element with the greater one will eventually help in getting the next permutation

    for(int i=n-1;i>idx;i--){
        if(nums[i]>nums[idx]){
            swap(nums[i],nums[idx]);
            break;
        }
    }

    // reverse the part after idx to get the minimum after changes made

    reverse(nums.begin()+idx+1,nums.end());




}

int main(){
    int n;

    cin>>n;

    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

       findNextP(nums);
    for(int num:nums) cout<<num<<" ";

    return 0;
    
}