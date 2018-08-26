#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

long long  reduce(long long  a,string b){
    long long  mod=0;
    for(int i=0;i<b.size();i++){
        mod=(mod*10+b[i]-'0')%a;
    }
    return mod;
}

long long  gcd(long long  a,long long  b){
    if(b==0){
        return a;
    }else{
        gcd(b,a%b);
    }
}


int main(){
int t;
cin >> t;

while(t--){
    long long  a,b;
    string b1;

    cin >> a>>b1;
    b=reduce(a,b1);
    cout<<gcd(a,b)<<"\n";



}
return 0;
}
