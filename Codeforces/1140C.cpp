#include<bits/stdc++.h>
using namespace std;

struct cmp{
	bool operator()(int a,int b){
		return a>b;
	}
};

int main(){

	long long n,k;
	cin >> n >> k;

	vector< pair<long long,long long> > p;
	long long a,b;
	for(long long i=0;i<n;i++){
		cin >> a >> b;
		p.push_back(make_pair(b,a));
	}

	sort(p.begin(),p.end());


	priority_queue< int , vector<int> , cmp > pq;

	long long ms = 0;
	long long ans = 0;
	for(long long i=n-1;i>=0;i--){
		if(n-i<=k){
			ms+=p[i].second;
			pq.push(p[i].second);

			//if(n-i==k){
				ans = max(ans , ms*p[i].first);
			//}

		}else{
			if(pq.top()<p[i].second){
				ms-=pq.top();
				ms+=p[i].second;
				pq.pop();
				pq.push(p[i].second);
				ans = max(ans , ms*p[i].first);
			}
		}
	}

	cout << ans << "\n";


	return 0;
}