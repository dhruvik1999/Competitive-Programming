#include<bits/stdc++.h>
using namespace std;

string ev(string s,int n){
	
	queue<char> q;
	string ans = "";
	for(int i=0;i<n;i++){
		if( (s[i]-'0')%2==0 ){
			q.push(s[i]);
		}else{
			bool lock = true;
			while( q.size()!=0 ){
				if( q.front()>s[i] ){
					lock = false;
					ans+=s[i];
					break;
				}else{
					ans+=q.front();
					q.pop();
				}
			}
			if(lock){
				ans+=s[i];	
			}
		}
	}

	while(q.size()!=0){
		ans+=q.front();
		q.pop();
	}

	return ans;
}

string od(string s,int n){
	
	queue<char> q;
	string ans = "";
	for(int i=0;i<n;i++){
		if( (s[i]-'0')%2!=0 ){
			q.push(s[i]);
		}else{
			bool lock = true;
			while( q.size()!=0 ){
				if( q.front()>s[i] ){
					lock = false;
					ans+=s[i];
					break;
				}else{
					ans+=q.front();
					q.pop();
				}
			}
			if(lock){
				ans+=s[i];	
			}
		}
	}

	while(q.size()!=0){
		ans+=q.front();
		q.pop();
	}

	return ans;
}


int  main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
    	string s;
    	cin >> s;
    	int n = s.length();
    	vector<string> f(4);

    	f[0] = ev(s,n);
    	f[1] = od(s,n);
    	f[2] = od( f[0] , n );
    	f[3] = ev(f[1],n);

    	//cout << f[0] << " " << f[1] << "\n";

    	sort(f.begin(),f.end());
    	cout << f[0] << "\n";




    }

	
	return 0;
}