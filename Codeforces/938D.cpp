#include<bits/stdc++.h>
using namespace std;
vector<long long> dis(200001,INT_MAX);

void dijkstra(vector< pair<long long,long long> > *g,long long n){
    set< pair<long long,long long> > s;

    for(long long i=1;i<=n;i++){
        s.insert( {dis[i],i} );
    }


    while(s.size()!=0){
        pair<long long,long long> p = *s.begin();
        s.erase(s.begin());
        long long u,v,d;
        for(auto itr : g[p.second]){
            u = p.second;
            v = itr.first;
            d = itr.second;

            if( dis[u]+d<dis[v] ){
                s.erase({dis[v],v});
                dis[v]=dis[u]+d;
                s.insert({dis[v],v});
            }

        }

    }
}


int main(){

    long long n,m;
    cin >> n >> m;

    vector< pair<long long,long long> > g[n+1];
    long long a,b,c;
    for(long long i=0;i<m;i++){
        cin >> a  >> b >> c;

        g[a].push_back( make_pair(b,c*2) );
        g[b].push_back( make_pair(a,c*2) );

    }

    for(long long i=1;i<=n;i++){
        cin >> dis[i];
    }

    dijkstra(g,n);

    for(long long i=1;i<=n;i++){
        cout << dis[i] << " ";
    }
    cout << "\n";



    return 0;
}