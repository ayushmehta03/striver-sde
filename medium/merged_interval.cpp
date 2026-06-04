#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// overlapping sub intervals soln

// tc=O(N*logN) for sorting + O(N) traversing
//sc= O(N) extra list for returning the answer



vector<vector<int>>mergeIntervals(vector<vector<int>>&intervals){


    //sort the intervals on the starting time basis
    sort(intervals.begin(),intervals.end());

    //declare the list to return
    vector<vector<int>>merged;

    //traversing+condition check

    for(auto interval: intervals){

        // intially if the list is empty or no overlapping condition

        if(merged.empty() || merged.back()[1]<interval[0]){
            merged.push_back(interval);
        }

        // if overlapping take the maxi b/w both of them for the last entry
        else{
            merged.back()[1]=max(merged.back()[1],interval[1]);
        }
    }

    return merged;

}

int main(){

    vector<vector<int>>intervals={
        {1,3},{2,6},{8,10},{9,12},{16,20}
    };


    vector<vector<int>>ans=mergeIntervals(intervals);

    for (auto v : ans) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    return 0;



}