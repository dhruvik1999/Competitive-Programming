#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,k;
	cin >> k >> n;

	int a,b;
	vector< pair<int,int> > g(n);
	for(int i=0;i<n;i++){
		cin >> a >> b;
		g[i] = { min(a,b) , max(a,b) };
	}

	sort( g.begin() , g.end() );

	vector<int> trace( k+10 , 1 );

	int ans = 0;

	for(int i=0;i<n;i++){
		if( trace[ g[i].first ] == 1 || trace[ g[i].second ]==1 ){

			trace[ g[i].first ]=-1;
			trace[ g[i].second ]=-1;
		}else{
			ans++;
		}
	}

	cout << ans << "\n";


	return 0;
}
/*

Prove your self to yourself, not others.

There are two types of people.

     One doesn’t want to change their self, happy with the current situation (  kind of compromising nature )
    Always ready to change ( competitive nature )

Now, why should you have to invest in your self? 

Let’s assume, If someone gave you the options which car you want to buy BMW or MARUTI‌-SUZUKI, you don’t have to pay for any of this.

what should be the answer, definitely BMW right.

Now, think about why you choose BMW? easy because it is one of the best premium car company. 

Now back to the answer, if you have to choose an object which has not that much impact than your life, for that also you choose BMW. But in this question 

*/