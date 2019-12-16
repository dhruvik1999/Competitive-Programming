#include<bits/stdc++.h>
using namespace std;

int main(){
	int k,n;
	cin >> k >> n;

	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int s4=0,s2=0;
	s4 = k;
	s2 = k*2;

	int t = 0,t2=0,t1=0;
	for(int i=0;i<n;i++){
		if( a[i]%4==0 ){
			t+=a[i]/4;
			a[i]=0;
		}else if( a[i]%4==3 ){
			t+=a[i]/4;
			a[i]=0;
			t++;
		}else{
			t+=a[i]/4;
			a[i]=a[i]%4;
			if(a[i]==1){
				t1++;
			}else{
				t2++;
			}
		}
	}

	if( t<=s4 ){
		s4-=t;
		t=0;
	}else{
		t-=s4;
		s4=0;
		s2-=2*t;
	}

	if( t2<= s2 ){
		s2-=t2;
		t2=0;
	}else{
		t2-=s2;
		s2=0;
	}

	int ef2=s4;
	if(t2>0){
		if(t2<=ef2){
			ef2-=t2;
			t2=0;
		}else{
			t2-=ef2;
			ef2=0;
		}
	}
	ef2=ef2+s4+s2;
	if(t2>=0){
		if( t2<=s4/2 ){
			ef2-=2*t2;
			t2=0;
		}else{
			cout << "NO" << "\n";
			return 0;
		}
	}

	if(ef2>=t1 && t2==0){
		cout  << "YES" << "\n";
	}else{
		cout << "NO" << "\n";
	}




	return 0;
}