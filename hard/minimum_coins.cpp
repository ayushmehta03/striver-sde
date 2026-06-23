#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// helper function memoization solution

int ad(vector<int>&coins,int amt,int idx,vector<vector<int>>&dp){


    // ase case when it reaches the last element we are starting in reverse order so 0 will be the last

    if(idx==0){

        // if the coin at 0th index divides amout completly it means we can take it


        // return the no of coins req eg. amt=8 coins[0]=2 so 8/2=4

        if(amt%coins[0]==0) return amt/coins[0];

        // no combination possible
        else return 1e9;
    }


    // if the subproblem has been visited before return it this avoids extra recurssive calls
    if(dp[idx][amt]!=-1) return dp[idx][amt];


    // two cases either take the coin or skip it


    // not take case -> no changes or case except the base case one just move the index
    int nTake=0+ad(coins,amt,idx-1,dp);

    // intially take value is infinty
    int take=1e9;

    // only consider when the amount is greater than or equal to the position we are standing at

    if(amt>=coins[idx]){

        // add one cause we have taken this one and decrease the amount take the max benefit from that index stick to it
        take=1+ad(coins,amt-coins[idx],idx,dp);
    }

    // take the minimu of take and ntake calls
    return dp[idx][amt]=min(nTake,take);

}

//driver code 

int main(){
    int n;
    cin>>n;

    vector<int>coins(n);

    cout<<"enter the types of coins: "<<endl;
    for(int i=0;i<n;i++)cin>>coins[i];



    int amount;

    cout<<"enter the amount: ";
    cin>>amount;

    //creating 2d dp arr to store the subproblems state

    vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));




    int ans=ad(coins,amount,n-1,dp);

    if(ans>=1e9){
        cout<<"no combination possible to sum upto amount";
    }
    else{
        cout<<"min coins required: "<<ans;
    }

    




}