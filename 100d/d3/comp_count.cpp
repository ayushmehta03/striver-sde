#include<iostream>
#include<vector>
using namespace std;

pair<int,int>comp(vector<int>&nums,int t){

    int check=1;
    for(int i=0;i<nums.size();i++){
     if(nums[i]==t){
        return {i,check};
     }

     check++;

    }


    return {-1,-1};

    

}


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    int t;
    cin>>t;

    pair<int,int>ans=comp(arr,t);
    cout<<"found at index: "<<ans.first<<" no of checks: "<<ans.second;
}