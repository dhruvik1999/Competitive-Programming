#include<bits/stdc++.h>
using namespace std;

vector< int > graph[100];

bool hasPath(vector<bool> &vis,int node,int trg){
	vis[node]=true;
	if(node==trg)
		return true;

	//cout << "&&" << "\n";


	bool ans = false;
	for(int i=0;i<graph[node].size();i++){
		if(vis[ graph[node][i] ]==false){
			ans = ans || hasPath(vis,graph[node][i],trg);
		}
	}



	return ans;

}



int main(){	
	int n;
	cin >> n;

	int t1,t2;
	vector<int> frq(n+1,0);

	for(int i=0;i<(n*(n-1))/2-1;i++){
		cin >>t1 >> t2;
		graph[t2].push_back(t1);
		
			frq[t1]++;
			frq[t2]++;
	}
	int to=-1,from=-1;

	for(int i=1;i<=n;i++){
		//cout << i << "  " << frq[i] << "\n";
		if(frq[i]==n-2){
			if(to==-1){
				to=i;
			}else{
				from=i;
			}
		}
	}

	//cout << to << " " << from << "\n";
	


	vector<bool> vis(n+5,false);
	//cout << "&&" << "\n";

	if(hasPath(vis,to,from)){
	//cout << "&&" << "\n";

		cout << from << " " << to << "\n";
	}else{
		cout << to << " " << from << "\n";
	}



	return 0;
}