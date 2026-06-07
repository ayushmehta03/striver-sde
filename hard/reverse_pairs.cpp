#include<iostream>
#include<vector>
using namespace std;


// brute force approach 

// tc=O(n^2)
//sc O(1)


int revPairs(vector<int>&nums){

    int n=nums.size();


    int cnt=0;

    for(int i=0;i<n-1;i++){
     for(int j=i+1;j<n;j++){
        if(nums[i]>2*nums[j]) cnt++;
     }
    }

    return cnt;


}

int main(){


    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i=0;i<n;i++)cin>>nums[i];

    cout<<revPairs(nums);

    return 0;

}