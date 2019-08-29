#include<bits/stdc++.h>
using namespace std;


vector< int > a[1000];
vector< vector< int > > ans;

int numberOfLeaf(int node){

	int ans = 0;

	for(int i=2;i<=node;i++){
		if(a[i].size()==1){
			//cout  << i << "\n";
			ans++;
		}
	}

	return ans;	

}

void findPath(vector<bool> &vis,vector<int> &temp,int d,int node){
	
	if(node==d){
		//temp.push_back(node);
		ans.push_back(temp);
		//temp.pop_back();
		return;
	}

	vis[node]=true;
	temp.push_back(node);
	for(int i=0;i<a[node].size();i++){
			if(vis[ a[node][i] ]==false){
				findPath(vis,temp,d,a[node][i]);
			}
	}
	temp.pop_back();




}


int main(){

	int n;
	cin >> n;


	int t1,t2;


	for(int i=0;i<n-1;i++){
		cin >> t1 >> t2;

		a[t1].push_back(t2);
		a[t2].push_back(t1);

	}

	


	//int l,r;
	//cin >> l >> r;

	
	//0findPath(vis,temp,r,l);

	//cout << "*" << "\n";
	//cout << "Number of leaf : " << numberOfLeaf(n) << "\n";


	int te;
	int s=1;
	for(int i=0;i<numberOfLeaf(n);i++){
		cin >> te;
		vector<int> temp;
		vector<bool> vis(n+10,false);
		findPath(vis,temp,te,s);
		s=te;
	}
	vector<int> u;
		vector<bool> vis(n+10,false);

	findPath(vis,u,1,s);

	//cout << "--------\n";

	vector<int> fans;
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			//cout << ans[i][j] << " ";
			fans.push_back(ans[i][j]);

		}
		//cout  << "\n";
	}

	fans.push_back(1);

	vector< vector<int> > frq(n+10,vector<int>(n+10,0));
	s=1;
	for(int i=0;i<fans.size();i++){
		frq[s][fans[i]]++;
		frq[fans[i]][s]++;

		if(frq[s][fans[i]]>2 || frq[fans[i]][s]>2){
			cout << -1 << "\n";
			return 0;
		}
		s=fans[i];
	}
	//cout << "\n";

	for(int i=0;i<fans.size();i++){
		cout << fans[i] << " ";
	}
	cout << "\n";




}