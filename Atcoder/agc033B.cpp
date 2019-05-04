#include<bits/stdc++.h>
using namespace std;

bool check(int i,int j,int n,int m){
	if(i>=0 && i<n && j>=0 && j<m)
		return false;
	return true;
}


int main(){
	int n,m,l;
	cin >> n >> m >> l;


	int p,q,x,y;
	cin >> x >> y;
	p=x;
	q=y;

	string s1,s2;
	cin >> s1 >> s2;

	for(int i=0;i<l;i++){
		if(s1[i]=='U'){
			p--;
		}

		if(p<=0){
			cout << "NO" << "\n";
		//	cout << "%\n";
			return 0;
		}

		if(s2[i]=='D'){
			if(p<n)
			p++;
		}
		
	}
	p=x;
	q=y;

	for(int i=0;i<l;i++){
		if(s1[i]=='L'){
			q--;
		}


		if(q<=0){
			cout << "NO" << "\n";
		//	cout << "4%\n";

			
			return 0;
		}

		if(s2[i]=='R'){
			if(q<m)
			q++;
		}
	}
	p=x;
	q=y;

	for(int i=0;i<l;i++){
		if(s1[i]=='R'){
			q++;
		}

		if(q>m){
			cout << "NO" << "\n";
		//	cout << "1%\n";
			
			return 0;
		}

		if(s2[i]=='L'){
			if(q>1)
				q--;
		}
		
	}
	p=x;
	q=y;

	for(int i=0;i<l;i++){
		if(s1[i]=='D'){
			p++;
		}

		if(p>n){
			cout << "NO" << "\n";
		//	cout << "22%\n";

			return 0;
		}
		
		if(s2[i]=='U'){
			if(p>1)
				p--;
		}
		
	}

	cout << "YES" << "\n";



	return 0;
}