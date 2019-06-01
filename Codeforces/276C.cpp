#include<bits/stdc++.h>
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n,q;
	cin >> n >> q;

	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int b[200005];
	memset(b,0,sizeof(b));

	//sort(a,a+n);
	sort( a,a+n , greater<>());

	int l,r;
	for(int i=0;i<q;i++){
		cin >> l >> r;

		b[l]+=1;
		b[r+1]-=1;
	}

	int temp = 0;

	for(int i=1;i<200005;i++){
		temp = temp + b[i];
		b[i] = temp;
	
	}

	//reverse(b,b+200005);

	sort( begin(b) , end(b) , greater<>() );

	//reverse(begin(b),end(b));

	
	int long long ans,t1,t2 = 0;
	for(int i=0;i<n;i++){
		t1 = a[i];
		t2 = b[i];
		ans += t1*t2;
	}

	cout << ans << "\n";



	






	return 0;
}