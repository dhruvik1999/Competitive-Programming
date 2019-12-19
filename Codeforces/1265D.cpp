#include<bits/stdc++.h>
using namespace std;


vector<int> doWork(int a,int b,int c,int d,int fe){
	vector<int> ans,ans1;
	int n = a+b+c+d;
	map<int,int> mp;
	mp[0]=a;
	mp[1]=b;
	mp[2]=c;
	mp[3]=d;


	if(mp[fe]!=0){
		ans.push_back(fe);
		mp[fe]--;

		for(int i=0;i<n-1;i++){
			if(mp[fe-1]!=0){
				ans.push_back(fe-1);
				mp[fe-1]--;
				fe=fe-1;
			}else if(mp[fe+1]!=0){
				ans.push_back(fe+1);
				mp[fe+1]--;
				fe+=1;
			}else{
				return ans1;
			}
		}

		return ans;

	}

	return ans1;

}


int main(){

	int a,b,c,d;
	cin >> a >> b >> c  >> d;

	vector<int> ans;

	ans = doWork(a,b,c,d,0);
	if(ans.size()!=0){
		cout << "YES" << "\n";
		for(int i=0;i<ans.size();i++){
			cout  << ans[i] << " ";
		}
		cout << "\n";
		return 0;
	}


	ans = doWork(a,b,c,d,1);
	if(ans.size()!=0){
		cout << "YES" << "\n";
		for(int i=0;i<ans.size();i++){
			cout  << ans[i] << " ";
		}
		cout << "\n";
		return 0;
	}
	ans = doWork(a,b,c,d,2);
	if(ans.size()!=0){
		cout << "YES" << "\n";
		for(int i=0;i<ans.size();i++){
			cout  << ans[i] << " ";
		}
		cout << "\n";
		return 0;
	}
	ans = doWork(a,b,c,d,3);
	if(ans.size()!=0){
		cout << "YES" << "\n";
		for(int i=0;i<ans.size();i++){
			cout  << ans[i] << " ";
		}
		cout << "\n";
		return 0;
	}

	cout << "NO" << "\n";


	return 0;
}