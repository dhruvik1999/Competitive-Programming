#include<bits/stdc++.h>
using namespace std;

int main(){

	long long int n;
	cin >> n;

	vector<long long int> a(n);
	for(long long int i=0;i<n;i++){
		cin >> a[i];
	}

	string s;
	cin >> s;

	long long int len = s.length();

	vector<long long int> bif(n+1,0), aft(n+1);

	for(long long int i=len-1;i>=0;i--){
		if( s[i]=='1' ){
			bif[i]=a[i]+bif[i+1];
		}else{
			bif[i]=bif[i+1];
		}
	}

	aft[0]=a[0];
	for(long long int i=1;i<len;i++){
		aft[i]=a[i]+aft[i-1];
	}

	long long int ans = bif[0];
	for(long long int i=1;i<n;i++){
		if( s[i]=='1' ){
			ans = max( ans , aft[i-1]+bif[i+1]  );
		}
	}

	cout << ans << "\n";

	return 0;
}