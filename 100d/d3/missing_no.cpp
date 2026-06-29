#include<iostream>
#include<vector>
using namespace std;


int missingNo(vector<int>&nums){
    int n=nums.size()+1;

int expectedSum = (n * (n + 1)) / 2;
  int  actualSum=0;

  for(int i:nums){
    actualSum+=i;

  }

  return expectedSum-actualSum;


}

int main(){

    vector<int>nums={1,2,3,5};
    cout<<"missing no is: "<<missingNo(nums);

}