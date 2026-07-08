#include<iostream>
#include<vector>
using namespace std;



bool symmetricC(vector<vector<int>>mat){

    int n=mat.size();
    int m=mat[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]!=mat[j][i]) return false;
        }
    }

    return true;


}

int main(){

    vector<vector<int>>mat={{1,2,3},{2,4,5},{3,5,6}};

    if(symmetricC(mat))cout<<"yes";

    else cout<<"no";

    return 0;

}