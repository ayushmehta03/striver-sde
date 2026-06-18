#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



//tc =O(N)
//sc=O(1)


int soln(vector<int>&height){

    // We will use the two-pointer approach to solve this problem.

        // Store the required variables.
        int left = 0, right = height.size() - 1;

        // Keep track of leftMax and rightMax because
        // using these references only we can calculate the trapped water.
        int leftMax = 0, rightMax = 0;

        // Store the total water trapped.
        int ttlWater = 0;

        // Continue until left and right cross each other.
        while (left <= right) {

            // Compare the left and right heights.
            // If the left one is smaller, then we know
            // the water level depends on the left side.
            if (height[left] <= height[right]) {

                // If the current height is greater than or equal to leftMax,
                // water cannot be stored here.
                // So update leftMax.
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                }
                else {

                    // Water can only be stored in the gap.
                    // Amount of water = leftMax - current height.
                    ttlWater += leftMax - height[left];
                }

                // Move the left pointer forward.
                left++;
            }

            // Same logic applies for the right side.
            else {

                // If current height is greater than or equal to rightMax,
                // update rightMax.
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                }
                else {

                    // Water stored = rightMax - current height.
                    ttlWater += rightMax - height[right];
                }

                // Move the right pointer backward.
                right--;
            }
        }

        return ttlWater;

}


//driver code

int main(){

    vector<int>height={0,1,0,2,1,0,1,3,2,1,2,1};


    cout<<"amount of water that can be trapped: "<<soln(height);




}