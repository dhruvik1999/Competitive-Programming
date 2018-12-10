#include<bits/stdc++.h>

using namespace std;
int dp[100][100];

int f(int *a,int *b,int n,int W,int i,int w){

    cout << i << " " << w << "\n";

    if(w>W || i>=n){
        return (dp[i][w]=0);
    }

    if(b[i]>W-w){
        return (dp[i][w]=f(a,b,n,W,i+1,w));
    }

    return (dp[i][w]=max(a[i]+f(a,b,n,W,i+1,w+b[i]),f(a,b,n,W,i+1,w)));

}



int main(){

    int t;
    cin >> t;

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            dp[i][j]=-1;
        }
    }

    int n,W;
    cin >> n >> W;

    int a[n],b[n];

    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++)
        cin >> b[i];


    cout << f(a,b,n,W,0,0);





    return 0;
}
