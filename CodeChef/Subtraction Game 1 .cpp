#include<bits/stdc++.h>
#define ll long long
#define here cout<<"here\n"
#define pb push_back
#define mp make_pair
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define pf printf
#define pfi(x) printf("%d\n",x)
#define pfl(x) printf("%lld\n",x)
using namespace std;

const ll mod = 1e9+7;

const int MAX = 100005;


int mi(int x , int y){
    if(x>y)
        return y;
    return x;
}

int fun(int a,int b){
    if(b==0)
        return a;

    fun(b,a%b);
}
int main(){
//cout << fun(12,10);
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;

        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];

        int ans =fun(a[0],a[1]);
        for(int i=2;i<n;i++){
            ans=fun(ans,a[i]);
        }
        cout << ans << "\n";


    }
    return 0;
}
