#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector<int> a(n);
		map<int,int> mp;
		int ans = 0;
		for(int i=0;i<n;i++){
			cin >> a[i];
			ans = max( ans , mp[a[i]] );

			for(int j=1;j*j<=a[i];j++){
				if( a[i]%j==0 ){
					if(j*j==a[i]){
						mp[j]++;
					}else{
						mp[j]++;
						mp[a[i]/j]++;
					}
				}
			}

		}

		cout << ans << "\n";





	}


	return 0;
}