#include<bits/stdc++.h>
using namespace std;
void Dfs(vector< vector<int> > &graph ,vector<int> &we, vector<int> &ans,int node,vector<bool> &vis ,int sum){
	vis[node]=true;
	ans[node] = we[node]+sum;

	//ans[node]=we[node];
	for(int i=0;i<graph[node].size();i++){
		if(vis[ graph[node][i] ] == false){
			Dfs(graph,we,ans,graph[node][i],vis,sum+we[node]);
			//ans[node]+=ans[graph[node][i]];
		}
	}
}


int main(){

	int n,q;
	cin >> n >> q;

	int t1,t2;
	vector< vector<int> > graph(n+10);

	for(int i=0;i<n-1;i++){
		cin >> t1 >> t2;
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}

	vector< int > we(n+10,0);
	vector<int> ans(n+10,0);
	vector<bool> vis(n+10,false);
	for(int i=0;i<q;i++){
		cin >> t1 >> t2;
		we[t1]+=t2;
	}

	Dfs(graph,we,ans,1,vis,0);

	for(int i=1;i<=n;i++){
		cout << ans[i] << " ";
	}
	cout << "\n";



	return 0;
}