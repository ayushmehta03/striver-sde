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

int main(){
    int n;

    cin>>n;

    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];


    vector<int>ans=NextP(nums);
    for(int num:ans) cout<<num<<" ";

    return 0;
    
}