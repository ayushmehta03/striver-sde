#include<iostream>
#include<vector>
using namespace std;

int main(){



    vector<vector<int>>A={{1,2,3},{4,5,6},{7,8,9}};

    vector<vector<int>>B={{9,8,7},{6,5,4},{3,2,1}};


    int n=A.size();
    int m=A[0].size();

    vector<vector<int>>result(n,vector<int>(m,0));


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            result[i][j]=A[i][j]+B[i][j];
        }
    }

    for(int i=0;i<n;i++){
        cout<<endl;
        for(auto it:result[i]){
            cout<<it<<" ";
        }
    }


    return 0;



}