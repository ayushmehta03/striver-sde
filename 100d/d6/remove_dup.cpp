#include<iostream>
#include<vector>
using namespace std;



int main(){
    vector<int>a={1,1,2,2,3,3};

    int j=0;

    for(int i=01;i<a.size();i++){
        if(a[i]!=a[j]){
            j++;
            a[j]=a[i];
        }
    }

    for(int i=0;i<=j;i++)cout<<" "<<a[i];

    return 0;


}