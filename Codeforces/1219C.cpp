#include<bits/stdc++.h>
using namespace std;

int main(){

	int l;
	cin >> l;

	string s;
	cin >> s;

	int n = s.length();


	if( n%l==0){

		vector<string> a(n/l,"");


		for(int i=0;i<n;i++){
			a[i/l]+=s[i];
		}

		string temp = *min_element( a.begin(),a.end() );

		bool lock = true;

		for(int i=0;i<temp.size();i++){
			if( temp[i]!='9' ){
				lock = false;
				break;
			}
		}

		if(lock){

			string temp = "1";
			for(int i=1;i<l;i++){
				temp+="0";
			}
			int t = n/l+1;
			string ans = "";
			for(int i=0;i<t;i++){
				ans += temp;
			}

			cout << ans << "\n";
		}else{


				temp = a[0];
				bool lock1 = true;

				for(int i=1;i<a.size();i++){
					if(a[i]<temp){
						lock1 = false;
						break;
					}else if( a[i] > temp ){
						//temp=a[i];
						//lock1 = false;
						break;
					}
				}

				if(lock1){


					int ch = 0;
				for(int i=temp.length()-1;i>=0;i--){
					if(i==temp.length()-1){
						ch= (temp[i]-'0'+1)/10;
						temp[i] = (char)( '0'+(temp[i]-'0'+1)%10);
					}else{
						int jj = (temp[i]-'0'+ch)/10;
						temp[i] = (char)( '0'+(temp[i]-'0'+ch)%10);
						ch=jj;
					}
				}


				for(int i=0;i<n/l;i++){
						cout << temp;
				}
				cout << "\n";


				}else{

					for(int i=0;i<n/l;i++){
						cout << temp;
				}
				cout << "\n";

				}
			

				
			
		}



	}else{
		string temp = "1";
		for(int i=1;i<l;i++){
			temp+="0";
		}
		int t = n/l+1;
		string ans = "";
		for(int i=0;i<t;i++){
			ans += temp;
		}

		cout << ans << "\n";
	}


	return 0;
}