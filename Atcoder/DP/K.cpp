#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,k;
	cin >> n >> k;

	vector<int> a(n);
	int mm = INT_MAX;
	for(int i=0;i<n;i++){
		cin >> a[i];
		mm = min(mm , a[i]);
	}

	vector< int > dp(k+10);
	for(int i=0;i<mm;i++){
		dp[i]=1;
	}
	// for(int i=0;i<=k;i++){
	// 	cout << dp[i] << " ";
	// }
	// cout << "\n";
	sort(a.begin(),a.end());

	for(int i=mm;i<=k;i++){
		dp[i]=1;
		for(int j=0;j<n;j++){
			if(i-a[j]>=0){
				if(dp[i-a[j]]==1){
					dp[i]=0;
					break;
				}
			}else{
				break;
			}
		}
	}

	// for(int i=0;i<=k;i++){
	// 	cout << dp[i] << " ";
	// }
	// cout  << "\n";

	if(dp[k]==1){
		cout << "Second" << "\n";
	}else{
		cout << "First" << "\n";
	}


	return 0;
}