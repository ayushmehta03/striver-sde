#include<iostream>
#include<vector>
using namespace std;



// using moore voting algorithm

// tc=O(N) sc=O(1)

int majorityEl(vector<int>&nums){

    int n=nums.size();

    int cnt=0;

    int el;

    for(int i=0;i<n;i++){

        if(cnt==0){
            cnt=1;
            el=nums[i];
        }

        else if(el==nums[i])cnt++;

        else cnt--;
    }


    // veeify selected element majority by counting again
    int cnt1=0;

    for(int i=0;i<n;i++){
        if(el==nums[i])cnt1++;

        if(cnt1>(n/2)) return el;
    }

    return -1;

}

int main(){

    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i=0;i<n;i++) cin>>nums[i];


    int ans=majorityEl(nums);

    if(ans==-1) cout<<"no majority element found";

    else cout<<"the majority element is: "<<ans;

    




}