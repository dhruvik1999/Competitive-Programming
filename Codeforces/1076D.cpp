#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD 1000000007
#define maxlen 9223372036854775807
#define minlen -9223372036854775807
#define fin(n) for(int i=0;i<n;i++)

int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
vector<int> primeFact(int n){vector<int> ans;for(int t=2;t<=sqrt(n);t++){if(n%t==0){ans.push_back(t);while(n%t==0){n=n/t;}}}if(n>2)ans.push_back(n);return ans;}
vector<int> fact(int n){vector<int> ans;for(int i=1;i<=sqrt(n);i++){if(n%i==0){if( i*i == n ){ans.push_back(i);}else{ans.push_back(i);ans.push_back(n/i);}}}return ans;}
int powerr(int base,int exp,int mod) { if(exp==0)return 1;int t = powerr(base,exp/2,mod)%mod;if(exp%2==0){return (t%mod*t%mod)%mod;}else{return (t%mod*t%mod*base%mod)%mod;}} 
void fastio(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}

vector<int> odr(300001,-1);
vector<int> dis(300001 ,maxlen);
map< pair<int,int> , int > ind;


struct cmp{
	bool operator()(pair<int,int> &a, pair<int,int> &b){
		return a>b;
	}
};

void dij( vector< pair<int,int> > *graph,int n){

	//priority_queue< pair<int,int>  , vector< pair<int,int> > , cmp > pq;
	set< pair<int,int> > pq;
	for(int i=2;i<=n;i++){
		pq.insert( {maxlen,i} );
	}
	pq.insert({0,1});

	dis[1]=0;
	odr[1]=-1;
	//cout  << pq.top().first << " " << pq.top().second << "\n";

	int p,q,r;

	while( pq.size()!=0 ){
		pair<int,int> node = *pq.begin();
		pq.erase( pq.begin() );

		p = node.second;
		//cout << p << "\n";
		for(int i=0;i<graph[ p ].size();i++){
			q = graph[p][i].first;
			r = graph[p][i].second;

			//cout << p << " " << q << " " << r << "\n";

			if( dis[p]+r < dis[q]){
				pq.erase( pq.find( { dis[q] , q } ) );
				//cout << r << " " << dis[p] << "\n";
				dis[q] = r + dis[p];
				odr[q]=p;
				pq.insert( { dis[q] , q } );
			}
		}

	}
}

vector< pair<int,int> > ans;

void dfs( vector<int> *tree, int n, vector<bool> &vis, int node, int par ){
	vis[node] = true;	
	odr.push_back( ind[ {min(node,par) , max(node,par)} ] );

	for(int i=0;i<tree[node].size();i++){
		if( vis[ tree[node][i] ]==false )
			dfs( tree,n,vis,tree[node][i],node );
	}
}


int32_t main(){
	fastio();

	int n,m,k;
	cin >> n >> m >> k;

	vector< pair<int,int> > graph[n+1];
	int p,q,w;

	for(int i=0;i<m;i++){
		cin >> p >> q >> w;
		graph[p].push_back( {q,w} );
		graph[q].push_back( {p,w} );
		ind[ { min(p,q) , max(p,q) } ] = i+1;
	}

	odr[1]=-1;

	dij(graph,n);

	for(int i=0;i<=n;i++){
		graph[i].clear();
	}

	vector<int> tree[n+1];

	for(int i=2;i<=n;i++){
		tree[i].push_back( odr[i] );
		tree[ odr[i] ].push_back(i);
	}

	odr.clear();


	vector<bool> vis(n+10 , false );
	dfs(tree,n,vis,1,-1);

	int tt = odr.size()-1;
	int t = min(k,tt);

	cout << t << "\n";
	for(int i=0;i<t;i++){
		//cout << ind[ {min(ans[i+1].first , ans[i+1].second) , max(ans[i+1].first , ans[i+1].second) } ] << " ";
		cout << odr[i+1] << " ";
	}
	cout << "\n";




	return 0;
}