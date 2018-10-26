#include<bits/stdc++.h>

using namespace std;

long long int digsum(long long int x){
    long long int ans = 0;

    while(x){
        ans+=x%10;
        x=x/10;
    }
    return ans;
}

long long int ans =100000000000000,move=0;
void fun(long long int a , long long int b,int ty){
    
    if(a < ans){
        ans=a;
        move=ty;
    }
    
    if(ty>13){
        return;
    }

    fun(a+b,b,ty+1);
    fun(digsum(a),b,ty+1);
}



int main(){
    int t;
    cin >> t;

    while(t--){
        long long int a , b;
        cin >> a >> b;
        ans =100000000000000,move=0;
        fun(a,b,0);
        cout << ans << " "<< move << "\n";
    }


    return 0;
}