#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> dis( 100000 , INT_MAX );

void dij( vector< pair<ll,ll> > *graph , int n ){
	set< pair<ll,ll> > s;
	for(int i=1;i<=n;i++){
		if( i!=1 ){
			s.insert( {INT_MAX , i} );
		}else{
			s.insert( {0 , 1} );
		}
	}
	dis[1]=0;

	while(s.size()!=0){
		pair<ll,ll> p = *s.begin();
		s.erase( s.begin() );

		for(int i=0;i<graph[ p.second ].size();i++){

			if( p.first + graph[p.second][i].second < dis[ graph[p.second][i].first ] ){

				s.erase( s.find( { dis[ graph[p.second][i].first ] , graph[p.second][i].first } ) );
				dis[ graph[p.second][i].first ] = p.first + graph[p.second][i].second;
				s.insert( {	 dis[ graph[p.second][i].first ] , graph[p.second][i].first } );
			}
		}

	}

}


int main(){

	int n,m;
	cin >> n >> m;

	vector< pair<ll,ll> > graph[n+1];

	int p,q,r;
	for(int i=0;i<m;i++){
		cin >> p >> q >> r;

		graph[p].push_back( { q , r } );
		graph[q].push_back( { p , r } );

	}
	dij(graph,n);
	for(int i=1;i<=n;i++){
		cout << i << " :: " << dis[i] << "\n";
	}

	return 0;
}