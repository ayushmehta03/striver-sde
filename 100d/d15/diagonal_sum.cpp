#include<iostream>
#include<vector>
using namespace std;


int ad(vector<vector<int>>&mat){

    int n=mat.size();
    int m=mat[0].size();
    int a=0;
    for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
        if(i==j) a+=mat[i][j];
     }  

     return a;


    }

}

int main(){

    vector<vector<int>>mat={{1,2,3},{5,5,7},{8,9,5}};
    cout<<"the sum of diagonal: "<<ad(mat);

}