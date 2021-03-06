#include <bits/stdc++.h>
using namespace std;

#define int long long

#define MOD 1000000007
#define maxlen 1000005

int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}
vector<int> primeFact(int n){vector<int> ans;for(int t=2;t<=sqrt(n);t++){if(n%t==0){ans.push_back(t);while(n%t==0){n=n/t;}}}if(n>2)ans.push_back(n);return ans;}
vector<int> fact(int n){vector<int> ans;for(int i=1;i<=sqrt(n);i++){if(n%i==0){if( i*i == n ){ans.push_back(i);}else{ans.push_back(i);ans.push_back(n/i);}}}return ans;}
int powerr(int base,int exp,int mod) { if(exp==0)return 1;int t = powerr(base,exp/2,mod)%mod;if(exp%2==0){return (t%mod*t%mod)%mod;}else{return (t%mod*t%mod*base%mod)%mod;}} 
void fastio(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}

int32_t main(){
    fastio();

    int n,m;
    cin >> n >> m;

    vector<string> a(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    vector< vector<char> > ans( n , vector<char>(m,'.')  );

    vector< pair<int,int> > cent;
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if( a[i-1][j-1]=='#' && a[i-1][j]=='#' && a[i-1][j+1]=='#'
            && a[i][j-1]=='#' && a[i][j+1]=='#'
            && a[i+1][j-1]=='#' && a[i+1][j]=='#' && a[i+1][j+1]=='#' ){
                ans[i-1][j-1] = '#' ;
                ans[i-1][j] = '#' ;
                ans[i-1][j+1] = '#' ;
                ans[i][j-1] = '#' ;

                ans[i][j+1] = '#' ;
                ans[i+1][j-1] = '#' ;
                ans[i+1][j] = '#' ;
                ans[i+1][j+1] = '#' ;

            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( a[i][j] != ans[i][j] ){
                cout << "NO" << "\n";
                return 0;
            }
        }
    }

    cout << "YES" <<"\n";




    return 0;
}




