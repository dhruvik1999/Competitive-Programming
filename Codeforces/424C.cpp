#include<bits/stdc++.h>
using namespace std;

 int main(){

	long long int n;
	cin >> n;
	long long int ans = 0;
	vector<long long int> a(n);
	for(long long int i=0;i<n;i++){
		cin >> a[i];
		ans = (ans)^(a[i]);
	}

	vector<long long int> xo(n+1,0);
	for(long long int i=1;i<=n;i++){
		xo[i] = ((i)^(xo[i-1]));
	}

	// for(long long int i=0;i<=n;i++){
	// 	cout << xo[i] << " ";
	// }
	// cout << "\n";

	long long int com,rem;
	for(long long int i=2;i<=n;i++){
		com = n/i;
		rem = n%i;

		if(com%2==0){
			ans = ((ans)^(xo[rem]));
		}else{
			ans = ((ans)^(xo[i-1])^(xo[rem]));
		}
	}

	cout << ans << "\n";


	return 0;
}