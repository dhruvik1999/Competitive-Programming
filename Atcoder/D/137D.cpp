#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,k;
	cin >> n >> k;

	vector< pair<int,int> > v;
	int t1,t2;

	for(int i=0;i<n;i++){
		cin >> t1 >> t2;
		if(t1<=k)
			v.push_back(make_pair(t1,t2));
	}

	priority_queue<long long> pq;

	long long ans = 0;

	for(int i=1;i<=k;i++){
		for(int j=0;j<v[i].size();j++){
			pq.push(v[i][j]);
		}
		if(pq.size()!=0){

		ans+= pq.top();
		pq.pop();
		}
	}

	cout << ans << "\n";


	return 0;
}