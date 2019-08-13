#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,temp;
	cin >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> temp;
		a[i] = temp<0?temp*-1:temp;
	}

	sort(a.begin(),a.end());

	// for(int i=0;i<n;i++){
	// 	cout << a[i] << "\n";
	// }

	long long  ans = 0,range;

	for(int i=0;i<n;i++){
		range = ( upper_bound(a.begin(),a.end(),a[i]*2)-a.begin())-1-i;
		//cout << a[i] << " " << upper_bound(a.begin(),a.end(),a[i]*2)-a.begin()-1-i << "\n";
		ans = ans + range;
	}

	cout << ans << "\n";

	return 0;	
}