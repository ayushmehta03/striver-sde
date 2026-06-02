#include<iostream>
#include<vector>
using namespace std;




vector<int>generateRows(int row){

    long long ans=1;
    vector<int>ansRow;
    ansRow.push_back(ans);

    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/(col);
        ansRow.push_back(ans);
    }

    return ansRow;




}
int main(){

    int numRows;
    cout<<"Enter the no of rows to print the p tri: ";
    cin>>numRows;

    vector<vector<int>>ans;

    for(int i=1;i<=numRows;i++){
        ans.push_back(generateRows(i));
    }

    for(int i=0;i<ans.size();i++){
        cout<<endl;
        for(auto el:ans[i]){
            cout<<el<<" ";
        }
    }






}