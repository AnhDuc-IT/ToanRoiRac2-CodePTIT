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
                if(i < j){
                    ke[i].insert({i, j});
                }
                else{
                    ke[j].insert({j, i});
                }
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
        for(int i = 1; i <= n; i++){
            if(ke[i].size() != 0){
                for(auto it : ke[i]){
                    ++dem;
                }
            }
        }
        cout << n << " " << dem << endl;
        for(int i = 1; i <= n; i++){
            if(ke[i].size() != 0){
                for(auto it : ke[i]){
                    cout << it.first << " " << it.second << endl;
                }
            }
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
