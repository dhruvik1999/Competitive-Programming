#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        long long int a[n],b[n],c[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        for(int i=0;i<n;i++)
        cin>>b[i];
        int k=0;
        c[0]=a[0];
        if(n>=2)
            k+=2;
        else if(n==1)
        k++;

        for(int i=1;i<n-1;i++)
        {
            if(a[i]-b[i]>c[i-1]){
                c[i]=a[i];
                k++;
            }else if(a[i]+b[i]<a[i+1]){
                c[i]=a[i]+b[i];
                k++;
            }else{
                c[i]=a[i];
            }

        }

        cout << k << "\n";    }


    return 0;
}
