#include<bits/stdc++.h>
using namespace std;

bool check(vector< pair<int,int> > a,int k){
	int n = a.size();
	int r = a[0].second;
	for(int i=1;i<n;i++){
		if(i==k)
			continue;
		if(a[i].first<r){
			return false;
		}
		r=max(r,a[i].second);
	}

	return true;
}


int main(){

	int n;
	cin >> n;

	vector < pair<int,int> > a;
	map< pair<int,int> , int > mp;


	int t1,t2;
	for(int i=0;i<n;i++){
		cin >> t1 >> t2;
		a.push_back( make_pair(t1,t2) );
		mp[ a[i] ] = i+1;
	}

	sort(a.begin(),a.end());

	pair<int,int> temp;
	vector<int> ans;

	for(int i=0;i<n;i++){
		temp = a[i];
		if(i==0){
			a[i] = make_pair(-1,-1);
		}else{
			a[i] = a[i-1];
		}

		if(check(a,i)){
			ans.push_back( mp[temp] );
		}

		a[i]=temp;
	}
	sort(ans.begin(),ans.end());
	cout << ans.size() << "\n";
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << " ";
	}
	if(ans.size()!=0)
		cout << "\n";	



	return 0;
}