#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long int n;
        cin >> n;

        long long int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
    cout << n*(n-1)/2 << "\n";

    }
    return 0;
}
