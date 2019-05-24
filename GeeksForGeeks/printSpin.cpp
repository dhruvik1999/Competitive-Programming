#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
		}
	}

	int r=n-1,l=0,d=n-1,u=0;

	while(l<=r && u<=d){
		
		
		for(int i=l;i<=r;i++){
			cout << a[u][i] << " ";
		}
		u++;

		for(int i=u;i<=d;i++){
			cout << a[i][r] << " ";
		}
		r--;

		for(int i=r;i>=l;i--){
			cout  << a[d][i] << " ";
		}
		d--;

		for(int i=d;i>=u;i--){
			cout << a[i][l] << " ";
		}
		l++;
	}

	cout << "\n";





	return 0;
}