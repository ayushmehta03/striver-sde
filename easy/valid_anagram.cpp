#include<iostream>
#include<unordered_map>
using namespace std;

//  two strings are considered to be an anagram when the char count is same between them 


bool ad(string &s,string &t){


    // anagrams cant be of diff size
    if(s.size()!=t.size()) return false;

    //declare an unordered map to store frequency of character
    unordered_map<char,int>freq;


    //store the frequency

    for(int i=0;i<s.size();i++){

        // add the char freq for string s
        freq[s[i]]++;

        //decrease for string t on the same character
        freq[t[i]]--;
    }

    // after performing the above ops if the count of char are same then map will store 0 for everyone 

    //check inside the map

    for(auto &it:freq){

        // if the count is not zero return false
        if(it.second!=0) return false;
    }

    return true;

}

int main(){

    string s="java";
    string t="vaaj";

    if(ad(s,t)) cout<<"yes given strs are valid anagram";
    else cout<<"given strs are not valid anagarm";

    return 0;


}