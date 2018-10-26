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

int main(){
    int n;
    cin >> n;

    string a,b;
    cin >> a >> b;

    b=b+b;

    int dp[n];
    dp[0]=0;

    int i=1,j=0;
    for(i=1,j=0;i<n;){
        if(a[i]==a[j]){
            dp[i]=j+1;
            i++;
            j++;
        }else{
            if(j==0){
                dp[i]=0;
                i++;
            }else{
                j=dp[j-1];
            }
        }
    }

    int moves=0,ans=0;
    for(i=0,j=0;j<2*n;){
        if(a[i]==b[j]){
            i++;
            j++;

            if(i==n){
                moves=j-n;
                break;
            }else{
                if(i>ans){
                    ans=i;
                    moves=j-i;
                   // cout << moves << "\n";
                }
            }
        }else{
            if(i==0){
                j++;
            }else{
                i=dp[i-1];
            }
        }
    }
    cout << moves << "\n";

    return 0;
}
