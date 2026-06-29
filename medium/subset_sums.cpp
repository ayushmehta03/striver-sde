#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



// this func will calculate the subset sums

void findSum(int idx,vector<int>&arr,int currS,vector<int>&sums) {

	// base case
	if(idx==arr.size()) {
		sums.push_back(currS);
		return;
	}


	// either include or exclude the curr element to get in all the possible subsets

	findSum(idx+1,arr,currS+arr[idx],sums);

	findSum(idx+1,arr,currS,sums);


}



vector<int>subsetSum(vector<int>&arr) {

	vector<int>sums;

	findSum(0,arr,0,sums);



	// sort the returned arr
	sort(sums.begin(),sums.end());

	return sums;





}

//driver code
int main() {

	vector<int>arr= {5,2,1};
	vector<int>ans=subsetSum(arr);
	cout<<"subset sums are: "<<endl;
	for(int i:ans) cout<<" "<<i;




}