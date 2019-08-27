#include<bits/stdc++.h>
using namespace std;

vector<int> graph[500];
bool check(vector<bool> vis,int node,int r){
	vis[node]=true;

	if(node==r)
		return true;
	//cout << "^^" << "\n";


	bool ans =false;

	for(int i=0;i<graph[node].size();i++){
		if(vis[ graph[node][i] ]==false){
			ans = ans || check(vis,graph[node][i],r);
		}
	}

	return ans;
}


int main(){

	int n;
	cin >> n;

	vector<int> a(n),b(n);

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	for(int i=0;i<n;i++){
		cin >> b[i];
	}



	for(int i=0;i<n;i++){
		if(i+1+b[i]<=n){
			graph[i+1+b[i]].push_back(i+1);
			graph[i+1].push_back(i+1+b[i]);
		}

		if(i+1-b[i]>=1){
			graph[i+1-b[i]].push_back(i+1);
			graph[i+1].push_back(i+1-b[i]);	
		}
	}



	for(int i=0;i<n;i++){
		vector<bool> vis(n+5,false);

		if(!check(vis,a[i],i+1)){
			cout << "NO"  << "\n";
			return 0;
		}
	}



	cout << "YES" << "\n";


	return 0;
}
