#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


int bstProfit(vector<int>&nums){

    int n=nums.size();
    int maxP=INT_MIN;
    int low=nums[0];

    for(int i=1;i<n;i++){

    low=min(low,nums[i]);
    int profit=nums[i]-low;
    maxP=max(maxP,profit);
    }

    if(maxP<0)maxP=0;

    return maxP;

}


int main(){
      int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    cout<<"the max profit can be made is: "<<bstProfit(nums);

    return 0;


}