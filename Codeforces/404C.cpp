#include<bits/stdc++.h>
using namespace std;

int main(){

	long long  n,k;
	cin >> n >> k;

	vector<long long > dis[100005];
	long long  nz=0,zp=-1,md=0,a;
	for(long long  i=0;i<n;i++){
		cin >> a;
		md=max(md,a);
		dis[a].push_back(i+1);
		if(a==0){
			nz++;
			zp=i;
		}
	}

	if( nz!=1 ){
		cout << -1 << "\n";
		return 0;
	}

	vector< pair<long long ,long long > > ans;
	for(long long  i=0;i<md;i++){
		if(i==0){
			if( dis[1].size()<=k && dis[1].size()>0){
				for(long long  j=0;j<dis[1].size();j++){
					ans.push_back( { dis[0][0] , dis[i+1][j] } );
				}
			}else{
				cout << -1 << "\n";
				return 0;
			}
		}else{
			
			if( dis[i].size()*(k-1) < dis[i+1].size() || dis[i+1].size()==0 ){
				cout << -1 << "\n";
				return 0;
			}



			long long  g=-1;
				for(long long  h=0;h<dis[i+1].size();h++){
					if( h%(k-1)==0 )
						g++;
					ans.push_back( { dis[i][g] , dis[i+1][h] } );
				}
			

		}
	}

	cout << ans.size() << "\n";
	for(long long  i=0;i<ans.size();i++){
		cout << ans[i].first << " " << ans[i].second << "\n";
	}




	return 0;
}