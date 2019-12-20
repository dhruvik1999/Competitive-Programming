#include<bits/stdc++.h>
using namespace std;
vector< long long  > graph[500005];
vector<long long > bact(500005,0);
vector<long long > par(500005,-1);
vector<bool> islyf(500005,false);

void getPar(long long  node,long long  p){

	par[node]=p;
	if(graph[node].size()==1&&node!=1 || node==1&&graph[node].size()==0)
		islyf[node]=true;

	for(long long  i=0;i<graph[node].size();i++){
		if( par[ graph[node][i] ]==-1 ){
			getPar( graph[node][i],node );
		}
	}
}


int  main(){

	long long  n,q;
	cin >> n >> q;

	long long  t1,t2;
	for(long long  i=0;i<n-1;i++){
		cin >> t1 >> t2;

		graph[t1].push_back(t2);
		graph[t2].push_back(t1);


	}

	for(long long  i=1;i<=n;i++){
		cin >> bact[i];
	}

	par[1]=0;
	getPar(1,0);
	vector< vector<long long > > dp( n+10 , vector<long long > (q+5,0) );
	
	vector< pair<long long ,long long > > a;
	char t;

	for(long long  i=1;i<=n;i++){
		dp[i][0]=bact[i];
	}

	for(long long  i=1;i<=q;i++){
		cin >> t;
		if(t=='?'){
			cin >> t1;
			a.push_back( { i, t1} );
		}else{
			cin >> t1 >> t2;
			dp[t1][i]+=t2;
		}
	}

	// for(long long  i=1;i<=n;i++){
	// 	cout  << islyf[i] << " ";
	// 	for(long long  j=0;j<=q;j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	// cout << "\n\n";

	//cout << "*" << "\n";

	for( long long  j=1;j<=q;j++ ){
		
		for(long long  i=1;i<=n;i++){
			
				if( islyf[i] ){
					dp[i][j]+=(dp[ par[i] ][j-1] + dp[i][j-1]);
				}else{
					dp[i][j]+=dp[ par[i] ][j-1];
				}
			
		}	

	}
	

	// for(long long  i=1;i<=n;i++){
	// 	for(long long  j=0;j<=q;j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }


	for(long long  i=0;i<a.size();i++){
		cout << dp[a[i].second][a[i].first] << "\n";
	}

	





	return 0;
}