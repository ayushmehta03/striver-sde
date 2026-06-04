// merge two sorted array with constant space 

#include<iostream>
#include<vector>
using namespace std;



void mergeSortedArr(vector<int>&nums1,int m, vector<int>&nums2,int n){


    // 3 pointers approach

    //last of valid element in nums1
    int i=m-1;

    //last of nums2
    int j=n-1;

      // k is the last index of nums1 (including 0 placeholders)
    int k=m+n-1;

    // Fill nums1 from the end by comparing nums1[i] and nums2[j]

    while(i>=0&&j>=0){

    if(nums1[i]>nums2[j]){
        nums1[k--]=nums1[i--];
    }

    else{
        nums1[k--]=nums2[j--];
    }

    }

    // If nums2 has remaining elements, copy them
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }

        // No need to copy remaining nums1 elements, as they are already in place


}

int main(){

    vector<int>nums1={1,2,3,0,0,0};
    vector<int>nums2={2,5,6};

    mergeSortedArr(nums1,3,nums2,3);

    for(auto it: nums1) cout<<it<<" ";



}

