#include<bits/stdc++.h>
using namespace std;

int main(){

	int n,k;
	cin >> n >> k;

	string a;
	cin >> a;

	deque<int> l,r;

	int ptr=0,p1=0,p2=0;
	if(a[0]=='0'){
		l.push_back(0);
	}
	for(int i=0;i<n;i++){
		if(a[i]=='1'){
			int j=i;
			for(;j<=n;j++){
				if(j==n || a[j]=='0'){
					l.push_back(j-i);
					break;
				}
			}
			i=j;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]=='0'){
			int j=i;
			for(;j<=n;j++){
				if(j==n || a[j]=='1'){
					r.push_back(j-i);
					break;
				}
			}
			i=j;
		}
	}
	
	int ans = 0;

	l.push_front(0);
	r.push_front(0);

	for(int i=1;i<l.size();i++){
		l[i]=l[i]+l[i-1];
	}
	for(int i=1;i<r.size();i++){
		r[i]=r[i]+r[i-1];
	}

	for(int i=0;i<=k;i++){
		l.push_back( l.back() );
		r.push_back( r.back() );

	}

	for(int i=1;i<=r.size();i++){
		if( i+k-1 < r.size() && i+k<l.size() )
		ans = max( ans , r[i+k-1]-r[i-1] + l[i+k]-l[i-1] );
	}

	cout << ans << "\n";



	return 0;
}