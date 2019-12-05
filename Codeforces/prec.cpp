#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<int> pri(10000,1);

{


if(p!=0){
			while(psum<trg){
				if(trg-psum>=2){
					if( q!=0 ){
						ans.push_back(2);
						q--;
						psum+=2;
					}else{
						ans.push_back(1);
						ans.push_back(1);
						p-=2;
						psum+=2;
					}
				}else{
					if(p!=0){
						ans.push_back(1);
						p--;
						psum+=1;
					}else{
						ans.push_back(2);
						q--;
						psum+=2;
					}
				}
			}
		}else{
			while(psum<trg){
				ans.push_back(2);
				q--;
				psum+=2;
			}
		}
	
}

void doPrimeFactorization(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			ans.push_back(i);
			while(n%i==0)
				n=n/i;
		}
	}
}

void primeJenration(int n){
	for(int i=2;i<10000;i++){
		if( pri[i]==-1 ){
			for(int j=i*i;j<10000;j=j+i){
				pri[j]=-1;
			}	
		}
	}
}

int main(){
	doPrimeFactorization(49*1000*121);
	for( int i : ans ){
		cout << i << "\n";
	}
	pri[2]=1;
	primeJenration(10000);
	return 0;
}