#include<iostream>
#include<vector>
using namespace std;




// memoization approach
int f(int i, int j, vector<vector<int>>&dp){


    //recahed destination
    if(i==0&&j==0) return 1;

    //no movement possible
    if(i<0 ||j<0) return 0;

    //already visited avoids extra recurssion 

    if(dp[i][j]!=-1) return dp[i][j];


    int up=f(i-1,j,dp);

    int left=f(i,j-1,dp);


    return dp[i][j]=up+left;

}

int main(){

    int m;
    cin>>m;

    int n;
    cin>>n;

    vector<vector<int>>dp(m,vector<int>(n,-1));


    cout<<"possible ways:"<<f(m-1,n-1,dp);


    return 0;




}