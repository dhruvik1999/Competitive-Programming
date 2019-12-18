#include<bits/stdc++.h>
using namespace std;

#define mod 998244353

vector< vector<long long int> > ncr ( 5001 , vector<long long int>(5001,0) );

void cnt(){

	for(int i=0;i<=5000;i++){
		ncr[0][i]=0;
		ncr[i][0]=1;
	}

	for(int i=1;i<=5000;i++){
		for(int j=1;j<=i;j++){
			ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j])%mod;
		}
	}

}



long long int doWork(long long int a,long long int b){
	long long int p = min(a,b);
	b = max(a,b);
	a = p;

	long long int ans = 1;
	vector<long long int> temp(a+1,1), chemp(a+1,1);
	temp[0]=1;

	for(long long int i=1;i<=a;i++ ){
		chemp[i] = (((chemp[i-1]%mod)*(b+1-i)))%mod;
		//cout << ncr[a][i] << " " << chemp[i] << "\n";
		ans = (ans%mod + (ncr[a][i]%mod*(chemp[i]%mod))%mod )%mod;
	}
	//cout << "\n\n";


	return ans%mod;


}


int main(){

	long long int a,b,c;
	cin >> a >> b >> c;
	cnt();

	cout << (doWork(a,b)%mod * doWork(b,c)%mod * doWork(a,c)%mod)%mod << "\n";





	return 0;
}