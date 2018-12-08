#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,s;
    cin>> n >> s;
    long long int a[n],ttl=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        ttl+=a[i];
    }

    sort(a,a+n);
    long long int need=a[0],hf=0;

    if(a[0]>1){
        hf=a[0]-1;
    }
    for(int i=0;i<n-1;i++){
        if(a[i+1]-a[i]==0){
            if(hf<=0){
                need++;
            }else{
                hf--;
            }
        }else{
            need+=a[i+1]-a[i];
            if(a[i+1]-a[i]>1)
                hf+=a[i+1]-a[i]-1;
        }
    }

    cout << ttl-need << "\n";




    return 0;
}
