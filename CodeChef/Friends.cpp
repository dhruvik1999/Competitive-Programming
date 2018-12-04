#include <bits/stdc++.h>
#define ll long long
#define ii pair<double,double>
#define vi vector<int>
#define vii vector<ii>
using namespace std;

bitset<2001> bs[2002];
int main(){
    int n;
    cin >> n;

    char a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
            if(a[i][j]=='1'){
                bs[i][j]=1;
            }else{
                bs[i][j]=0;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && a[i][j]=='0'){
                if((bs[i]&bs[j])!=0){
                        ans++;
                }
            }
        }
    }
    cout << ans << "\n";


    return 0;
}
