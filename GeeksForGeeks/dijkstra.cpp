#include<bits/stdc++.h>
using namespace std;

vector<int> dis(10000,INT_MAX);

void dijkstra( vector< pair<int,int> > *g,int n,int src ){

	set< pair<int,int> > s;

	for(int i=1;i<=n;i++){
		if(src==i){
			s.insert( {0,i} );
			dis[src]=0;
		}else{
			s.insert({INT_MAX,i});
			dis[i]=INT_MAX;
		}
	}

	while(s.size()!=0){
		pair<int,int> p = *s.begin();
		s.erase(s.begin());

		int u,v,d;
		for(auto itr : g[p.second]){
			u = p.second;
			v = itr.first;
			d = itr.second;

			if( dis[u]+d<dis[v] ){
				s.erase({dis[v],v});
				dis[v] = dis[u] + d;
				s.insert( {dis[v],v} );

			}

		}

	}


}


int main(){

	int n,m;
	cin >> n >> m;

	vector< pair<int,int> > g[n+1];

	int a,b,c;
	for(int i=0;i<m;i++){
		cin >> a >> b >> c;

		g[a].push_back( make_pair(b,c) );
		g[b].push_back( make_pair(a,c) );

	}

	dijkstra( g,n,1 );

	for(int i=1;i<=n;i++){
		cout << i << " : " << dis[i] << "\n";
	}


	return 0;
}