#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int>>Solution(vector<int>&nums,int t ){

    int n=nums.size();

    sort(nums.begin(),nums.end());

    vector<vector<int>>ans;


    for(int i=0;i<n;i++){

    if(i>0&&nums[i]==nums[i-1])continue;


    for(int j=i+1;j<n;j++){
        if(j>i+1&&nums[j]==nums[j-1])continue;

        int left=j+1;
        int right=n-1;

        while(left<right){
        int sum=nums[i]+nums[j]+nums[left]+nums[right];
        if(sum==t){
        left++;
        right--;
  ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                left++;
                right--;      
                
                
    while(left<right &&nums[left]==nums[left-1])left++;
                 while (left < right && nums[right] == nums[right +1])
                            right--;


        }


        else if(sum<t)left++;
            else if(t<sum)right--;
        }
    }
    }

    return ans;


}


int main(){

    vector<int>nums{1,0,-1,0,-2,2};

    int t=0;

    vector<vector<int>>ans=Solution(nums,t);
    
    
    if(ans.size()==0) cout<<"no pair found.";
    
    else{
        for(int i=0;i<ans.size();i++){
          cout<<" ";
          for(int num:ans[i]){
              cout<<num<<" ";
          }
        }
    }
    
    return 0;

}


