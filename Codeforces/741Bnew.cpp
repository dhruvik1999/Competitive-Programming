#include<bits/stdc++.h>
using namespace std;

int findSet(int i,int *a){
	if(a[i]!=i){		
		a[i] = findSet(a[i],a);
		return a[i];
	}
	return a[i];
}

void uni(int i,int j,int *a){
	int l = findSet(i,a);
	int r = findSet(j,a);
	if(l!=r){
		a[l]=r;
	}
}

int dp[1005][1005];


int knap(vector< pair<float, pair<int, pair<int,int> > > > &vec,int w,int n,map<int,bool>&ma){

	cout << w << " " << n << " \n";
	if(n<0 || w<=0)
		return 0;

	if(dp[n][w]!=-1)
		return dp[n][w];

	if(vec[n].second.second.first > w)
		return ( dp[n][w] = knap(vec,w,n-1,ma) );
	else
		return ( dp[n][w] = max( knap(vec,w,n-1,ma) , vec[n].second.second.second + knap(vec,w-vec[n].second.second.first,n-1,ma)) );
}



int main(){
	int a[10005];

	for(int i=0;i<10005;i++){
		a[i]=i;
	}

	map <int,bool> ma;

	for(int i=0;i<1005;i++){
		for(int j=0;j<1005;j++){
			dp[i][j]=-1;
		}
	}

	int n,m,w;
	cin >> n >> m >> w;

	vector<int> f(n),g(n);
	for(int i=0;i<n;i++){
		cin >> f[i];
	}

	for(int i=0;i<n;i++){
		cin >> g[i];
	}

	vector< pair<int,int> > graph(m);
	int p,q;

	for(int i=0;i<m;i++){
		cin >> p >> q;
		graph[i] = make_pair(p,q);
		//cout << "("  << p << " " << q << ")";
		uni(p,q,a);
	}

	vector< pair<float, pair<int, pair<int,int> > > > vec;

	for(int i=0;i<n;i++){
		vec.push_back(make_pair((float)g[i]/f[i] , make_pair( findSet(i+1,a) , make_pair(f[i],g[i]) )));
	}


	

	vector< pair<int,int> > tr(n+5,make_pair(0,0));
	int cnt[10000]={0};
	for(int i=0;i<n;i++){
		tr[vec[i].second.first] = make_pair(tr[vec[i].second.first].first + vec[i].second.second.first,tr[vec[i].second.first].second + vec[i].second.second.second);
		cnt[vec[i].second.first]++;
	}

	for(int i=1;i<=n;i++){
		//cout << i << " " << tr[i].first << " " << tr[i].second << "\n";
		ma[i]=false;
		if(tr[i].first !=0 && cnt[i]!=0 && cnt[i]!=1)
			vec.push_back(make_pair( (float)tr[i].second/tr[i].first ,  make_pair( i , make_pair( tr[i].first,tr[i].second ) ) ));
	}

	for(int i=0;i<vec.size();i++){
		cout << vec[i].second.first << " " << vec[i].second.second.first << " " << vec[i].second.second.second << "\n";
	}

	cout << knap(vec,w,vec.size()-1,ma) << "\n";

	return 0;
}