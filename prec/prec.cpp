#include<bits/stdc++.h>
#include<stdio.h>
#include<math.h>
typedef long long ll;
using namespace std;

    ll sz=1000009;
    ll vis[1000005]={0};
    ll prime[1000005];
    ll digitprime[10000000];
     
    void sieve()
    {
        ll k=sqrt(sz),i,j,m=0,ans,ans1;
        for(i=2;i<=k;i++)
        {
            if(vis[i]==0)
            {
                for(j=i*i;j<=sz;j+=i)
                {
                    vis[j]=1;
                }
            }
        }

        vis[1]=1;
        
        for(i=2;i<=sz;i++){
            if(vis[i]==0){
                prime[m]=i;
                m++;
            }
    	  }
     
    }

ll numdpf(ll n){     
    ll ind=0,pf=prime[ind],ans=0;
     while(pf*pf<=n){
            
            if(n%pf==0) 
                ans++;
            
            while(n%pf==0){
              n=n/pf;
            }

            pf=prime[++ind];
     }

     if(n!=1)
      ans++;
     return ans;
    }
     
    int main()
    {
        ll j,x,b,i,t,n,flag;
           sieve();

           for(int i=0;i<100;i++){
            cout << i << " " << prime[i] << "\n";
           }

          scanf("%lld%lld",&n,&x);
          ll ans=__gcd(n,x);
          ll res=numdpf(ans);
          cout<<res+1<<endl;
          return 0;
     }