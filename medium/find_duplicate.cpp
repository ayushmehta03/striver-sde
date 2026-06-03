// find dupicate element in constant space 

#include<iostream>
#include<vector>
using namespace std;

// using tortise and hare algo, slow and fast pointer approach will find the duplicate 

// time complexity-> O(N) best
// space -> O(1)



int findD(vector<int>&nums){

    // declare the slow and fast point at same position

    int slow=nums[0];
    int fast=nums[0];

    // move the slow pointer by one step and fast by two step until the values are same 

    do{
        slow=nums[slow];
        fast=nums[nums[fast]];

    }while(slow!=fast);


    //reset the fast, keep the slow as it is 

    fast=nums[0];

    // move both of them by one position once their v
    while(slow!=fast){

        slow=nums[slow];
        fast=nums[fast];
    }

    return slow;




}

int main(){

    int n;
    cin>>n;

    vector<int>nums(n);

    for(int i=0;i<n;i++)cin>>nums[i];

    cout<<"the duplicate element is: "<<findD(nums);

    return 0;
}