    #include<bits/stdc++.h>
    #define pb push_back
    #define f first
    #define s second     
    #define fio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    #define mp make_pair
    #define int long long
    using namespace std;
    const int INF = 1e9;
    const int MAX = 1e5+3;
    int MOD = 1e9+7;
    int n, M;
    int32_t main()
    {
       int n;
       cin>>n;
       vector<int> v;
       int odd = 0, even = 0, ans = 0;
       for(int i=0;i<n;i++)
       {
          int x;
          cin>>x;
          v.pb(x);
          if(x != 0){
             if(x%2)
                odd++;
             else even++;
          }
       }
       if(n == 1)
       {
          cout<<0;
          return 0;
       }
       for(int i=1;i<n;i++)
       {
          if(v[i] != 0 && v[i-1] != 0)
          {
             if(v[i]%2 != v[i-1]%2)
                ans++;
          }
       }
       odd = (n+1)/2-odd;
       even = n/2-even;
       int stp = -1, edp = -1, beg=0, ed=n-1;
       while(beg < n && v[beg] == 0)
          beg++;
       while(ed >= 0 && v[ed] == 0)
          ed--;
     
       if(beg > ed)
       {
          cout<<1;
          return 0;
       }
       if(beg != 0)
       {
          if(v[beg]%2 == 0)
             stp = 0;
          else stp = 1;
       }
       if(ed != n-1)
       {
          if(v[ed]%2 == 0)
             edp = 0;
          else edp = 1;
       }
       int cnt = 0;
       int prev;
       if(v[beg]%2 == 0)
          prev = 0;
       else prev = 1;
       vector<int> oi, ei;
       for(int i=beg+1;i<=ed;i++)
       {
          if(v[i] == 0)
             cnt++;
          else
          {
             if(cnt > 0){
                int curr;
                if(v[i]%2 == 0)
                   curr = 0;
                else curr = 1;
                if(curr != prev)
                   ans++;
                else
                {
                   if(curr == 0 && prev == 0)
                      ei.pb(cnt);
                   if(curr == 1 && prev == 1)
                      oi.pb(cnt);
                }
                prev = curr;
                cnt = 0;
             }
          }  
       }
       sort(oi.begin(), oi.end());
       sort(ei.begin(), ei.end());
       for(int i=0;i<oi.size();i++)
       {
          if(odd >= oi[i])
             odd -= oi[i];
          else
          {
             if(odd == 0)
                ans+=2;
             else
             {
                ans++;
                odd = 0;
             }
          }
       }
       for(int i=0;i<ei.size();i++)
       {
          if(even >= ei[i])
             even -= ei[i];
          else
          {
             if(even== 0)
                ans+=2;
             else
             {
                ans++;
                even = 0;
             }
          }
       }
     
       if(stp == edp)
       {
          if(stp == 0)
          {
             int mn = min(beg, n-1-ed);
             int mx = max(beg, n-1-ed);
             if(mn <= even){
                even -= mn;
                if(mx > even)
                   ans++;
             }
             else
                ans += 2;
          }
          if(stp == 1)
          {
             int mn = min(beg, n-1-ed);
             int mx = max(beg, n-1-ed);
             if(mn <= odd){
                odd -= mn;
                if(mx > odd)
                   ans++;
             }
             else
                ans += 2;
          }
       }
       else
       {
          if(stp == 1)
          {
             if(odd < beg)
                ans++;
             if(edp == 0){
             if(n-1-ed > even)
                ans++;
             }
          }
          else if(stp == 0)
          {
             if(even < beg)
                ans++;
             if(edp == 1){
             if(n-1-ed > odd)
                ans++;
             }
          }
          else
          {
             if(edp == 1)
             {
                if(n-1-ed > odd)
                   ans++;
             }
             if(edp == 0)
             {
                 if(n-1-ed > even)
                   ans++;
             }
          }
     
       }
     
       cout<<ans;
     
    }