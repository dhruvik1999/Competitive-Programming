#include<bits/stdc++.h>
using namespace std;

vector<int> seq;
bool hasCycle( int node, int par , vector<int> *graph , vector<bool> &vis ){

	if( vis[node]==true ){
		for(int i=0;i<seq.size();i++){
				cout << seq[i] << " ";
		}
		cout << "\n";

		return true;
	}
	vis[node]=true;
	seq.push_back(node);
	bool ans = false;
	for(int i=0;i<graph[node].size();i++){
		if( graph[node][i] != par ){
			 ans = ans |  hasCycle(graph[node][i],node,graph,vis);
		}
	}

	seq.pop_back();

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
		graph[q].push_back(p);


	}

	vector<bool> vis( n+1  , false );

	cout << "ANS : " << hasCycle(1,-1,graph,vis) << "\n";
}