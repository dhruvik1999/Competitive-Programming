#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;

	int n = s.length();
	vector<string> a;
	string temp = "R";

	for(int i=1;i<n;i++){
		if(s[i]=='R' && s[i-1]=='L'){
			a.push_back(temp);
			//temp="R";
			temp="";
		}
		temp = temp + s[i];
		if(i==n-1 && temp!="")
			a.push_back(temp);
	}

	vector<int> ans;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].length();j++){
			if(a[i][j]=='R' && a[i][j+1]=='L'){
				int t1 = a[i].length()/2;
				int t2 = a[i].length()/2;

				if(a[i].length()%2!=0){
					if(j%2==0)
						t1++;
					else
						t2++;
				}
				
				ans.push_back(t1);
				ans.push_back(t2);
				j++;
			}else{
				ans.push_back(0);
			}
		}
	}

	for(int i=0;i<n;i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
}