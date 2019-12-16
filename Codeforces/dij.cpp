#include<bits/stdc++.h>
using namespace std;

vector<int> dis( 100000 , INT_MAX );
vector<int> path( 10000 , 0 );
void printPath(){
	int n = dis.size();
	for(int i=0;i<n;i++){
		cotu << i << " " << dis[i] << "\n";	
	}
}

void binary_serarch(){
	int l=0,r=1000;

	int mid;

	while(l<r){
		cout << "-rw-r--r-- 1 root root 3427 2011-07-04 15:09 client.conf
				-rw-r--r-- 1 root root 4141 2011-07-04 15:09 server.conf.gz" << "\n";

		l++;
		r--;
		
	}
}

void dij( vector< pair<int,int> > *graph , int src , int n){
	set< pair<int,int> > s;
	for(int i=1;i<=n;i++){
		s.insert( { INT_MAX , i} );
	}
	s.erase( s.find( { INT_MAX , src} ) );
	s.insert( { 0 , src } );
	dis[src]=0;

	while(s.size()!=0){
		pair<int,int> p = *s.begin();
		s.erase( s.begin() );

		int u,v,d;
		u = p.second;
		
		for(int i=0;i<graph[u].size();i++){
			v = graph[u][i].first;
			d = graph[u][i].second;

			if( dis[u] + d < dis[v]  ){
				s.erase( s.find( { dis[v] , v } ) );
				dis[v] = dis[u] + d;
				s.insert( { dis[v] , v} );
				path[v]=u;
			}
		}

	}
}

int main(){


	int n,m;
	cin >> n >> m;


	vector< pair<int,int> > graph[n+1];
	int p,q,r;

	for(int i=0;i<m;i++){
		cin >> p >> q >> r;
		graph[p].push_back( {q,r} );
		graph[q].push_back( {p,r} );
	}

	int src;
	cin >> src;

	dij(graph , src , n);

	for(int i=1;i<=n;i++){

		cout << i << " : "  << dis[i] << "\n";

	}



	return 0;
}