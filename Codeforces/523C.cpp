#include<bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;
const int N=1e6+5;

int n, a[N], cnt[N], ans=0;
int main(){
    cin >> n;
    cnt[0]=1;

    for(int i=0;i<n;i++){
        cin >> a[i];
        vector <int> di;
        for(int j=1;j*j<=a[i];j++){
            if(a[i]%j==0){
                di.push_back(j);
                    if(a[i]/j!=j){
                        di.push_back(a[i]/j);
                    }
            }
        }

        //sort(di.begin(),di.end());
        reverse(di.begin(),di.end());

        for(int j=0;j<di.size();j++){
            cnt[di[j]]+=cnt[di[j]-1];
            cnt[di[j]]%=MOD;

        }
    }

    long long int ans=0;

    for(int i=1;i<=n;i++){
            //cout << cnt[i] << "\n";
        ans+=cnt[i];
        ans%=MOD;
    }

    cout << ans%MOD << "\n";





    return 0;
}
