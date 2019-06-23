#include<bits/stdc++.h>
using namespace std;

int fect(int n){
    int ans = 1;
    for(int i=2;i<=n;i++){
        ans= ans*i;
    }
    return ans;
}

int findRank(string a) {
    int n = a.length();
    
    char s[n];
    
    for(int i=0;i<n;i++){
        s[i]=a[i];
    }
    sort(s,s+n);
    
    int factor = fect(n-1);
    int ans = 0;

    for(int i=0;i<n;i++){
        
        if(s[i] == a[i]){
            if(i!=n-1)
                factor = factor/(n-i-1);
        }else{
        cout << factor << "\n";
        int j = i+1;
        for(;j<n;j++){
            if( a[i] == s[j] ){
                break;
            }
        }
        char temp;
        while(j>i){
            temp  = s[j];
            s[j] = s[j-1];
            s[j-1] = temp;
            ans = ans + factor;
            j--;
        }


        }
    }
    return ans;
}
int main(){
    string a;
    cin >> a;
    cout << findRank(a) << "\n";
}