#include<bits/stdc++.h>
using namespace std;

int doWork( vector<int> *v, vector<int> &op , vector<bool> &vis , int node){

	vis[node]=true;

	if( v[node].size()==1 && node!=1){
		return node;
	}

	int t;

	if( op[node]==1 ){
		cout << "+" << "\n";
		t = INT_MIN;
		for(int i=0;i<v[node].size();i++){
			if( vis[ v[node][i] ]==false ){
				t = max( t , doWork(v,op,vis,v[node][i]) );
			}
		}
	}else{
		cout << "-" << "\n";

		t = INT_MAX;
		for(int i=0;i<v[node].size();i++){
			if( vis[ v[node][i] ]==false ){
				t = min( t , doWork(v,op,vis,v[node][i]) );
			}
		}
	}

	return t;

}


int main(){

	int n;
	cin >> n;

	vector<int> op(n+1);
	for(int i=1;i<=n;i++){
		cin >> op[i];
	}

	vector<int> g[n+1];

	int t;
	for(int i=2;i<=n;i++){
		cin >> t;
		g[i].push_back(t);
		g[t].push_back(i);
	}

	vector<bool> vis(n+10,false);
	cout << doWork(g,op,vis,1) << "\n";





	return 0;
}