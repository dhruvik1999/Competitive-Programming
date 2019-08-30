#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector< pair<int,int> > a;
	int t;

	for(int i=0;i<n;i++){
		cin >> t;
		a.push_back(make_pair(t,i+1));
	}

	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				//cout << a[i].first << " " << a[j].first << " " << a[k].first << "\n";
				if(a[i].first == a[j].first+a[k].first){
					cout << a[i].second << " " << a[j].second << " " << a[k].second << "\n";
					return 0;
				}
			}
		}
	}

	cout << -1 << "\n";


	return 0;
}