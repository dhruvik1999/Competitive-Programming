#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int l_max[n],r_max[n];
	l_max[0]=0;
	r_max[n-1]=0;

	for(int i=1;i<n;i++){
		l_max[i]=max(l_max[i-1],a[i-1]);
		r_max[n-i-1]=max(r_max[n-i],a[n-i]);
	}

	/*
	
	for(int i=0;i<n;i++){
		cout << i << " " << l_max[i] << " " << r_max[i] << "\n";
	}

	*/
	int temp;
	int ans = 0;
	for(int i=0;i<n;i++){
		temp = min(l_max[i],r_max[i])-a[i];
		if(temp>0){
			ans += temp;
		}
	}

	cout << ans << "\n";


	return 0;
}