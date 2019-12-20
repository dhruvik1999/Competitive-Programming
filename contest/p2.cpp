#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mod  1000000007


int  main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){

    	int n;
    	cin >> n;

    	string s;
    	int nz=0,no=0;
    	vector<int> len(n);

    	for(int i=0;i<n;i++){
    		cin >> s;

    		len[i]=s.length();
    		for(int j=0;j<s.length();j++){
    			if(s[j]=='0'){
    				nz++;
    			}else{
    				no++;
    			}
    		}
    	}

    	int ans = 0;
    	sort(len.begin(),len.end());
    	int y=0;
    	for(int i=0;i<n;i++){
    		if( len[i]%2!=0 ){
    			y++;
    			continue;
    		}
    		if(len[i]<=nz){
    			ans++;
    			nz-=len[i];
    		}else if(len[i]<=no){
    			ans++;
    			no-=len[i];
    		}else{
    			int t1=nz,t2=no;
    			t1=t1-t1%2;
    			t2=t2-t2%2;
    			
    			if( t1+t2>=len[i] ){
    				nz-= (t1);
    				no-= (len[i]-t1); 
    				ans++;
    			}
    		}
    	}

    	cout << ans+y << "\n";


    }

   
    return 0;
}
