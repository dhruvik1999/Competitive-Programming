#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,s;
    cin >> n >> s;

    int large[n],small[n];

    if(s==0){
        if(n==1){
            cout << 0 << " " << 0 << "\n";
        }else{
            cout << -1 << " " << -1 << "\n";
        }
    }else{
    if(s<=9*n && s>=1){
        int sum=s;
        for(int i=0;i<n;i++){
            if(sum>=9){
                large[i]=9;
                sum-=9;
            }else if(sum>0 && sum <9){
                large[i]=sum;
            sum=0;
            }else{
                large[i]=0;
            }
        }
        sum=s;
        int memory=0;
      for(int i=n-1;i>=0;i--){
      if(sum>=9){
        small[i]=9;
        sum-=9;
        memory=i;
      }else if(sum>0 && sum<9){
        small[i]=sum;
        sum=0;
        memory=i;
      }else{
        small[i]=0;
      }

      }
      if(small[0]==0){
        small[0]=1;
        small[memory]-=1;
      }

      for(int i=0;i<n;i++){
        cout << small[i];
    }

    cout<< " " ;

    for(int i=0;i<n;i++){
        cout << large[i];
    }

    cout << "\n";

    }else{
        cout << -1 << " " << -1 << "\n";
    }
    }
    return 0;
}
