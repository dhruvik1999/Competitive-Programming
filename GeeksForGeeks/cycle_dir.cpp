#include<bits/stdc++.h>
using namespace std;

bool has_cycle(vector<int> *graph,int node,vector<bool> &vis){

	if( vis[node]==true ){
		return true;
	}

	vis[node]=true;
	bool ans = false;
	for(int i=0;i<graph[node].size();i++){
		
			ans = ans | has_cycle(graph,graph[node][i],vis);
	}

	return ans;
}


int main(){

	int n,m;
	cin >> n >> m;

	vector<int> graph[n+1];
	int p,q;

	for(int i=0;i<m;i++){
		cin >> p >> q;
		graph[p].push_back(q);
	}

	vector<bool> vis( n+1 , false );

	cout << has_cycle(graph,1,vis) << "\n";




	return 0;
}