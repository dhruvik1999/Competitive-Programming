#include<bits/stdc++.h>
using namespace std;

long long findMax(vector<long long> &a){
	long long m = 0,ans;

	for(long long i=0;i<a.size();i++){
		if(a[i]>=m){
			m=a[i];
			ans=i;
		}
	}
	return ans;
}



int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long long n,m;
	cin >> n >> m;

	vector< vector<long long> > a(n , vector<long long>(m));
	vector<long long> sh(n,0),sv(m,0);

	for(long long i=0;i<n;i++){
		for(long long j=0;j<m;j++){
			cin >> a[i][j];
			sh[i]+=a[i][j];
			sv[j]+=a[i][j];
		}
	}

	long long ans = 0;

	long long fans = 0;

	for(int x=0;x<32;x++){
		//ah=sh;
		//av=sv;

	vector<long long> ah (sh);
	vector<long long> av (sv);

		ans = 0;

		for(int i=0;i<4;i++){
			if( (x>>i)&1 ){
		//		cout << 1;
				int ind = findMax(ah);
				ans+=ah[ind];
				ah[ind]=0;

				for(int j=0;j<m;j++){
					if(av[j]!=0)
						av[j]-=a[ind][j];
				}

			}else{
		//		cout << 0;
				int ind = findMax(av);
				ans+=av[ind];
				av[ind]=0;

				for(int j=0;j<n;j++){
					if(ah[j]!=0)
						ah[j]-=a[j][ind];
				}

			}
		}
		//cout << "\n";

		fans = max(fans,ans);

	}

	cout << fans << "\n";




	return 0;
}