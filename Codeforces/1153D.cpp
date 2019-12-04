#include<bits/stdc++.h>
using namespace std;

int doWork(vector<int> *graph , int node , vector<int> &op , vector<bool> &vis, int lv){
	vis[node]=true;

	if( graph[node].size()==1 && node!=1 ){
		return lv;
	}

	if( op[node]==1 ){

	}else{

	}

}


int main(){


	int n;
	cin >> n;

	vector<int> op(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	vector< int > graph[n+1];
	int t;
	for(int i=2;i<=n;i++){
		cin >> t;
		graph[t].push_back(i);
		graph[i].push_back(t);
	}

	int lv = 0;
	for(int i=2;i<=n;i++){
		if( graph[i].size()==1 ){
			lv++;
		}
	}




	return 0;
}