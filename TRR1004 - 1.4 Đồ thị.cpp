#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair <int, int>;
#define MOD 1e9 + 7;
vector <int> ke[10005];
int degree[10005];
int dem = 0;
int n, m, t;
void nhap(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }
}
void solve(){
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << degree[i] << " ";
        }
    }
    else{
        int a[n + 1][n + 1];
        cout << n << endl;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++){
            for(auto it : ke[i]){
                a[i][it] = 1;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}
int main(){
    ios :: sync_with_stdio(false);
    cin.tie(0);
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> t;
    nhap();
    solve();
}
