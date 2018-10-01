#include <iostream>
#include <vector>
using namespace std;

vector <int>g[10];
bool a[10];

int dfs(int key){
    a[key]=true;
    for(int i=0;i<g[key].size();i++){
        if(a[g[key][i]]==false){
            dfs(g[key][i]);
        }
    }
}

int main(){
    int node,e;
    cin >> node >> e;

    for(int i=0;i<=10;i++){
        a[i]=false;
    }

    for(int i=0;i<e;i++){
        int on,tw;
        cin >> on >> tw;
        g[on].push_back(tw);
        g[tw].push_back(on);

    }
    int counte=0;
    for(int i=0;i<node;i++){
        if(a[i]==false){
            dfs(i);
            counte++;
        }
    }

    cout << counte;

return 0;
}
