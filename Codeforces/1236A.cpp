#include<bits/stdc++.h>
using namespace std;
     
#define ll long long

int  main(){
   	
   	int t;
   	cin >> t;
   	int a,b,c;

   	while(t--){
   		cin >> a >> b >> c;
   		int ans = 0;

   		ans+= min( b , c/2 )*3;
   		b=b-ans/3;
   		ans+=min( a , b/2 )*3;

   		cout << ans << "\n"; 

   	}


  	return 0;
 
}