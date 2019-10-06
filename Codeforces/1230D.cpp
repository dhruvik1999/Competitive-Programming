#include<bits/stdc++.h>
using namespace std;

int  main(){
	long long  n;
	cin >> n;

	vector< pair<long long ,long long > > a(n);
	long long  t;
	for(long long  i=0;i<n;i++){
		cin >> t;
		a[i].first=t;
	}
	for(long long  i=0;i<n;i++){
		cin >> t;
		a[i].second=t;
	}

	sort(a.begin(),a.end());

	vector<long long > temp(n,0);

	for(long long  i=1;i<n;i++){
		bool lock = false;
		while(i<n && a[i-1].first==a[i].first){
			lock = true;
			i++;
		}
		t=i-1;

		if(lock){
		for(long long  j=t;j>=0;j--){
			if( ((a[j].first)|(a[t].first))==a[t].first ){
				temp[j]=1;
			}
		}
	}

	}

	long long  ans =0 ;

	for(long long  i=0;i<n;i++){
		if(temp[i]==1)
		ans+=a[i].second;
	}
	cout << ans <<"\n";

	return 0;
}