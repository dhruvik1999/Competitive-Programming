#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,q;
	cin >> n >> q;

	char a[n];
	int np=0,ns=0;

	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i] == '.'){
			np++;
		}

		if( (i==0 && a[i]=='.') || ( a[i-1]!='.' && a[i]=='.' )){
			ns++;
		}
	}

	//cout << np << " " << ns << "\n";
	int p;
	char ch;
	for(int i=0;i<q;i++){
		cin >> p >> ch;
		p--;

		if(ch != '.'){
			if(a[p]=='.'){
				np--;

				if(p==0 && p+1<n && a[p+1] != '.'){
					ns--;
				}else if(p==n-1 && p-1>=0 && a[p-1] != '.'){
					ns--;
				}
				else if(p!=0 && p!=n-1 && ( a[p-1]=='.' && a[p+1]=='.' ) ){
					ns++;
				}else if(p!=0 && p!=n-1 && a[p-1]!='.' && a[p+1]!='.'){
					ns--;
				}else if(p==0 && p==n-1){
					ns--;
				}


			}
			a[p]=ch;

		}else{
			// if ch is .

			if(a[p]!='.'){
				np++;

				if(p==0 && p+1<n && a[p+1]!='.' ){
					ns++;
				}else if(p==n-1 && p-1>=0 && a[p-1] != '.'){
					ns++;
				}else if(p!=0 && p!=n-1 && (a[p-1]=='.' && a[p+1]=='.')){
					ns--;
				}else if(p!=0 && p!=n-1 && a[p-1]!='.' && a[p+1]!='.'){
					ns++;
				}else if(p==0 && p==n-1){
					ns++;
				}

			}

			a[p]='.';

		}

		//cout << np << " " << ns << " " << np-ns << "\n";
		cout << np-ns << "\n";
	}







	return 0;
}