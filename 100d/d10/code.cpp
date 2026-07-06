#include<iostream>
using namespace std;

bool ad(string s){

    int n=s.size()-1;
    int i=0;
    int j=n;

    while(i<=j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }

    return true;
    

}


int main(){
    string s;
    cin>>s;

    if(ad(s)) cout<<"yes";
    else cout<<"no";

    return 0;

}