#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair <int, int>
int n, s, t, q;
int parent[1005];
bool visited[1005];
vector <int> res[1005];
void File(){
    freopen("TK.INP", "r" ,stdin);
    freopen("TK.OUT", "w", stdout);
}
int a[1004][1005];
vector <int> ke[10005];
void nhap(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j]){
                ke[i].push_back(j);
            }
        }
    }
}
void DFS(int u, vector <int> &a){
    visited[u] = true;
    a.push_back(u);
    for(auto x : ke[u]){
        if(!visited[x]){
            DFS(x, a);
        }
    }
}
void solve(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++cnt;
            DFS(i, res[cnt]);
            sort(begin(res[cnt]), end(res[cnt]));
        }
    }
    cout << cnt << endl;
    for(int i = 1; i <= cnt; i++){
        for(auto it : res[i]){
            cout << it << " ";
        }
        cout << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    File();
    nhap();
    solve();
}
