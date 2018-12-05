#include<bits/stdc++.h>

using namespace std;

int main(){


int t;
cin >> t;
int n;

while(t--){
    cin >> n;
    if(360%n==0){
        cout << "y ";
    }else{
        cout << "n ";
    }
    if(n<=360){
        cout << "y ";
    }else{
        cout << "n ";
    }

    //laste test case is difficult
    if(n<=26){
        cout << "y\n";
    }else{
        cout << "n\n";
    }
}


    return 0;
}
