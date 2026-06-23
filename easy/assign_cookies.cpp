#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




int ad( vector<int> &student,  vector<int> &cookie ){

    //sort both the arr/vector

    sort(student.begin(),student.end());
    sort(cookie.begin(),cookie.end());



    //declare the index
    int idxS=0,idxC=0;
    //check until one of them becomes invalid

    while(idxS<student.size() &&idxC<cookie.size()){

        //if the cookie is valid to assign move to the next student
        if(cookie[idxC]>=student[idxS]){
            idxS++;
        }

        //move the cookie idx
        idxC++;
    }

    // the student idx will be the no of students 

    return idxS;


}

int main(){

     vector<int> student = {1, 2, 3};
    vector<int> cookie = {1, 1};


    cout<<"max no of student: "<<ad(student,cookie);


}