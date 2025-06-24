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
        cout << n << " " << v.size() << endl;
        for(auto x : v){
            cout << x.first << " " << x.second << endl;
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
