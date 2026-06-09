#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;



//appraoch 1 using hahmap to store sum ad indices


int longestSubA(vector<int>&nums,int k){

    int n=nums.size();

    unordered_map<int,int>mpp;

    int sum=0;

    int maxLen=0;

    for(int i=0;i<n;i++){
     sum+=nums[i];

     if(sum==k){
        maxLen=max(maxLen,i+1);
     }

     int rem=sum-k;

     if(mpp.find(rem)!=mpp.end()){
        int len=i-mpp[rem];
        maxLen=max(maxLen,len);
     }


     if(mpp.find(sum)==mpp.end()){
        mpp[sum]=i;
     }

    }

    return maxLen;

}

//approach 2 

//works only for positive numbers


int longestLength(vector<int>&nums,int k){

    int n=nums.size();


    int left=0,right=0;

    int sum=0,maxLen=0;

    while(right<n){

    while(left<=right &&sum>k){
        sum-=nums[left];
        left++;
    }

    if(sum==k){
        maxLen=max(maxLen,right-left+1);

    }


    right++;
    if(right<n) sum+=nums[right];

    }

    return maxLen;
}



int main(){


    vector<int>nums={1,2,3,1,1,1,1,4,2,3};

    int k=3;


    cout<<"the length of longest suba with sum k is: "<<longestSubA(nums,k);

    return 0;



}