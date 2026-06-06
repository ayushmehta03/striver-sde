#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// return two element from the vector whose occurance is  greater than n/3 times


// there can be most two elements hoding this condition 



vector<int>majorityElement(vector<int>&nums){

    int n=nums.size();

    int cnt1=0,cnt2=0;

    int el1=INT_MIN,el2=INT_MIN;

    for(int i=0;i<n;i++){

        if(cnt1==0 &&el2!=nums[i]){
            cnt1=1;
            el1=nums[i];
        }

        else if(cnt2==0 && el1!=nums[i]){
            cnt2=1;
            el2=nums[i];
        }

        else if(el1==nums[i])cnt1++;

        else if(el2==nums[i])cnt2++;

        else{
            cnt1--;
            cnt2--;
        }
    }

    cnt1=0,cnt2=0;

    for(int i=0;i<n;i++){
        if(el1==nums[i])cnt1++;
        if(el2==nums[i])cnt2++;
    }   

    vector<int>res;

    if(cnt1>n/3) res.push_back(el1);

    if(cnt2>n/3 &&el2!=el1)res.push_back(el2);

    return res;

}

int main(){

    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i=0;i<n;i++)cin>>nums[i];

    vector<int>ans=majorityElement(nums);


    cout<<"first el:"<<ans[0]<<",second el:"<<ans[1];

    return 0;

}