#include<bits/stdc++.h>
using namespace std;

int  main(){

	long long  n;
	cin >> n;

	priority_queue<long long > a,b;
	long long  p;

	for(long long  i=0;i<n;i++){
		cin >> p;
		a.push(p);
	}


	for(long long  i=0;i<n;i++){
		cin >> p;
		b.push(p);
	}

	long long  ans1=0,ans2=0;
	while(a.size()!=0 || b.size()!=0){
		if( a.size()==0 ){
			b.pop();
		}else if(b.size()==0){
			ans1+=a.top();
			a.pop();
		}else{
			if( a.top()<b.top() ){
				b.pop();
			}else{
				ans1+=a.top();
				a.pop();
			}
		}

		if( b.size()==0 ){
			a.pop();
		}else if(a.size()==0){
			ans2+=b.top();
			b.pop();
		}else{
			if( b.top()<a.top() ){
				a.pop();
			}else{
				ans2+=b.top();
				b.pop();
			}
		}

	}

	cout << ans1-ans2 << "\n";


	return 0;
}