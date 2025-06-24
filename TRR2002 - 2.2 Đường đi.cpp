#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair <int, int>
int n, s, t, q;
int parent[1005];
bool visited[1005];
void File(){
    freopen("TK.INP", "r" ,stdin);
    freopen("TK.OUT", "w", stdout);
}
int a[1004][1005];
vector <int> ke[10005];
void nhap(){
    cin >> n >> s >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j]){
                ke[i].push_back(j);
            }
        }
    }
}
void BFS(int u){
    queue <int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        auto x = q.front(); q.pop();
        for(auto v : ke[x]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
                parent[v] = x;
            }
        }
    }
}
void solve(){
    if(q == 1){
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(a[s][i] && a[i][t]) ++cnt;
        }
        cout << cnt << endl;
    }
    else{
        vector <int> res;
        BFS(s);
        if(!visited[t]){
            cout << 0 << endl;
            return;
        }
        while(s != t){
            res.push_back(t);
            t = parent[t];
        }
        res.push_back(s);
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
    cin >> q;
    nhap();
    solve();
}
