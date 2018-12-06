#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,s;
    cin >> n >> s;

    if(s%n==0){
        cout  << s/n << "\n";
    }else{
        cout << s/n+1 << "\n";
    }



    return 0;
}
