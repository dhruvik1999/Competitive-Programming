#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector<int> a(n+10);
		for(int i=1;i<=n;i++){
			cin >> a[i];
		}
		a[0]=INT_MAX;
		int ans = 0;

		for(int i=1;i<=n;i++){
			bool lock = true;
			for(int j=i-1;j>=0 && j>=i-5;j--){
				if( a[j]<=a[i] ){
					lock = false;
					break;
				}
			}
			if(lock){
				ans++;
				//cout  << a[i] << "\n";
			}
		}

		cout << ans << "\n";



	}


	return 0;
}