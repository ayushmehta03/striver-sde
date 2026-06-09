// missing and repeating number
#include<iostream>
#include<vector>
using namespace std;




vector<int>findMissingandRepeating(vector<int>&nums){


    int n=nums.size();

    vector<int>hash(n+1,0);


    for(int i=0;i<n;i++){
        hash[nums[i]]++;
    }


    int repeating = -1, missing = -1;
        
        // Find the repeating and missing number:
        for (int i = 1; i <= n; i++) {
            if (hash[i] == 2) {
                repeating = i;
            } else if (hash[i] == 0) {
                missing = i;
            }
            /* If both repeating and missing 
            are found, break out of loop*/
            if (repeating != -1 && missing != -1) {
                break;
            }
        }
        
        // Return {repeating, missing}
        return {repeating, missing};
}

int main(){

    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};



    vector<int>result=findMissingandRepeating(nums);

        cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";

    return 0;


}