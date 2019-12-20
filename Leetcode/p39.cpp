#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > ans;

void doWork( vector<int> &a, int ind,int n,int trg,int sum,vector<int> &temp){
		

	if( trg==sum ){
		ans.push_back(temp);
		return;
	}else if( sum>trg ){
		return;
	}

	for(int i=0;i<n;i++){
		temp.push_back( a[i] );
			doWork(a,i,n,trg,sum+a[i],temp);
		temp.pop_back();
	}

}

int main(){

	int n,trg;
	cin >> n >> trg;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	vector<int> temp;
	doWork(a,0,n,trg,0,temp);

	sort( ans.begin(),ans.end() );
	for(int i=0;i<ans.size();i++){
		sort( ans[i].begin() , ans[i].end() );
	}
	ans.erase( unique( ans.begin() , ans.end() ) , ans.end() );

	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[i].size();j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}