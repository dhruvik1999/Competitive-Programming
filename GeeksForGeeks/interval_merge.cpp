#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	vector< pair<int,int> > a(n);

	int t1,t2;
	for(int i=0;i<n;i++){
		cin >> t1 >> t2;
		a[i] = make_pair(t1,t2);
	}

	for(int i=1;i<a.size();i++){
		if( a[i-1].second >= a[i].first ){
			a[i-1].second = a[i].second;
			a.erase(a.begin()+i);
			i--;
		}
	}

	for(int i=0;i<a.size();i++){
		cout << a[i].first << " " << a[i].second << "\n";
	}

	return 0;

}