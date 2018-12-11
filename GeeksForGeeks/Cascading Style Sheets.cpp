#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,p,q,r,s;
    cin >> n>>m;

    map<pair<int,int>,pair<int,int> > mp;

    for(int i=0;i<n;i++){
        cin >> p >> q >> r >> s;
        pair<int,int> pp=make_pair(p,q);

        if(mp.find(pp)!=mp.end()){
            if(mp[pp].second<=s){
               mp[pp]=make_pair(r,s);
            }else{

            }
        }else{
            mp[pp]=make_pair(r,s);
        }

    }

    for(int i=0;i<m;i++){
        cin >> p >> q;
        cout << mp[make_pair(p,q)].first << "\n";
    }


    return 0;
}
