#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair <int, int>
#define iii pair<pair <int,int>, int>
#define MOD 1e9 + 7;
void File(){
    freopen("BN.INP", "r", stdin);
    freopen("BN.OUT", "w", stdout);
}
int n, s, t, parent[10005], d[1005];
struct edge{
    int x, y, w;
};
vector <edge> E;
void nhap(){
    cin >> n >> s >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x && x != 1e4){
                edge temp = edge({i, j, x});
                E.push_back(temp);
            }
        }
    }
}
bool Solve(int s){
    fill(d + 1, d + n + 1, 1e9);
    d[s] = 0;
    for(int i = 1; i <= n - 1; i++){
        for(auto e : E){
            int u = e.x, v = e.y, w = e.w;
            if(d[u] < 1e9 && d[v] > d[u] + w){
                d[v] = d[u] + w;
                parent[v] = u;
            }
        }
    }
    for(auto e : E){
        int u = e.x, v = e.y, w = e.w;
        if(d[u] < 1e9 && d[v] > d[u] + w) return false;
    }
    return true;
}
void output(int t){
    int temp = t;
    vector <int> res;
    while(temp != s){
        res.push_back(temp);
        temp = parent[temp];
    }
    res.push_back(temp);
    reverse(begin(res), end(res));
    for(auto x : res){
        cout << x << " ";
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    File();
    nhap();
    if(!Solve(s)) cout << -1 << endl;
    else{
        if(d[t] == 1e9) cout << 0 << endl;
        else{
            cout << d[t] << endl;
            output(t);
        }
    }
}
