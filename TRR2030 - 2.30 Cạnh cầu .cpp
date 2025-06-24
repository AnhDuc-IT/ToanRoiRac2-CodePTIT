#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair <int, int>
#define iii pair <pair <int,int>>
int n;
set <int> ke[1005];
bool visited[1005];
set <ii> adj;
void File(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
}
void nhap(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int  x; cin >> x;
            if(x){
                ke[i].insert(j);
                if(i < j){
                    adj.insert({i, j});
                }
                else{
                    adj.insert({j, i});
                }
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
            }
        }
    }
}
int tplt(){
    int dem = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++dem;
            BFS(i);
        }
    }
    return dem;
}
void solve(){
    auto temp = tplt();
    set <ii> res;
    for(auto x : adj){
        memset(visited, false, sizeof(visited));
        auto u = x.first, v = x.second;
        ke[u].erase(v);
        ke[v].erase(u);
        if(tplt() > temp){
            res.insert({u, v});
        }
        ke[u].insert(v);
        ke[v].insert(u);
    }
    cout << res.size() << endl;
    for(auto x : res){
        cout << x.first << " " << x.second << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    File();
    nhap();
    solve();
}
