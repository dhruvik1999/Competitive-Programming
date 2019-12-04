#include<bits/stdc++.h>
using namespace std;

vector<int> dp(1000,-1);

void doWork( vector<int> *graph, int node, vector<int> &val, int root ){

	cout << node << "\n";
	dp[node]=val[node];
	if( graph[node].size()==1 && node!=root){
		return ; 
	}

	int t = 0;
	for(int i=0;i<graph[node].size();i++){
		if(dp[ graph[node][i] ]==-1){
			doWork(graph,graph[node][i],val,root);
		}
		t = max( t , dp[ graph[node][i] ] );
	}

	dp[node]+=t;
	return ;

}
int main(){

	int n;
	cin >> n;

	vector<int> graph[n+1];
	int p,q;

	for(int i=0;i<n-1;i++){
		cin >> p >> q;
		graph[p].push_back(q);
		graph[q].push_back(p);
	}

	vector<int> val(n+1);
	for(int i=1;i<=n;i++){
		cin >> val[i];
	}
	vector<bool> vis(n+1,false);
	int root;
	cin >> root;

	doWork(graph,root,val,root);
	cout << "ANS : " << "\n";
	cout << dp[root] << "\n";

	return 0;
}