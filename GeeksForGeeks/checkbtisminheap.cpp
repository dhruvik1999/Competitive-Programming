#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n+1];

	for(int i=1;i<=n;i++){
		cin >> a[i];
	}

	if(((n)&(n+1))!=0){
		cout  << "1." << "not heap" << "\n";
		return 0;
	}

	for(int i=1;i<=(n-1)/2;i++){
		if(a[i] > a[2*i] || a[i] > a[2*i+1]){
			cout << "Not heap" << "\n";
			return 0;
		}
	}

	cout << "given bt is heap" << "\n";

	return 0;
}