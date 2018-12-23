#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define mi map<int,int>
#define mll map<ll,ll>
#define si set<int>
#define sll set<ll>
#define usi unordered_set<int>
#define usll unordered_set<ll>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define F first
#define S second

#define MOD 1000000007
#define maxlen 100005

int main(){
    string s;
    cin >> s;


    int cnt=0;
    vll x;
    ll ans=1;
    x.push_back(0);
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            x[x.size()-1]++;
        }else if(s[i]=='b'){
            if(x[x.size()-1]!=0)
                x.push_back(0);
        }else{

        }
    }

    for(int i=0;i<x.size();i++){
            ans=((ans%MOD)*((1+x[i])%MOD))%MOD;
    }

    cout << (ans%MOD-1)%MOD<< "\n";



    return 0;
}
