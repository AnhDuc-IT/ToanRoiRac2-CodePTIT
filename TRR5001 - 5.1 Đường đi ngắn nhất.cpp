#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair <int, int>
#define iii pair <pair <int,int>>
void File(){
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
}
int n, s, t;
vector <ii> ke[10005];
void nhap(){
    cin >> n >> s >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x && x != 10000){
                ke[i].push_back({j, x});
            }
        }
    }
}
void solve(int s){
    int parent[1005];
    vector <int> d(n + 1, 1e9);
    priority_queue <ii, vector<ii>, greater <ii>> q;
    d[s] = 0;
    q.push({0, s});
    while(!q.empty()){
        auto x = q.top(); q.pop();
        auto u = x.second, kc = x.first;
        if(kc > d[u]) continue;
        for(auto it : ke[u]){
            auto v = it.first, diss = it.second;
            if(d[v] > d[u] + diss){
                parent[v] = u;
                d[v] = d[u] + diss;
                q.push({d[v], v});
            }
        }
    }
    if(d[t] != 1e9){
        cout << d[t] << endl;
        vector <int> res;
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
    else cout << 0 << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    File();
    nhap();
    solve(s);
}
