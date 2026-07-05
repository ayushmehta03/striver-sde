#include<iostream>
#include<algorithm>
using namespace std;



void mirror(string &s){
    int l=0,r=s.size()-1;


    while(l<=r){
     swap(s[l],s[r]);
     l++;
     r--;

    }

}


int main(){

    string s;
    cin>>s;
    mirror(s);
    cout<<"mirror str is: "<<s;
}