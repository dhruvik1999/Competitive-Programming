#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int p1=-1,p2=-1;

void func(string a,int l,int r,int n){

    for(int i=l;i<=r;i++){
        if(p1==-1 && a[i]!=a[n-i-1]){
            p1=i;
        }

        if(p1!=-1 && a[i]!=a[n-i-1]){
            p2=i;
        }
    }

}


int main(){
    int n,k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ans = 0,t=('z'-'a');

    for(int i=0;i<=(n-1)/2;i++){
    if(abs(s[i]-s[n-i-1])==25){
        ans+=1;
    }else{
        ans +=min(abs(s[i]-s[n-i-1]),26-abs(s[i]-s[n-i-1]));
        }
    }

        if(k<n/2){
            func(s,0,(n-1)/2,n);
        }else{
            func(s,n/2,n-1,n);
        }
k--;
        if(p1==p2 && p2==-1){
            cout << 0 << "\n";
            return 0;
        }else if(p1==p2){
            ans += abs(p1-k);
        }else if(p1 <= k && k<=p2){
            ans+= 2*min(abs(p2-k),abs(p1-k)) + max(abs(p2-k),abs(p1-k));
        }else if(p1 <k && p2<k){
            ans+= k-min(p1,p2);
        }else{
            ans+=max(p1,p2)-k;
        }

    cout << ans<< "\n";

    return 0;
}
