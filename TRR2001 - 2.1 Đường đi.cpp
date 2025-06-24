#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair <int, int>
int n, t, u, v, parent[1005];
vector <int> adj[10005];
bool visited[10005];
int ans = 1e9, a[105][105];
void File(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
}
void nhap(){
    cin >> n >> u >> v;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j]){
                adj[i].push_back(j);
            }
        }
    }
}
void DFS(int s){
    visited[s] = true;
    for(auto x : adj[s]){
        if(!visited[x]){
            parent[x] = s;
            DFS(x);
        }
    }
}
void solve(){
    if(t == 1){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(a[u][i] && a[i][v]){
                ++cnt;
            }
        }
        cout << cnt << endl;
    }
    else{
        DFS(u);
        if(!visited[v]){
            cout << 0 << endl;
            return;
        }
        vector <int> res;
        while(u != v){
            res.push_back(v);
            v = parent[v];
        }
        res.push_back(v);
        reverse(begin(res), end(res));
        for(auto x : res){
            cout << x << " ";
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    File();
    cin >> t;
    nhap();
    solve();
}
