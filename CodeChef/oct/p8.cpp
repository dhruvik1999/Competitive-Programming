#include<bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2) 
{ 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
    return "0"; 
    vector<int> result(len1 + len2, 0);   
    int i_n1 = 0;  
    int i_n2 = 0; 
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
        i_n2 = 0;              
        for (int j=len2-1; j>=0; j--) 
        { 
            int n2 = num2[j] - '0'; 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
            carry = sum/10; 
            result[i_n1 + i_n2] = sum % 10; 
  
            i_n2++; 
        } 

        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
        i_n1++; 
    } 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--;  
    if (i == -1) 
    return "0"; 
    string s = "";     
    while (i >= 0) 
        s += std::to_string(result[i--]); 
  
    return s; 
} 

string findSum(string str1, string str2) 
{ 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    if (carry) 
        str.push_back(carry+'0'); 
    reverse(str.begin(), str.end()); 
    return str; 
} 


string decVal( string  b,string num ){
	string ans = "0";
	string p = "1";
	for(long long  i=num.length()-1;i>=0;i--){
		//cout << i << " :: " << p  << " " << num[i] << " " << multiply(p,to_string(num[i]-'0'))  << " " << to_string(num[i]) << "\n";
		if('0'<= num[i] && num[i]<='9'){
			ans = findSum(ans ,  multiply(p,to_string(num[i]-'0')));
			//cout << ans << " \n";
		}else{
			ans = findSum(ans ,  multiply(p, to_string(10+num[i]-'A') ));
		}
		p= multiply(p,b) ;
	}

	return ans;
}

int  main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	long long  t;
	cin >> t;

	while(t--){
		long long  n;
		cin >> n;

		vector< pair<long long ,string> > a(n);
		pair<long long ,string> s={-1,"-1"};

		for(long long  i=0;i<n;i++){
			cin >> a[i].first >> a[i].second;
			if(a[i].first!=-1){
				s={ a[i].first , a[i].second };
			
			}
		}
		if(s.first==-1){
			cout << -1 << "\n";
			continue;
		}

		//cout << decVal("36","AAF123") << "\n";

		string check = decVal( to_string(s.first) , s.second );

		bool lock1 = true;
		for(long long  i=0;i<n;i++){

			if(a[i].first==-1){
				bool lock = true;

				int st = 2;
				string lema = a[i].second;
				for(int i=0;i<lema.length();i++){
					if( '0'<= lema[i] && lema[i] <= '9'){
						st = max(st,lema[i]-'0');
					}else{
						st = max( st , 10+(lema[i]-'A') );
					}
				}


				for(long long  j=st;j<=36;j++){
					if(check == decVal(to_string(j),a[i].second)){
						lock = false;
						//cout << " :: " << j << "\n";
						break;
					}
				}
				if(lock){

					cout << -1 << "\n";
					lock1=false;
					break;	
				}
			}else{
				if( check != decVal( to_string(a[i].first) , a[i].second ) ){
					cout << -1 << "\n";
					lock1=false;
					break;
				}
			}
		}
		if(lock1){
			cout << check << "\n";
		}

	}


	return 0;
}