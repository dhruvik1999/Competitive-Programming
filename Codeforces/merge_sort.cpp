#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include<unordered_set>
#include <algorithm>
using namespace std;

void merg(int a[],int l,int mid,int r){
int L=mid-l+1;
int R=r-mid;
}
void mergSort(int a[],int l,int r){

if(l<r){
    mid=(l+r)/2;

    mergSort(a,l,mid-1);
    mergSort(a,mid,r);

    merg(a,l,mid,r);
}
}

int main(){
    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    mergSort(a,0,n-1);

    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}