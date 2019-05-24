#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int a[n];
	for(int i=0;i<n;i++){
		cin >>a[i];
	}

	sort(a,a+n);
	int ans = INT_MAX;
	int temp;
	for(int i=n-1;i>=0;i--){
		temp = upper_bound(a,a+n,a[i]/2) - a;
		cout << a[i] << " " << temp << "\n";
		ans = min(ans , n-(i-temp+1));
	}

	cout << "Ans : " << ans << "\n";
	return 0;
}