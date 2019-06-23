#include<bits/stdc++.h>
using namespace std;


int main(){

	int t;
	cin >> t;
	while(t--){

		int n,m;
		cin >> n >> m;

		int a[n];
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		int j;
		int sum = 0;
		int ans = 0;

		for(j=0;j<min(n,m);j++){
			sum = sum + a[j];
			ans = max(ans,sum);
		}

		//cout << "\n" << sum << "\n";
		
		if(n>m){
		for(int i=0;i<n;i++){
				sum = sum + a[j] - a[i];
				ans = max(ans,sum);
				j = (j+1)%n;	
			}
		}

			//cout << sum << " ";
	
		//cout << "\n";

		cout << ans << "\n";

	}


	return 0;
}	