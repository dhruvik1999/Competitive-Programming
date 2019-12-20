#include<bits/stdc++.h>
using namespace std;
#define lim 1000000000000


long long  dic(string n,long long  b){
	long long ans = 0;
	long long  p =1;

	for(long long  i=n.length()-1;i>=0;i--){

		if(ans>lim){
			return -1;
		}

		if( '0' <= n[i] && n[i]<='9'  ){
			ans+= p*((long long)(n[i]-'0'));
		}else{
			ans+= p*( (long long)(10 + (n[i] - 'A')) );
		}

		p=p*b;
	}

	if(ans>lim){
			return -1;
	}

	return ans;

}


int main(){

	long long  t;
	cin >> t;

	while(t--){

		long long  n;
		cin >> n;

		vector< pair<long long ,string> > a(n);
		long long  y;
		string yy;
		for(long long  i=0;i<n;i++){
			cin >> y >> yy;
			a[i]=make_pair(y,yy);
		}

		unordered_map< long long ,long long  > mp;

		for(long long  i=0;i<n;i++){

			unordered_set<long long > s;

			if(a[i].first==-1){

				long long  st = 1;
				string lema = a[i].second;

				for(long long  j=0;j<lema.length();j++){
					if( '0'<= lema[j] && lema[j] <= '9'){
						st = max(st,(long long)(lema[j]-'0'));
					}else{
						st = max( st , (long long)(10+(lema[j]-'A')) );
					}
				}
				
				// cout << "ST :: " << st << "\n";

				for(long long  j=st+1;j<=36;j++){
					long long ans = dic( lema , j );
					//cout << j << " " << lema << " " << ans << "\n";
					if(ans!=-1){
						s.insert(ans);
					}
				}

				for(auto k : s){
					mp[k]++;
				}


			}else{
					long long ans = dic(a[i].second , a[i].first );
					if(ans!=-1){
						mp[ans]++;
					}
			}
		}

		long long ans = lim+1;

		for( auto i : mp ){
			//cout << i.first << " " << i.second << "\n";
			if(i.second==n){
				ans = min( ans , i.first );
			}
		}

		if(ans==lim+1){
			cout << -1 << "\n";
		}else{
			cout << ans << "\n";
		}





	}


	return 0;
}