#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector< vector<int> > a(n, vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
		}
	}

	double mulall = 1;
	vector<int> ans(n);
	if(n%2==1){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				mulall = mulall * pow(a[i][j],0.25);
			}
		}

		ans[0] = ceil(mulall);

		for(int i=1;i<n;i+=2){
			ans[0] = ans[0]/a[i][i+1];
		}

	}else{
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n-1;j++){
				mulall = mulall * pow(a[i][j],0.25);
			}
		}

		ans[0] = ceil(mulall);

		cout << ans[0] << "\n";

		for(int i=1;i<n-1;i+=2){
			ans[0] = ans[0]/a[i][i+1];
		}
	}

	cout << ans[0] << "\n";


	





	return 0;
}