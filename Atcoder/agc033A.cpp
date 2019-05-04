#include<bits/stdc++.h>

using namespace std;

#define ma 1000000007
#define ll long long

bool isPos(int i,int j,int n,int m){
	if(i>=0 && j>=0 && i<n && j<m)
		return true;
	return false;
}

int main(){
	int n,m;
	cin >> n >> m;

	int a[n][m];
	char t;
	queue< pair<int,int> > q;

	bool vis[n][m];

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> t;

			vis[i][j]=false;

			if(t=='#'){
				a[i][j]=0;
				q.push(make_pair(i,j));
				vis[i][j]=true;
			}else{
				a[i][j]=10000;
			}
		}
	}

	pair<int,int> temp;
	int i,j;


	while(q.size()!=0){
		temp = q.front();
		q.pop();
		//cout << temp.first << " " << temp.second << "\n";

		i = temp.first;
		j = temp.second;

		//cout<< i << " " << j << "\n";

		

		if(isPos(i-1,j,n,m) && vis[i-1][j]==false){
			a[i-1][j] = min(a[i-1][j],a[i][j]+1);
			vis[i-1][j]=true;
			q.push(make_pair(i-1,j));
		}
		if(isPos(i,j-1,n,m) && vis[i][j-1]==false){
			a[i][j-1] = min(a[i][j-1],a[i][j]+1);
			vis[i][j-1]=true;

			q.push(make_pair(i,j-1));
		}
		if(isPos(i+1,j,n,m)&& vis[i+1][j]==false){
			a[i+1][j] = min(a[i+1][j],a[i][j]+1);
			vis[i+1][j]=true;

			q.push(make_pair(i+1,j));
		}
		if(isPos(i,j+1,n,m)&& vis[i][j+1]==false){
			a[i][j+1] = min(a[i][j+1],a[i][j]+1);
			vis[i][j+1]=true;

			q.push(make_pair(i,j+1));
		}
	}
	int ans =  0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans = max(ans,a[i][j]);
			//cout << a[i][j] << " ";
		}
		//cout << "\n";
	}
	cout << ans << "\n";






	return 0;
}