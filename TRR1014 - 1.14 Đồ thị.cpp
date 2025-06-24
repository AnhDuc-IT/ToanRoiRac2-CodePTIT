#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair <int, int>
#define iii pair<int, pair <int,int>>
#define MOD 1e9 + 7;
void File(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
}
set <ii> adj;
int n, t, in_de[1005], out_de[1005];
void nhap(){
    cin >> t >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x){
                in_de[j]++;
                out_de[i]++;
                adj.insert({i, j});
            }
        }
    }
}
void solve(){
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << in_de[i] << " " << out_de[i] << endl;
        }
    }
    else{
        int m = adj.size();
        int a[n + 1][m + 1];
        memset(a, 0, sizeof(a));
        int dem = 1;
        cout << n << " " << m << endl;
        for(auto x : adj){
            int u = x.first, v = x.second;
            a[u][dem] = 1;
            a[v][dem] = -1;
            dem++;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
  File();
   nhap();
   solve();
}
