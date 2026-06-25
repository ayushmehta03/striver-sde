#include<iostream>
#include<vector>
using namespace std;


void ad(int idx,vector<int>&arr,int target,vector<int>ds,vector<vector<int>>&ans){

        //base case
        if(idx==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        //pick the current element only if it is samller or equal to the taregt
        if(arr[idx]<=target){
         //add the element in the list
         ds.push_back(arr[idx]);

         //recurssive call stay at the idx and decrease the target
         ad(idx,arr,target-arr[idx],ds,ans);

         //back tarck remove the prev added element
         ds.pop_back();

        }


        //not pick skip the current element move idx
        ad(idx+1,arr,target,ds,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>a;
        ad(0,candidates,target,a,ans);
        return ans;
    }



//driver code 
int main(){
    vector<int>a={2,2,3,4};
    int t=8;
    vector<vector<int>>ans=combinationSum(a,t);
    for (auto comb : ans) {
        cout << "[";
        for (int i = 0; i < comb.size(); i++) {
            cout << comb[i];
            if (i != comb.size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;


}