#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	vector<double> a;
	double temp;

	for(int i=0;i<n;i++){
		cin >> temp;
		a.push_back(temp);
	}

	sort(a.begin(),a.end());

	double ans = a[0] ;

	for(int i=1;i<n;i++){
		ans = (ans+a[i])/2;
	}

	printf("%0.9f\n",ans);

	return 0;
}