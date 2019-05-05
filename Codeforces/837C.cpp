#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,a,b;
	cin >> n >> a >> b;

	pair< int , pair<int,int> > rec[n];


	int p,q;
	for(int i=0;i<n;i++){
		cin >> p >> q;
		rec[i] = make_pair(p*q , make_pair(p,q) );
	}

	

	int a1,b1,a2,b2;
			int  ans = 0;


	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			a1 = rec[i].second.first;
			b1 = rec[i].second.second;

			a2 = rec[j].second.first;
			b2 = rec[j].second.second;
			

			if(rec[i].first + rec[j].first <= a*b){
				if( (a-a1 >= a2 && b >= b2 && b>=b1) || ( a>=a2 && b-b1>=b2 && a>=a1) || ( a-b1>=a2 && b>=b2 && b>=a1 ) || ( a >= a2 && b-a1>=b2 && a>=b1) 
					|| (a-a1 >= b2 && b >= a2 && b>=b1) || ( a>=b2 && b-b1>=a2 && a>=a1 ) || ( a-b1>=b2 && b>=a2 && b>=a1 ) || ( a >= b2 && b-a1>=a2 && a>=b1)){

					ans = max(ans,a1*b1+a2*b2);

				}
			}
		}
	}

	cout  << ans << "\n";


	return 0;
}