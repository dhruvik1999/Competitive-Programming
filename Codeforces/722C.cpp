#include<bits/stdc++.h>
using namespace std;


int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin >> n;

	vector<long long> a(n+5),b(n+5);
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int j=1;j<=n;j++){
		cin >> b[j];
	}

	vector<long long> ans1(n+5,0);
	vector< bool > vis(n+5,false);
	vector< long long > temp(n+5,-1);
	unordered_map< int,int > ltor,rtol;

	long long ans = 0;
	for(int j=n;j>0;j--){
		ans1[j] = ans;
		int i = b[j];

		// cout << " " << b[j] << " " << "-------------------" << "\n";
		// for(int ll=1;ll<=n;ll++){
		// 	cout << temp[ll] << " ";
		// }
		// cout << "\n";

		if(1<i && i<n){

			if(temp[i-1]==-1 && temp[i+1]==-1){
				temp[i]=a[i];
				ans = max(ans , temp[i]);
				ltor[i]=i;
				rtol[i]=i;
			}else if(temp[i-1]==-1 && temp[i+1]!=-1){
				temp[i] = a[i] + max(temp[i+1] , temp[ ltor[i+1] ]);
				ans = max(ans , temp[i]);

				rtol[ ltor[i+1] ] = i;
				ltor[i]=ltor[i+1];
			}else if(temp[i-1]!=-1 && temp[i+1]==-1){
				temp[i] = a[i] + max( temp[i-1] , temp[ rtol[i-1] ] );
				ans = max(ans , temp[i]);

				ltor[ rtol[i-1] ] = i;
				rtol[i] = rtol[i-1];
			}else{
				temp[i] = a[i] + max(temp[i+1] , temp[ ltor[i+1] ]) + max( temp[i-1] , temp[ rtol[i-1] ] );
				ans = max(ans , temp[i]);

				temp[ rtol[i-1] ] = temp[i];
				temp[ ltor[i+1] ] = temp[i];

				ltor[ rtol[i-1] ] = ltor[i+1];
				rtol[ ltor[i+1] ] = rtol[i-1];
			}
		}else if(i==1){
			if( temp[i+1]==-1 ){
				temp[i]=a[i];
				ans = max(ans , temp[i]);

				ltor[i]=i;
				rtol[i]=i;
			}else{
				temp[i] = a[i] + max( temp[i+1] , temp[ ltor[i+1] ] );
				ans = max(ans , temp[i]);

				rtol[ ltor[i+1] ]=i;
				ltor[i]=ltor[i+1];
			}
		}else{
			if(temp[i-1]==-1){
				temp[i]=a[i];
				ans = max(ans , temp[i]);

				ltor[i]=i;
				rtol[i]=i;
			}else{
				temp[i] = a[i] + max( temp[i-1] , temp[ rtol[i-1] ] );
				ans = max(ans , temp[i]);

				ltor[ rtol[i-1] ] = i;
				rtol[ i ] = rtol[ i-1 ];
			}
		}

		// for(int ll=1;ll<=n;ll++){
		// 	cout  << temp[ll] << " "; 
		// }
		// cout  << "\n";

	}
	
	for(int i=1;i<=n;i++){
		cout << ans1[i] << "\n";
	}

	return 0;
}