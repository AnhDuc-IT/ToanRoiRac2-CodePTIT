#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
using ii = pair <int,int>;
int n, m, t;
set <int> se[10005];
int indegree[10005];
int outdegree[10005];
void nhap(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x){
                se[i].insert(j);
                indegree[j]++;
                outdegree[i]++;
            }
        }
    }
}
void solve(){
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << indegree[i] << " " << outdegree[i] << endl;
        }
    }
    else{
        cout << n << endl;
        for(int i = 1; i <= n; i++){
            cout << se[i].size() << " ";
            for(auto x : se[i]){
                cout << x << " ";
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
