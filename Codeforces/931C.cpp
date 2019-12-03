#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;

	cin >> n;

	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		b[i]=a[i];
	}

	sort(a.begin(),a.end());

	int l=0,r=n-1;

	vector<int> ans;
	
	int p=0,q=0;

	while( l<r && a[r]-a[l]==2 ){
		p+=2;
		l++;
		r--;
	}

	sort(b.begin(),b.end());
	b.erase( unique( b.begin() , b.end() ) , b.end() );


	if( b.size()==3 ){
		for(int i=0;i<n;i++){
			if( a[i]==b[1] ){
				q++;
			}
		}
		q=q-q%2;
	}

	if( p>q || b.size()!=3){
		l=0;
		r=n-1;

		while(l<r){
			if( a[r]-a[l]==2 ){

				ans.push_back( (a[r]+a[l])/2 );
				ans.push_back( (a[r]+a[l])/2 );


				l++;
				r--;

			}else{

				for(int i=l;i<=r;i++){
					ans.push_back( a[i] );
				}
				break;
			}
		}

		cout << n-p << "\n";
		for(int i=0;i<n;i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
	}else{

		vector<int> c;
		for(int i=0;i<n;i++){
			if( a[i]==b[0] || a[i]==b[2]){
				ans.push_back(a[i]);
			}else{
				c.push_back( a[i] );
			}
		}

		if( c.size()%2==0 ){
			for(int i=0;i<c.size();i++){
				if( i%2==0 ){
					ans.push_back( c[i]-1 );
				}else{
					ans.push_back( c[i]+1 );
				}
			}
		}else{
			ans.push_back( c[0] );
			for(int i=1;i<c.size();i++){
				if( i%2==0 ){
					ans.push_back( c[i]-1 );
				}else{
					ans.push_back( c[i]+1 );
				}
			}

		}

		cout << n-q << "\n";
		for(int i=0;i<n;i++){
			cout << ans[i] << " ";
		}
		cout << "\n";



	}



	return 0;
}