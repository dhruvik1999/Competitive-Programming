#include<bits/stdc++.h>

using namespace std;

int minn(int x,int y){
    if(x>y)
        return y;
    return x;
}

int ans = 0;
int fun(int a[],int n,int ty){
    if(n<=1){

            if(n==1){
                ans = ty;
                return 0;
            }else{
                return 0;
            }
    }


    if(a[n]!=-1)
        return a[n];

    if(n%2==0){
            return (a[n]=fun(a,n/2,ty+1)+1);
    }else{
            return  (a[n]=minn(fun(a,n-1,ty+1),fun(a,n+1,ty+1)) + 1);
    }
}

int main(){
    int t;
    cin >> t;

    int a[100000];
    for(int i=0;i<100000;i++)
        a[i]=-1;

    a[1]=0;

    cout << fun(a,t,0) << "\n";
    //cout << ans << "\n";

    return 0;
}
