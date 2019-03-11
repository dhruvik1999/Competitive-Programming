#include<bits/stdc++.h>

#define fast1 ios_base::sync_with_stdio(false)
#define fast2 cin.tie(NULL)
#define ll long long

using namespace std;


int main(){

    fast1;
    fast2;

   // cout << "*\n";

    ll n;
    cin >> n;


    vector<ll> a;
    ll l,r;
    vector<ll> L,R;

    for(int i=0;i<n;i++){
            cin >> l >> r;
            a.push_back(l);
            a.push_back(r+1);
            L.push_back(l);
            R.push_back(r);
    }
    a.shrink_to_fit();
    sort(a.begin(),a.end());


    sort(L.begin(),L.end());
    sort(R.begin(),R.end());

    vector<ll> :: iterator itr;

    itr = unique(a.begin(),a.end());
    a.resize(distance(a.begin(),itr));

    map<ll,ll> an;

    for(int i=0;i<a.size()-1;i++){
        an[ (upper_bound(L.begin(),L.end(),a[i])-L.begin())  - (lower_bound(R.begin(),R.end(),a[i])-R.begin()) ] += a[i+1]-a[i];
        //cout << a[i+1]-a[i] << "\n"
       // cout << a[i]  << " " <<  distance(L.begin(),upper_bound(L.begin(),L.end(),a[i]) )  << " " << distance(R.begin(),lower_bound(R.begin(),R.end(),a[i])) << "\n";
       // cout <<an[ upper_bound(L.begin(),L.end(),a[i]) - lower_bound(R.begin(),R.end(),a[i]) + 1 ]<< " ";
    }

    for(int i=1;i<=n;i++){
        cout << an[i] << " ";
    }

    return 0;
}
