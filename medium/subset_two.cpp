#include<iostream>
#include<vector>
using namespace std;



void backtrack(int start,vector<int>&nums,vector<int>&curr,vector<vector<int>>&res){

        res.push_back(curr);

        for(int i=start;i<nums.size();i++){
            if(i>start &&nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            backtrack(i+1,nums,curr,res);
            curr.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<vector<int>>res;
       vector<int>curr;
       backtrack(0,nums,curr,res);
       return res;

    }


int main(){

    vector<int>nums={1,1,2};
    vector<vector<int>>ans=subsetsWithDup(nums);
    for (auto subset : ans) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i != subset.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;
    return 0;


}