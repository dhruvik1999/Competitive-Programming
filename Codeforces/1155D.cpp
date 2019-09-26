#include<bits/stdc++.h>
using namespace std;

pair<long long,long long> findMax(vector<long long> &a,long long n){
	long long locmax=0,globmax=0;
	long long st = 0,en=-1,k=0;

	for(long long i=0;i<n;i++){
		if(locmax==0)
			k=i;

		//cout << i << " " << locmax << " " << globmax << "\n";
		//cout << i << " " << st << " " << en << "\n";

		if(locmax+a[i]>=0){
			locmax=locmax+a[i];
		}else{
			locmax=0;
		}

		if(globmax<locmax){
			//cout << "& " << globmax << "\n";
			st=k;
			en=i;
			globmax=locmax;
		}

	}

	//cout << globmax << "\n";
	//cout << st << " " << en << "\n";

	return make_pair(st,en);
}

int main(){

	long long n,x;
	cin >>n >> x;

	vector<long long> a(n),b(n);

	for(long long i=0;i<n;i++){
		cin >> a[i];
		b[i]=-1*a[i];
		//cout << b[i] << " ";
	}
	//cout << "\n";


//	findMax(a,n);
	long long ans = 0;
	if(x>0){
		pair<long long,long long> p = findMax(a,n);
		for(long long i=p.first;i<=p.second;i++){
			ans += a[i]*x;
		}
		cout << ans << "\n";
	}else{
		pair<long long,long long> p = findMax(b,n);
		for(long long i=p.first;i<=p.second;i++){
			a[i]=a[i]*x;
		}
		p = findMax(a,n);
		for(long long i=p.first;i<=p.second;i++){
			ans += a[i];
		}
		cout << ans << "\n";
	}




	return 0;
}