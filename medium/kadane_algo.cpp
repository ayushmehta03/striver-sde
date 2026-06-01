#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;



int maxSubA(vector<int>&nums){

    int n=nums.size();

    int ans=INT_MIN;
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=nums[i];
        if(sum>ans)ans=sum;

        if(sum<0) sum=0;

    }

    return ans;

}
int main(){

    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];


    int ans=maxSubA(nums);

    cout<<"the max sum in the sub a will be: "<<ans;

}