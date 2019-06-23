#include<bits/stdc++.h>
using namespace std;

void allPerm(string a,string ans,int depth,int n,int count[]){
	if(n==depth){
		cout << ans << "\n";
		return;
	}

	for(int i=0;i<n;i++){
		if(count[a[i]-'a']>0){
			count[a[i]-'a']--;
			allPerm(a,ans+a[i],depth+1,n,count);
			count[a[i]-'a']++;			
		}
	}

}


int main(){
int count[26];

	string a;
	cin >> a;
	int n = a.length();
	for(int i=0;i<26;i++){
		count[i]=0;
	}

	cout << "ok" << "\n";
	cout << a << " " << n << "\n";

	for(int i=0;i<n;i++){
		count[a[i]-'a']++;
	}

	allPerm(a,"",0,n,count);


	return 0;
}