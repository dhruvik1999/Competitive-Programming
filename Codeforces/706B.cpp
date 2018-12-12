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
    int n,dp[maxlen]={0},temp;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> temp;
        dp[temp]++;
    }
    int pt=0;
    for(int i=0;i<maxlen;i++){
        pt+=dp[i];
        dp[i]=pt;
       // cout << dp[i] << " ";
    }
    //cout << "\n";

    int q;
    cin >> q;

    while(q--){
        cin >> temp;
        if(temp>100000){
            cout << n << "\n";
        }else{
            cout << dp[temp] << "\n";
        }

    }



    return 0;
}
