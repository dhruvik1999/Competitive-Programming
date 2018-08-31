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
        cin >> n;
        long long int t,sum=0,sum1=0;
        for(int i=0;i<n;i++){
            cin >> t;
            sum+=t;
            if(t>0)
            sum1+=t-1;
        }
        if(sum1<100 && 100<=sum){
                cout <<"YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
return 0;
}
