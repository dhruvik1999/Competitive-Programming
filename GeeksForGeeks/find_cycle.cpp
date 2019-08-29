#include<bits/stdc++.h>
using namespace std;

bool isCyclePresent(vector< int > *v , int node,int n,vector<int> color){
	if(color[node]==1)
		return true;

	color[node]=1;
	bool ans = false;
	for(int i=0;i<v[node].size();i++){
		if(v[node][i] != node)
			ans = ans || isCyclePresent(v,v[node][i],n,color);
	}
	color[node]=2;

	return ans;
}


int main(){
	int n,e;
	cin >> n >> e;

	vector< int > v[n];
	int a,b;
	for(int i=0;i<e;i++){
		cin >> a>> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<v[i].size();j++){
	// 		cout << v[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	vector< int > color(n,0);
	cout << "ANS : " << isCyclePresent(v,0,n,color) << "\n";





	return 0;
}