#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod  1000000007
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){

    	string a;
    	cin >> a;

    	int n = a.length();

    	vector<string> s( n+5,  "" );

    	s[0]=a[0];
    	int top=0;

    	for(int i=1;i<n;i++){
    		if( s[top][0]==a[i] ){
    			s[top]=s[top]+a[i];
    		}else{
    			top+=1;
    			s[top]=s[top]+a[i];
    		}
    	}

    	string ans = "";

    	for(int i=0;i<=top;i++){
    		if(s[i].length()%2==1){
    				ans+=s[i][0];
    		
    		}
    	}

    	sort(ans.begin(),ans.end());
    	string fans = "";
    	set<char> se;
    	for(int i=0;i<ans.length();i++){
    		se.insert(ans[i]);
    	}
    	for(auto i : se){
    		fans+=i;
    	}
    	cout << fans << "\n";


    }

	return 0;
}