#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> a(n),b(n);

	for(int i=0;i<n;i++){
		cin >> a[i];
		b[i]=a[i];
	}
	sort(b.begin(),b.end());

	unordered_map<int,int> mp;
	int ans = 0;

	for(int i=0;i<n;i++){

		mp[ a[i] ]++;
		mp[ b[i] ]--;

		if(mp[b[i]]==0){
			mp.erase( b[i] );
		}


		if(mp[a[i]]==0){
			mp.erase( a[i] );
		}

		if(mp.size()==0){
			ans++;
		}


	}

	cout << ans << "\n";


	return 0;
}