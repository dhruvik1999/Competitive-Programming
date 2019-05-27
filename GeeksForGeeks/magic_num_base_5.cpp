#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;




	int temp,ans =0 ;
	while(n!=0){

		temp = (int)(log(n)/log(2));
		ans = ans + pow(5,temp+1);
		n=n-pow(2,temp);
		cout << temp << "  " << ans << "\n";
	}

	cout << "ans : " << ans << "\n";



	return 0;
}