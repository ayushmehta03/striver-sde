// set marix zero
#include<iostream>
#include<vector>
using namespace std;


// solution 1 

// tc =0(2*m*n)
//sc=O(m)+O(n)

void setZeros1(vector<vector<int>>&mat){
    int m=mat.size();
    int n=mat[0].size();


    vector<int>rows(m,0);
    vector<int>cols(n,0);


    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==0){
                rows[i]=1;
                cols[j]=1;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(rows[i]==1 || cols[j]==1){
                mat[i][j]=0;
            }
        }
    }

}

int main(){

   vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};

   setZeros1(matrix);


   for(int i=0;i<matrix.size();i++){
    cout<<endl;
    for(auto el:matrix[i]){
        cout<<el<<" ";
    }
   }










}