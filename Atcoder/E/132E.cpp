#include<bits/stdc++.h>
using namespace std;

void doWork( vector<int> *g , vector<int> &graph , int node  , int len){
	if(len==3){
		graph.push_back( node );
		return ;
	}


	for(int i=0;i<g[node].size();i++){
			doWork(g,graph,g[node][i],len+1);
	}
}

int dfs( vector<int> *graph , int node  ,int tt , vector<bool> vis,int n){
	vector< int > dis( n+1,0 );

	queue<int> q;
	q.push( node );
	dis[node]=0;

	while(q.size()!=0){

		int t = q.front();
		q.pop();
		vis[t]=true;
		//cout << t << "\n";

		for( int i=0;i<graph[t].size();i++){
			if(vis[ graph[t][i] ]==false){
				q.push( graph[t][i] );
				vis[ graph[t][i] ]=true;
				dis[ graph[t][i] ] = dis[ t ] + 1;
				if(graph[t][i]==tt){
					return dis[graph[t][i]];
				}
			}
		}



	}

	return INT_MAX;

}


int main(){

	int n,m;
	cin >> n >> m;

	vector<int> g1[n+1];
	int p,q;

	for(int i=0;i<m;i++){
		cin >> p >> q;
		g1[p].push_back(q);
	}
	int s,t;
	cin >> s >> t;
	vector<int> graph[n+1];

	for(int i=1;i<=n;i++){
		doWork( g1,graph[i],i,0 );
	}

	for(int i=1;i<=n;i++){
		g1[i].clear();
		sort( graph[i].begin(), graph[i].end() );
		graph[i].erase( unique( graph[i].begin() , graph[i].end() ) , graph[i].end() );
	}

	// for(int i=1;i<=n;i++){
	// 	cout <<  i << " :: ";
	// 	for( int j=0;j<graph[i].size();j++ ){
	// 		cout << graph[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	vector<bool> vis( n+1 , false );
	 int ans = dfs( graph , s  , t , vis ,n) ;

	 if(ans == INT_MAX){
	 	cout << -1 << "\n";
	 }else{
	 	cout << ans << "\n";
	 }


	return 0;
}