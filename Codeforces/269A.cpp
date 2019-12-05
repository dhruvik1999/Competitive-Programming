#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector< pair<int,int> > a;
	int p,q;
	for(int i=0;i<n;i++){
		cin >> p >> q;
		a.push_back( {p,q} );
	}

	sort(a.begin(),a.end());

	if( a.size()>=2 ){
		for(int i=1;i<n;i++){
			a[i].second = max( a[i].second , (int)ceil( (float)a[i-1].second/pow(4,a[i].first-a[i-1].first) ) );
		}
	}

	pair<int,int> t = a.back();

	int ans = t.first;
	int box = t.second;

	if(box==1){
		cout << ans+1 << "\n";
		return 0;
	}

	while( box>1 ){
		ans++;
		box=ceil((float)box/4);
	}
	cout << ans << "\n";



	return 0;
}