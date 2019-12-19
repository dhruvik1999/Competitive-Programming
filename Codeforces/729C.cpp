#include<bits/stdc++.h>
using namespace std;


bool doWork(vector<double> &dis,long long int t,long long int k,long long int mid){
	double t1=0,t2=0,tt1,tt2;
	for(long long int i=0;i<k;i++){
		tt1 = max( 0.0 ,  ( 2*dis[i]- mid)*2 );
		tt2 = dis[i] - 0.5*tt1;
		//cout << tt1 << " " << tt2 << "\n";
		if(tt2<0)
			return false;
		t1+=tt1;
		t2+=tt2;
	}

	//cout << t1 << " " << t2 << "\n";

	if( t1+t2<=t ){
		return true;
	}else{
		return false;
	}

}


int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long long int n,k,s,t;
	cin >> n >> k >> s >> t;

	vector<pair<long long int,long long int>> cv;
	long long int p,q;
	long long int ld = 0;

	for(long long int i=0;i<n;i++){
		cin >> p >> q;
		cv.push_back( {p,q} );
	}

	vector<double> dis;
	for(long long int i=0;i<k;i++){
		cin >> p ;
		dis.push_back(p);
	}
	dis.push_back(s);
	sort(dis.begin(),dis.end());

	long long int sum = 0;
	for(long long int i=0;i<=k;i++){
		dis[i]-=sum;
		sum+=dis[i];
		//cout << dis[i] << "\n";
	}

	// for(long long int i=0;i<n;i++){
	// 	cout << doWork(dis,t,k+1,cv[i].second) << "\n\n";
	// }

	long long int l=1,r=1000000000;
	long long int cap=r+5;
	while(l<=r){
		long long int mid = (l+r)>>1;

		if( doWork( dis , t , k+1 , mid ) ){
			cap = mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}

	long long int ans = INT_MAX;
	for(long long int i=0;i<n;i++){
		if( cv[i].second >= cap ){
			ans = min( ans , cv[i].first );
		}
	}

	if(ans == INT_MAX){
		cout << -1 <<"\n";
	}else{
		cout << ans << "\n";
	}


	return 0;
}