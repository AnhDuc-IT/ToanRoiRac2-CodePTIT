#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair <int, int>;
#define MOD 1e9 + 7;
set <int> adj[10005];
set <pair <int, int>> ke[10005];
int degree[10005];
int dem = 0;
int n, t;
void nhap(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x == 1){
                adj[i].insert(j);
                adj[j].insert(i);
                degree[i]++;
            }
        }
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
        for(int i = 1; i <= n; i++){
            cout << degree[i] << " ";
            for(auto it : adj[i]){
                cout << it << " ";
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
