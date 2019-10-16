#include<bits/stdc++.h>
using namespace std;
int   main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


	long long  n;
	cin >> n;

	vector<long long > a(n);
	for(long long  i=0;i<n;i++){
		cin >> a[i];
	}

	deque< pair<long long ,long long > > dp;
	long long  cmp = LONG_LONG_MAX;
	vector<long long > ans(n);
	for(long long  i=n-1;i>=0;i--){

		if( a[i]<cmp ){
			cmp=a[i];
			dp.push_front( { a[i] , i } );
			ans[i]=-1;
		}else if( i!=n-1 && a[i]==a[i+1] ){
			if( ans[i+1]==-1 ){
				ans[i]=-1;
			}else{
				ans[i]=ans[i+1]+1;
			}
		}else{
			auto g = lower_bound( dp.begin(),dp.end(),make_pair( a[i],(long long)1 ) );
			ans[i] = ( (*(g-1)).second-i-1 );
		}


	}

	for(long long  i=0;i<n;i++){
		cout << ans[i] << " ";
	}
	cout << "\n";


	return 0;
}