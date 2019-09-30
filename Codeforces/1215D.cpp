#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;

	string s;
	cin >> s;

	int sl=0,sr=0,ql=0,qr=0;
	vector<int> a(n+1,-1);
	for(int i=0;i<n;i++){
		if(s[i]!='?'){
			a[i] = (  s[i]-'0' );
			if(i<n/2){
				sl+=a[i];
			}else{
				sr+=a[i];
			}
		}else{
			if(i<n/2){
				ql++;
			}else{
				qr++;
			}
		}
	}

	int t = min(qr,ql);
	qr-=t;
	ql-=t;

	int diff = abs(sl-sr);

	//cout << qr <<  " " << ql << "\n";

	if(qr!=0){
		if(sr>sl){
			cout << "Monocarp" << "\n";
		}else{
			if(  0<= diff && diff <= (qr/2)*9 && 0<=(diff-(qr-qr/2)*9) && (diff-(qr-qr/2)*9)<=(qr/2)*9 ){
				cout << "Bicarp" <<"\n";
			}else{
				cout << "Monocarp" <<"\n";
 			}
		}
	}else{
		if(sl>sr){
			cout << "Monocarp" << "\n";
		}else{
			if(  0<= diff && diff <= (ql/2)*9 && 0<=(diff-(ql-ql/2)*9) && (diff-(ql-ql/2)*9)<=(ql/2)*9 ){
				cout << "Bicarp" <<"\n";
			}else{
				cout << "Monocarp" <<"\n";
 			}
		}
	}



	return 0;
}