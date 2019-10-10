#include<bits/stdc++.h>
using namespace std;


bool hasOddCycle(int node , vector<int>*graph , vector<bool> &vis ,vector<int> &lvl){

	queue<int> q;
	q.push(node);
	lvl[node]=1;

	while(q.size()!=0){
		node = q.front();
		q.pop();
		

		for(int i=0;i<graph[node].size();i++){
			if(vis[graph[node][i]]==false){
				q.push(graph[node][i]);
				lvl[graph[node][i]] = lvl[node]+1;
				vis[ graph[node][i] ]=true;
			}
		}


	}

}


int main(){

	int n,m;
	cin >> n >> m;

	vector<int> graph[n+1];
	int p,q;

	for(int i=0;i<n;i++){
		cin >> p >> q;

		graph[p].push_back(q);
		graph[q].push_back(p);


	}

	vector<bool> vis(n+1,false);
	vector<int> lvl(n+1,0);

	hasOddCycle(1,graph,vis,lvl);


	for(int i=1;i<=n;i++){
		cout << i << " " << lvl[i] << "\n";
	}


	for(int i=1;i<=n;i++){
		bool lock = false;
		for(int j=0;j<graph[i].size();j++){
			if( lvl[ i ] == lvl[ graph[i][j] ] ){
				cout << "ODD CYCLE FOUND" << "\n";
				lock = true;
				break;
			}
		}
		if(lock){
			break;
		}
	}

	cout << "_____" << "\n";





}