#include<bits/stdc++.h>
using namespace std;

bool doWork(string s,int gap,int n){
	for(int i=0;i+gap<n;i++){
		if(s[i]!=s[i+gap]){
			return false;
		}
	}
	return true;
}


int main(){

	string s,t;
	cin >> s >> t;

	int n = s.length();
	int m = t.length();
	int l=(m+1)/2,r=m-1;
	int gap=m;

	while(l<=r){
		int mid = (l+r)>>1;

		if( doWork(t,mid,m) ){
			gap=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}

	string x="",y="";

	for(int i=0;i<(m-gap);i++){
		x+=t[i];
	}
	for(int i=m-gap;i<gap;i++){
		y+=t[i];
	}

	cout << x << " "<< y << " " << x << "\n";



	return 0;
}