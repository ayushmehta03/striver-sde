#include<iostream>
#include<vector>
#include<unordered_map>
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


//optimal solution

// using hashmap tc=O(N) sc=O(N)


int cntSubA(vector<int>&A,int k){

 // Store frequency of prefix XORs
        unordered_map<int, int> freq;
        // Initialize with prefix XOR 0
        freq[0] = 1;

        // Current prefix XOR
        int prefixXor = 0;
        // Answer count
        int count = 0;

        // Traverse array
        for (int num : A) {
            // Update prefix XOR
            prefixXor ^= num;

            // Compute required XOR
            int target = prefixXor ^ k;

            // If target exists in map, add its frequency
            if (freq.find(target) != freq.end()) {
                count += freq[target];
            }

            // Store current prefix XOR in map
            freq[prefixXor]++;
        }
        return count;
    
}

int main(){

vector<int>nums={4, 2, 2, 6, 4};

int B=6;

cout<<"no of subarrays: "<<cntSubA(nums,B);




}