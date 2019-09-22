#include<bits/stdc++.h>
using namespace std;

int  main(){
	long long  n;
	cin >> n;

	vector< vector<long long > > a(n , vector<long long >(n,0));
	for(long long  i=0;i<n;i++){
		for(long long  j=0;j<n;j++){
		cin >> a[i][j];

		}
	}

	double numnul = 1;
	numnul = a[0][1];
	numnul*=a[0][2];
	numnul*=a[1][2];
	numnul = sqrt(numnul);
	long long  fa = numnul/a[1][2];

	cout << fa << " ";
	for(long long  i=1;i<n;i++){
		cout << a[0][i]/fa << " ";
	}
	cout << "\n";




	return 0;
}