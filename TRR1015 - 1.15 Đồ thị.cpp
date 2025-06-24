#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
using ii = pair <int,int>;
int n, m, t;
set <ii> se;
vector <ii> v;
int indegree[10005];
int outdegree[10005];
void nhap(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        indegree[y]++;
        outdegree[x]++;
        se.insert({x, y});
    }
    for(auto x : se){
        v.push_back({x.first, x.second});
    }
}
void solve(){
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << indegree[i] << " " << outdegree[i] << endl;
        }
    }
    else{
        int dem = v.size();
        cout << n << endl;
        int a[n + 1][n + 1];
        memset(a, 0, sizeof(a));
        for(auto it : v){
            int x = it.first;
            int y = it.second;
            a[x][y] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t;
    nhap();
    solve();
}
