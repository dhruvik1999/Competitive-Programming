#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
int open_tweet(int a[]){
    int n=sizeof(a)/sizeof(a[0]);
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
        string a;
        cin>>a;
        int p;
        if(a==""){
            cin>>p
            if(a[p]==0){
                a[p]++;
            }else{
                a[p]--;
            }
        }else{
            for(int i=0;i<n;i++){
                a[i]=0;
            }
        }
        cout << open_tweet(a) <<"\n";
    }

    return 0;
}