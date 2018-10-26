#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int n,k;
    cin >> n >> k;

    vector <long long int> a,b,c;
    int temp=0;

    for(int i=0;i<n;i++){
            cin >> temp;
            a.push_back(temp);
    }

    for(int i=0;i<n;i++){
            cin >> temp;
            b.push_back(temp);
    }

    for(int i=0;i<n;i++){
            for(int j=1;j<=a[i];j++){
                c.push_back(j*a[i]);
            }
    }

    sort(c.rbegin(),c.rend());

    if(k<c.size()){
        cout << c[k] << "\n";
    }else{
        cout << 0 << "\n";
    }
    return 0;
}
