#include<bits/stdc++.h>
using namespace std;

void Dfs(int node , vector<int> *graph , vector<bool> &vis){
	vis[node]=true;
	cout << node <<  " ";

	for(int i=0;i<graph[node].size();i++){
		if(vis[graph[node][i]]==false)
			Dfs(graph[node][i],graph,vis);
	}

}


int main(){

	int n,m;
	cin >> n;

	vector<int> graph[n+1];
	int p,q;

	for(int i=0;i<n-1;i++){
		cin >> p >> q;
		graph[p].push_back(q);
		graph[q].push_back(p);
	}

	vector<bool> vis( n+1 , false);

	Dfs(1,graph,vis);
	cout << "\n";


	return 0;
}