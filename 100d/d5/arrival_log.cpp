#include<iostream>
#include<vector>
using namespace std;



vector<int>arrivalS(int n,vector<int>&a,int m,vector<int>&b){

    int i=0,j=0;
    int m=i+j-1;
    vector<int>ans;

    while(i<n&&j<m){
        if(a[i]<b[j]){
            ans.push_back(a[i]);
            i++;
        }

        else{
            ans.push_back(b[j]);
            j++;
        }
    }

    while(i<n){
        ans.push_back(a[i]);
        i++;
    }


    while(j<m){
        ans.push_back(b[j]);
        j++;
    }
    

    return ans;
}

int main(){


    int n=5;
    vector<int>a={10,20,30,50,70};
    

    int m=4;

    vector<int>b={15,25,40,60};

    vector<int>ad=arrivalS(n,a,m,b);


    for(auto it:ad){
        cout<<" "<<it;
    }


}