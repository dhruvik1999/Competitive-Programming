#include<bits/stdc++.h>
using namespace std;

int  main(){

	int n;
	cin >> n;

	vector<  int > ans[n];

	int k=n*n;

	while(k>0){
		//cout << k << "\n";
		for(int i=0;i<n;i++){
			ans[i].push_back(k);
			k--;
		}
		if( k<=0 )
			break;

		for(int i=n-1;i>=0;i--){
			ans[i].push_back(k);
			k--;
		}
		if(k<=0)
			break;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

}