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


// tabulation approach

int tabulationA(int m,int n){
    int dp[m][n];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){

            if(i==0&&j==0){
                dp[i][j]=1;
                continue;
            }

            else{
                int up=0;
                int left=0;

                if(i>0)up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];

                dp[i][j]=up+left;
            }
        }
    }
    return dp[m-1][n-1];

}

int main(){

    int m;
    cin>>m;

    int n;
    cin>>n;

    vector<vector<int>>dp(m,vector<int>(n,-1));


    cout<<"possible ways:"<<f(m-1,n-1,dp);
    cout<<endl;

    cout<<"tabulation way:"<<tabulationA(m,n);


    return 0;




}