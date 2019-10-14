#include<bits/stdc++.h>
using namespace std;

bool check( vector<long long > &a , long long  gap,long long  n ){
	for(long long  i=0;i<=n-gap;i++){
		//s.clear();
		unordered_set<long long > s;
		bool lock = true;


		for(long long  j=0;j<n ;j++){
			if(!( j<i || j>=i+gap ))
				continue;
			//cout << a[j] << " ";
			if( s.find( a[j] )!=s.end() ){
				lock = false;
				break;
			}else{
				s.insert(a[j]);
			}
		}
		//cout << "\n";

		if(lock)
			return true;
	}
	return false;
}

bool check1( vector<long long > &a,long long  gap,long long  n ){
	vector<long long > frq(2005,0);
	bool lock = true;
	for(long long  i=0;i<n;i++){
		if(i>=gap){
			frq[a[i]]++;

			if(frq[a[i]]>1){
				lock = false;
			}
		}
	}
	if(lock)
		return true;

	for(long long  r=gap;r<n;r++){
		frq[ a[r-gap] ]++;
		frq[ a[r] ]--;

		bool lock = true;

		for(long long  i=0;i<n;i++){
			if( frq[a[i]]>1 ){
				lock = false;
			}
		}

		if(lock)
			return true;;

	}


	return false;
}

int  main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long long  n;
	cin >> n;

	vector<long long > a(n);
	for(long long  i=0;i<n;i++){
		cin >> a[i];
	}
	long long  l=0,r=n;
	long long  ans = 0;

	//cout << check(a,1,n) << "\n";

	while(l<=r){
		long long  mid = (l+r)>>1;
		//cout << l << " " << r << "\n";
		if( check1(a,mid,n) ){
			ans = mid;
			//cout << ans << "\n";
			r=mid-1;
		}else{
			l=mid+1;
		}
	}

	cout << ans << "\n";



	return 0;
}