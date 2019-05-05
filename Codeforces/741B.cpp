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
	//cout << "---" << i << " " << j << "\n";

	int l = findSet(i,a);
	int r = findSet(j,a);
	//cout << i << " " << l << "\n";
	//cout << j << " " << r << "\n";
	if(l!=r){
		a[l]=r;
	}
}



int main(){

	int a[10005];

	for(int i=0;i<10005;i++){
		a[i]=i;
	}


	int n,m,w;
	cin >> n >> m >> w;
	//cout << n << " " << m << " " << w << "\n";

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

	vector<pair<int, pair<int,int> > > vec;

	for(int i=0;i<n;i++){
		vec.push_back(make_pair((float)g[i]/f[i] , make_pair( findSet(i+1,a) , make_pair(f[i],g[i]) )));
	}


	

	vector< pair<int,int> > tr(n+5,make_pair(0,0));
	int cnt[10000]={0};
	int itr = 0;
	for(int i=0;i<n;i++){
		tr[vec[i].second.first] = make_pair(tr[vec[i].second.first].first + vec[i].second.second.first,tr[vec[i].second.first].second + vec[i].second.second.second);
		cnt[vec[i].second.first]++;
		itr = max(itr,cnt[vec[i].second.first]);
	}

	for(int i=1;i<=n;i++){
		//cout << i << " " << tr[i].first << " " << tr[i].second << "\n";
		if(tr[i].first !=0 && cnt[i]!=0 && cnt[i]!=1)
			vec.push_back(make_pair( (float)tr[i].second/tr[i].first ,  make_pair( i , make_pair( tr[i].first,tr[i].second ) ) ));
	}

	sort(vec.begin(),vec.end());

	//for(int i=0;i<vec.size();i++){
		//	vec.push_back(make_pair((float)g[i]/f[i] , make_pair( findSet(i+1,a) , make_pair(f[i],g[i]) )));
		 	//cout << vec[i].first << " " << vec[i].second.first << " " << vec[i].second.second.first << " " << vec[i].second.second.second << "\n";
	//}

	vector< pair<int,int> > pr(n+5,make_pair(0,0));
	int ans = 0;

	for(int h=0;h<=itr*2;h++){
		for(int i=vec.size()-1;i>=0;i--){
			if(w > 0){
				if(pr[vec[i].second.first]==make_pair(0,0)){
					w = w - vec[i].second.second.first;
					ans = ans + vec[i].second.second.second;
					pr[vec[i].second.first] = make_pair(vec[i].second.second.first,vec[i].second.second.second);
				}else{
					if( w + pr[vec[i].second.first].first >= vec[i].second.second.first && pr[vec[i].second.first].second < vec[i].second.second.second){
						w = w + pr[vec[i].second.first].first - vec[i].second.second.first;
						ans = ans - pr[vec[i].second.first].second + vec[i].second.second.second;
						pr[vec[i].second.first] = make_pair(vec[i].second.second.first,vec[i].second.second.second);
					}
				}
			//	cout << w << " " << ans 	 << "\n";
			}
		}
	}

	cout << ans << "\n";


 

 



	return 0;
}