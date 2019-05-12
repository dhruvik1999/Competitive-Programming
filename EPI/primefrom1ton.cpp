#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >>  n;

	bool a[n+1];
	
	for(int i=0;i<n+1;i++)
		a[i]=true;

	for(int i=2;i<=sqrt(n);i++){
		for(int j=2;j*i<=n;j++){
			a[j*i]=false;
		}
	}

	for(int i=1;i<=n;i++){
		if(a[i]){
			cout << i << "\n";
		}
	}




	return 0;
}