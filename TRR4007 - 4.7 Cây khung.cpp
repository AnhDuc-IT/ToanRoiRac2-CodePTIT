#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair <int, int>
#define iii pair <pair <int,int>>
void File(){
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
}
int n, m, sz[10005], parent[10005];
struct edge{
    int x, y, w, index;
};
vector <edge> e;
void nhap(){
    cin >> n >> m;
    for(int i = 0; i < m;i++){
        int x, y, w; cin >> x >> y >> w;
        edge temp = edge{x, y, w, i};
        e.push_back(temp);
    }
}
void ktao(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}
int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}
bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}
void solve(){
    vector <edge> res;
    ll d = 0;
    sort(begin(e), end(e), [](edge a, edge b) -> bool{
        if(a.w == b.w) return a.index < b.index;
        return a.w < b.w;
    });
    for(auto it : e){
        if(res.size() == n - 1) break;
        auto u = it.x, v = it.y, z = it.w;
        if(Union(u, v)){
            d += z;
            res.push_back(it);
        }
    }
    if(res.size() == n - 1){
        cout << d << endl;
        for(auto x : res){
            cout << x.x << " " << x.y << " " << x.w << endl;
        }
    }
    else cout << 0 << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    File();
    nhap();
    ktao();
    solve();
}
