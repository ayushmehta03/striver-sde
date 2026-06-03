//rotate 3x3 matrix by 90*


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void rotate(vector<vector<int>>&matrix){


    // transpose the matrix first 
    // interchanging the rows and cols

    int n=matrix.size();

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    //reverse the rows 
    for(int i=0;i<n;i++){
         reverse(matrix[i].begin(),matrix[i].end());
    }
}


int main(){

    vector<vector<int>>matrix={{1,2,3},{4,5,6},{7,8,9}};

    rotate(matrix);


    for(int i=0;i<matrix.size();i++){
        cout<<endl;
        for(auto it:matrix[i]){
            cout<<it<<" ";
        }
    }

}