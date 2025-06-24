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
            if(i < y){
                se.insert({i, y});
            }
            else{
                se.insert({y, i});
            }
        }
    }
    for(auto x : se){
        degree[x.first]++;
        degree[x.second]++;
        v.push_back({x.first, x.second});

    }
}
void solve(){
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << degree[i] << " ";
        }
    }
    else{
        m = v.size();
        int a[n + 1][m + 1];
        memset(a, 0, sizeof(a));
        for(int i = 0; i < m; i++){
            int x = v[i].first;
            int y = v[i].second;
            a[x][i + 1] = 1;
            if(x != y){
                a[y][i + 1] = 1;
            }
        }
        cout << n << " " << m << endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
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
    //freopen("DT.INP", "r", stdin);
    //freopen("DT.OUT", "w", stdout);
    cin >> t;
    nhap();
    solve();
}
