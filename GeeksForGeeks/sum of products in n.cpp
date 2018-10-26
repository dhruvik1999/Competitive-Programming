#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    long long int sqsum=0,sum=0;
    vector <int> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
        sum+=v[i];
        sqsum+=v[i]*v[i];
    }

    cout << (sum*sum - sqsum)/2 << "\n";
    return 0;
}