#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
using ii = pair <int,int>;
int n, m, t;
vector <ii> v;
set <ii> se;
int degree[10005];
void nhap(){
        cin >> n;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            for(int j = 1; j <= x; j++){
                int y; cin >> y;
                if(y < i){
                    se.insert({y, i});
                }
                else{
                    se.insert({i, y});
                }
            }
        }
    for(auto x : se){
        v.push_back({x.first, x.second});
        int a = x.first;
        int b = x.second;
        degree[a]++;
        degree[b]++;
}
}
void solve(){
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << degree[i] << " ";
        }
    }
    else{
        cout << n << endl;
        int dem = v.size();
        int a[n + 1][n + 1];
        memset(a, 0, sizeof(a));
        for(int i = 0; i < dem; i++){
            int x = v[i].first;
            int y = v[i].second;
            a[x][y] = 1;
            a[y][x] = 1;
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
