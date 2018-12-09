#include<bits/stdc++.h>

using namespace std;

bitset<100> bset;
int main(){
    int n,m,temp;
    cin >> n;
    vector <int> a;
     for(int i=0;i<n;i++){
        cin >> temp;
        a.push_back(temp);
     }

    cin >> m;

    vector <int> b;
    for(int i=0;i<m;i++)
    {
        cin >> temp;
        b.push_back(temp);
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int> :: iterator itr;

    for(int i=0;i<n;i++){
            itr = find(b.begin(),b.end(),a[i]-1);
            if(itr!=b.end()){
                b.erase(itr);
                continue;
            }

            itr = find(b.begin(),b.end(),a[i]);
            if(itr!=b.end()){
                b.erase(itr);
                continue;
            }


            itr = find(b.begin(),b.end(),a[i]+1);
            if(itr!=b.end()){
                b.erase(itr);
                continue;
            }

    }
    b.shrink_to_fit();

    cout <<m-b.size() << "\n";


    return 0;

}
