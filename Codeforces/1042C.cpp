#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<int> a(n);

	int nz=0,nn=0;
	unordered_set<int> s;
	unordered_set<int> m;


	for(int i=0;i<n;i++){
		cin >> a[i];
		if( a[i]==0 ){
			nz++;
			s.insert( i);
		}else if( a[i]<0 ){
			nn++;
			m.insert( i );
		}
	}

	if(nn%2==0){

		if( nz==0 ){
			for(int i=0;i<n-1;i++){
				cout << 1 << " " << 2+i << " "  << 1 << "\n";
			} 
		}else{
			int ss = *s.begin();
			s.erase( s.begin() );

			for( auto i : s ){
				cout << 1  << " " << i+1 << " " << ss+1 << "\n";
			}
			s.insert(ss);
			if(s.size()!=n)
				cout << 2 << " " << ss+1 << "\n";
			ss=-1;

			for(int i=0;i<n;i++){
				if( s.find( i ) == s.end() ){
					if( ss==-1 ){
						ss = i;
					}else{
						cout << 1 <<  " " << i+1 << " " << ss+1 << "\n";
					}
				}
			}
		}
	}else{

		int ss = 0;
		int sss = INT_MIN;
		if( nz==0 ){
			ss = -1;
			for(int i=0;i<n;i++){
				if(a[i]<0 && sss<=a[i]){
					ss=i;
					sss=a[i];
				}
			}

			cout << 2 << " " << ss+1 << "\n";
			sss=ss;
			ss=-1;
			for(int i=0;i<n;i++){
				if(	i!=sss  ){
					if(ss==-1){
						ss = i;
					}else{
						cout << 1  << " " << i+1 << " " << ss+1 << "\n";
					}
				}
			}

		}else{
			int pn = -1;
			sss=INT_MIN;
			for(int i=0;i<n;i++){
				if(a[i]<0 && sss<=a[i]){
					pn=i;
					sss=a[i];
				}
			}

			ss = *s.begin();
			s.erase( s.begin() );
			for( auto i : s ){
				cout << 1  << " " << i+1 << " " << ss+1 << "\n";
			}
			s.insert(ss);
			
			cout << 1 << " " << pn+1 << " " << ss+1 << "\n";

			if(s.size()!=n-1)
				cout << 2 << " " << ss+1 << "\n";
			

			ss=-1;
			for(int i=0;i<n;i++){
				if(	i!=pn && s.find(i)==s.end() ){
					if(ss==-1){
						ss = i;
					}else{
						cout << 1  << " " << i+1 << " " << ss+1 << "\n";
					}
				}
			}

			
		}

	}


	return 0;
}