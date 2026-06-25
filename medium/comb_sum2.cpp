#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void ad(int idx,vector<int>&arr,int target,vector<int>&ds,vector<vector<int>>&ans){
    // Base case: If the target becomes 0, we found a valid combination
    if(target==0){
        ans.push_back(ds); //add the comb to the result
        return;
    }

    // Loop through the elements starting from index 'ind'
    for(int i=idx;i<arr.size();i++){
          // Skip duplicates to avoid repeating combinations

        if(i>idx && arr[i]==arr[i-1])continue;

        // If the current element is greater than the remaining target, break the loop
        if(arr[i]>target) break;

        //include the current element
        ds.push_back(arr[i]);


    // Recur with the updated target and next index (i + 1 to avoid repetition)
        ad(i + 1,arr, target - arr[i],ds,ans);

        // Backtrack by removing the last added element
        ds.pop_back();
    }

}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>a;
        vector<vector<int>>ans;
        sort(candidates.begin(), candidates.end());
        ad(0,candidates,target,a,ans);
        return ans;
    }


   // driver code 
int main(){
    vector<int>a={10,1,2,7,6,1,5};
    int t=8;
    vector<vector<int>>ans=combinationSum2(a,t);
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