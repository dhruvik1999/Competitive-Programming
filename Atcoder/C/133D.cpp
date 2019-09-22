#include<bits/stdc++.h>
using namespace std;

int  main(){

	long long  n;
	cin >> n;

	vector<long long > a(n);
	for(long long  i=0;i<n;i++){
		cin >> a[i];
	}

	long long  temp = 0;

	bool tan = true;

	for(long long  i=n-1;i>=0;i--){
		if(tan){
			temp+=a[i];
			tan=false;
		}else{
			temp-=a[i];
			tan=true;
		}
	}

	vector<long long > ans(n);
	ans[0]=temp;

	//cout << ans[0] << "\n";

	for(long long  i=1;i<n;i++){
		ans[i] = (a[i-1]-ans[i-1]/2)*2;
	}

	for(long long  i=0;i<n;i++){
		cout << ans[i] << " ";
	}
	cout << "\n";


	return 0;
}