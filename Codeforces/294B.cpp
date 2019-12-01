#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> v1,v2;
	int p,q,c1=0,c2=0;

	for(int i=0;i<n;i++){
		cin >> p >> q;
		if(p==1){
			c1++;
			v1.push_back(q);
		}else{
			c2++;
			v2.push_back(q);
		}
	}

	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	int ans = INT_MAX;
	int l,r;
	for(int t1=0;t1<=c1;t1++){
		for(int t2=0;t2<=c2;t2++){
			l=0;
			r=0;
			for(int i=0;i<t1;i++){
				r+=v1[i];
			}

			for(int i=0;i<t2;i++){
				r+=v2[i];
			}

			if( r <= 2*(c2-t2)+(c1-t1) ){
				ans = min(ans , 2*(c2-t2)+(c1-t1));
			}
		}
	}

	cout << ans << "\n";



	return 0;
}