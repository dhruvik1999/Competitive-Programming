#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int open_tweet(int a[],int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            count++;
        }
    }
    return count;
}
int main(){

    int n,m;
    cin>>n>>m;
    int a[n]={0};
    while(m--){
        string aa;
        cin>>aa;
        int p;
        if(aa=="CLICK"){
            cin>>p;
            if(a[p-1]==0){
                a[p-1]++;
            }else{
                a[p-1]--;
            }
            cout << open_tweet(a,sizeof(a)/sizeof(a[0])) <<"\n";
        }else{
            for(int i=0;i<n;i++){
                a[i]=0;
            }
            cout << 0 <<"\n";
        }

    }

    return 0;
}
