#include<bits/stdc++.h>

using namespace std;

 int BIT[1000005]={0};

long long int read(int* BIT,long long int n,long long int i){
    long long ans=0;
    i++;
    while(i>0){
        ans+=BIT[i];
        i-=i&(-i);
    }

    return ans;
}


void update(int* BIT,long long int n,long long int i,long long int val){
    i++;
    while(i<=n){
        BIT[i]+=val;
        i+=i&(-i);
    }
}


int main(){

    long long int n;
    cin >> n;

    pair<long long int,long long int> mp[n];

    long long int t1,t2;
    for(long long int i=0;i<n;i++){
        cin >> t1 >> t2;
        mp[i]=make_pair(t1,t2);
    }

    sort(mp,mp+n);

    vector<long long int> s;

    for(long long int i=0;i<n;i++){
        s.push_back(mp[i].second);
    }
    sort(s.begin(),s.end());

    map <long long int ,long long int > rec;

    for(long long int i=0;i<n;i++){
        rec[s[i]]=i;
    }

    for(long long int i=0;i<n;i++){
        update(BIT,n,i,1);
    }

    long long int ans=0;





    for(long long int i=0;i<n;i++){
        ans+=read(BIT,n,rec[mp[i].second]-1);
       // cout << ans << "\n";


        update(BIT,n,rec[mp[i].second],-1);

    }

    cout << ans << "\n";




    return 0;
}
