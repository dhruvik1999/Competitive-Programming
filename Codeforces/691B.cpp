#include<bits/stdc++.h>
using namespace std;

int main(){

	string a;
	cin >> a;

	bool lock = false;
	int n = a.length();
	for(int i=0;i<a.length();i++){
		lock = false;
		if( a[i]=='A' && a[n-1-i]=='A' ){
			lock = true;
		}

		if( a[i]=='b' && a[n-1-i]=='d' ){
			lock = true;
		}


		if( a[i]=='d' && a[n-1-i]=='b' ){
			lock = true;
		}


		if( a[i]=='H' && a[n-1-i]=='H' ){
			lock = true;
		}
		if( a[i]=='I' && a[n-1-i]=='I' ){
			lock = true;
		}
		if( a[i]=='M' && a[n-1-i]=='M' ){
			lock = true;
		}
		if( a[i]=='O' && a[n-1-i]=='O' ){
			lock = true;
		}
		if( a[i]=='o' && a[n-1-i]=='o' ){
			lock = true;
		}
		if( a[i]=='p' && a[n-1-i]=='q' ){
			lock = true;
		}
		if( a[i]=='q' && a[n-1-i]=='p' ){
			lock = true;
		}
		if( a[i]=='T' && a[n-1-i]=='T' ){
			lock = true;
		}
		if( a[i]=='U' && a[n-1-i]=='U' ){
			lock = true;
		}
		if( a[i]=='V' && a[n-1-i]=='V' ){
			lock = true;
		}
		if( a[i]=='v' && a[n-1-i]=='v' ){
			lock = true;
		}
		if( a[i]=='W' && a[n-1-i]=='W' ){
			lock = true;
		}

		if( a[i]=='w' && a[n-1-i]=='w' ){
			lock = true;
		}
		if( a[i]=='X' && a[n-1-i]=='X' ){
			lock = true;
		}
		if( a[i]=='x' && a[n-1-i]=='x' ){
			lock = true;
		}

		if( a[i]=='Y' && a[n-1-i]=='Y' ){
			lock = true;
		}

		// if( a[i]=='m' && a[n-1-i]=='m' ){
		// 	lock = true;
		// }
		
		if(!lock){
			cout << "NIE" << "\n";
			return 0;
		}
	}
	cout << "TAK" << "\n";

	return 0;
}