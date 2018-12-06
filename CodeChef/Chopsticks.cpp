#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    int a[n];
    for(int i=0;i<n;i++)
    cin >> a[i];

    sort(a,a+n);

    int ans=0;

    for(int i=0;i<n-1;i++){
        if(a[i+1]-a[i]<=k){
            ans++;
            i++;
        }
    }

    cout << ans << "\n";

    return 0;
}