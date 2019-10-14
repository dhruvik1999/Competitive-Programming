#include<bits/stdc++.h>
using namespace std;

vector<int> cyc;
vector<int> path;
void dfs( vector<int> *graph, int node , vector<bool>vis, int pnode){


	if( vis[node]==true ){
		path.pop_back();
		for(int i=path.size()-1;i>=0;i--){
			if( path[i]!=node ){
				cyc.push_back( path[i] );
			}else{
				cyc.push_back(node);
				break;
			}
		}
		path.push_back(node);
		return;
	}
	// //cout << node << " \n";
	// for(int i=0;i<path.size();i++){
	// 	cout << path[i] << " ";
	// }
	//cout << "\n";
	vis[node]=true;
	for(int i=0;i<graph[node].size();i++){
		if( graph[node][i]!=pnode && cyc.size()==0){
			path.push_back(graph[node][i]);
			dfs( graph , graph[node][i] , vis , node );
			path.pop_back();
		}
	}
}

void doWork( vector<int> *graph , int node , vector<int> &dp , vector<bool> &vis , int pnode){

	if( dp[node]==-1){
		dp[node]=dp[pnode]+1;
	}
	vis[node]=true;
	//cout << node << "\n";

	for(int i=0;i<graph[node].size();i++){
		if( vis[ graph[node][i] ]==false ){
			doWork(graph,graph[node][i],dp,vis,node);
		}
	}

}


int main(){

	int n;
	cin >> n;

	vector<int> graph[n+1];
	int p,q;
	for(int i=0;i<n;i++){
		cin >> p >> q;
		graph[p].push_back(q);
		graph[q].push_back(p);
	}

	vector<bool> vis(n+1,false);
	path.push_back(1);
	dfs(graph , 1 , vis , -1);

	vector< int > dp(n+1,-1);
	for(int i=0;i<cyc.size();i++){
		dp[ cyc[i] ]=0;
	}

	vector<bool> vis1(n+1,false);
	doWork(graph,cyc[0],dp,vis1,-1);
	for(int i=1;i<=n;i++){
		cout << dp[i] << " ";
	}
	cout << "\n";


	





	return 0;
}