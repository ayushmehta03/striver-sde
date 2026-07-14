#include<iostream>
#include<vector>
using namespace std;


vector<int>find(vector<int>&nums){
    int n=nums.size();

    int min=INT_MAX;
    int max=INT_MIN;

    for(int i=0;i<n;i++){
        if(nums[i]>max)max=nums[i];
        if(nums[i]<min)min=nums[i];
    }


    return{min,max};
}


int main(){
    vector<int>nums={3,5,29,1,8};


    vector<int>ans=find(nums);

    cout<<"min element: "<<ans[0]<<endl;
    cout<<"max element: "<<ans[1]<<endl;

}