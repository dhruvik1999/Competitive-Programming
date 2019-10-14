#include<bits/stdc++.h>
using namespace std;

void doWork(int node , vector<int> *graph,vector<bool> &vis){
	vis[node]=true;

	for(int i=0;i<graph[node].size();i++){
		if( vis[ graph[node][i] ]==false ){
			doWork(graph[node][i] , graph , vis);
		}
	}
}


int main(){

	int n,m;
	cin >> n >> m;

	set< pair<int,int> > s;
	int p,q;

	for(int i=0;i<m;i++){
		cin >> p >> q;
		s.insert( { min(p,q) , max(p,q) } );
	}

	vector<int> graph[n+1];
	for(auto i : s){
		graph[ i.first ].push_back(i.second);
		graph[ i.second ].push_back(i.first);
	}

	vector<bool> vis( n+1 , false );

	int comp = 0;

	for(int i=1;i<=n;i++){
		if(vis[i]==false){
			comp++;
			doWork(i,graph,vis);
		}		
	}

	cout << m-(n-comp) << "\n";

	return 0;
}