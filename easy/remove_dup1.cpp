#include<iostream>
#include<vector>
using namespace std;



int dups(vector<int>&nums){

    int i=0;

    int n=nums.size();


    for(int j=1;j<n;j++){
        if(nums[i]!=nums[j]){
            i++;
            nums[i]=nums[j];
        }
    }

    return i+1;



}

int main(){

    vector<int>a={0,0,1,1,2,3,3,3,4,4};

    cout<<"unique ele: "<<dups(a);

}