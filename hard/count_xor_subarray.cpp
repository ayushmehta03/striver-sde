#include<iostream>
#include<vector>
using namespace std;



//brute force 

//tc=O(n^2) //sc=O(1)
int subACnt(vector<int>&nums,int B){

int count = 0;
        // Traverse all starting points
        for (int i = 0; i < nums.size(); i++) {
            // Maintain xor of current subarray
            int xorVal = 0;
            // Extend subarray till end
            for (int j = i; j < nums.size(); j++) {
                // Update xor
                xorVal ^= nums[j];
                // If xor equals B, increment count
                if (xorVal == B) {
                    count++;
                }
            }
        }
        return count;    


}


int main(){

vector<int>nums={4, 2, 2, 6, 4};

int B=6;

cout<<"no of subarrays: "<<subACnt(nums,B);




}