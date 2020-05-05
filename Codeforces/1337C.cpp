#include<bits/stdc++.h>
using namespace std;

vector<int> dp(1000000,-1);

int dfs( vector<int> *tree, int node, vector<bool> vis ){

	vis[node]=true;

	int t = 0;
	for(int i=0;i<tree[node].size();i++){
		if( vis[ tree[node][i] ]==false ){
			t+=dfs(tree,tree[node][i],vis);
		}
	}
	return( dp[node]=t+1 );
}


int main(){

	int n,k;
	cin >> n >> k;

	vector< int > tree[n+1];
	int l,m;
	for(int i=0;i<n-1;i++){
		cin >> l >> m;
		tree[l].push_back(m);
		tree[m].push_back(l);
	}

	k=n-k;
	vector<bool> vis(n+10,false);
	dfs(tree,1,vis);

	vector< pair<int,int> > check;
	for(int i=1;i<=n;i++){
		check.push_back( { dp[i] , i} );
	}

	sort( check.begin() , check.end() );
	reverse( check.begin(), check.end() );

	for(auto aa : check){
		cout << aa.first << " " << aa.second << "\n";
	}

	return 0;
}