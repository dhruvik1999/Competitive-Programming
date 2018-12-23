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
    int t;
    cin >> t;
    int a[200005];

    int l=20006,r=20005;

    while(t--){
        char ty;
        int n;

        cin >> ty >> n ;

        if(ty=='L'){
            l--;
            a[n]=l;
        }else if(ty=='R'){
            r++;
            a[n]=r;
        }else{
            cout << min(r-a[n],a[n]-l) << "\n";
        }
    }
    return 0;
}
