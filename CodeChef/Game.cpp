#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

void res(int a[],char b[],int n,int i,int r[]){
    if(i<0)
        return ;


    if(i==n-1){
        r[i]=a[i];
    }else{
        if(b[i+1]=='F'){
            r[i]=r[i+1]+a[i];
        }else{
            r[i]=r[i+2]+a[i];
        }
    }

    res(a,b,n,i-1,r);
}
int main(){
    int t;
    cin >>t;


    while(t--){
int n;
cin>>n;
int a[n];
char b[n];
int r[n+1]={0};

for(int i=0;i<n;i++)
cin>>a[i];

for(int i=0;i<N;i++)
cin>>b[i];
res(a,b,n,n-1,r);

for(int i=0;i<=n;i++){
    cout << r[i]<<"\n";
}

    }    
}