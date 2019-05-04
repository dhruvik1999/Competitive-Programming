#include <bits/stdc++.h>

using namespace std;
	
int main(){

	pair<int,int> pa[8];
	int p,q;
	map <int,int> m;


	for(int i=0;i<8;i++){
		cin >> p >> q;
		pa[i] = make_pair(p,q);
		//s.insert(pa[i]);
		m[p]=q;
	}

	sort(pa,pa+8);
	int m1,m2,n1,n2;
	p = 0, q=7;

	m1 = pa[p].first;
							n1 = pa[p].second;
							m2 = pa[q].first;
							n2 = pa[q].second;
	
			if(pa[p].first+1 < pa[q].first && pa[p].second+1 < pa[q].second){


					if((pa[1].first == m1 )&&
							(pa[2].first == m1 && pa[2].second == n2)&&
							(pa[3].second ==n1 )&&
							(pa[4].second == n2)&&
							(pa[5].first == m2 && pa[5].second == n1)&&
							(pa[6].first == m2) && ( pa[3].first == pa[4].first ) && (pa[1].second == pa[6].second)){
							cout << "respectable" << "\n";
						return 0;

					}

				/*for(int i=pa[p].first+1;i<pa[q].first;i++){
					for(int j=pa[p].second+1;j<pa[q].second;j++){
						
							m1 = pa[p].first;
							n1 = pa[p].second;
							m2 = pa[q].first;
							n2 = pa[q].second;

						if((pa[1].first == m1 && pa[1].second == j )&&
							(pa[2].first == m1 && pa[2].second == n2)&&
							(pa[3].first == i && pa[3].second ==n1 )&&
							(pa[4].first == i && pa[4].second == n2)&&
							(pa[5].first == m2 && pa[5].second == n1)&&
							(pa[6].first == m2 && pa[6].second == j) ) {
							cout << "respectable" << "\n";
						//cout << pa[p].first << " " << pa[p].second << "\n";
						//cout << i << " " << j << "\n";
						//cout << pa[q].first << " " << pa[q].second << "\n";

						return 0;

						}

						
						}
					}*/
				}
			

	
	cout << "ugly" << "\n";

	return 0;
}