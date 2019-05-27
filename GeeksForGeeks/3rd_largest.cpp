#include<bits/stdc++.h>
using namespace std;

int  main(){
	int n;
	cin >> n;

	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int fir=INT_MIN,sec=INT_MIN,thir=INT_MIN;
	for(int i=0;i<n;i++){
		if(a[i] > fir){
			thir = sec;
			sec = fir;
			fir = a[i];
		}else if(a[i] > sec &&  a[i]!=fir){
			thir = sec;
			sec = a[i];
		}else if(a[i] > thir && a[i]!=fir && a[i] != sec){
			thir=a[i];
		}
	}

	cout << fir << " " << sec << " " << thir << "\n";

	return 0;
}