#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> a(n+1),b(n);

	for(int i=0;i<=n;i++){
		cin >> a[i];
	}

	for(int j=0;j<n;j++){
		cin >> b[j];
	}

	long long ans = 0;

	for(int i=0;i<n;i++){
		if(b[i] < a[i]){
			ans+=b[i];
			a[i]-=b[i];
		}else{
			ans+=a[i];
			b[i]-=a[i];

			if(b[i]<a[i+1]){
				ans+=b[i];
				a[i+1]-=b[i];
			}else{
				ans+=a[i+1];
				a[i+1]=0;
			}
		}
	}

	cout << ans << "\n";


	return 0;
}