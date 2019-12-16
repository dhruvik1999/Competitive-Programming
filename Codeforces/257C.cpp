#include<bits/stdc++.h>
using namespace std;
#define M_PII 3.14159265358979323846
int main(){

	int n;
	cin >> n;
	//cout << M_PI << "\n";

	vector<double> ang;
	double x,y;

	for(int i=0;i<n;i++){
		cin >> x >> y;
		double ans = atan(y/x);
		if(ans<0)
			ans=ans+2*M_PII;
		ang.push_back( ans );
	}
	
	double q = (*max_element(ang.begin() , ang.end())-*min_element(ang.begin() , ang.end()))*((double)180)/M_PII;
	if( q>180 )
		q-=180;
	printf("%0.9f\n",q);

	return 0;
}