#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair <int, int>
#define MOD 1e9 + 7;
void File(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
}
int n, t, de[10005];
set <ii> ke;
vector <ii> adj;
void nhap(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x){
                de[i]++;
                if(i < j){
                    ke.insert({i, j});
                }
                else{
                    ke.insert({j, i});
                }
            }
        }
    }
    for(auto x : ke){
        adj.push_back(x);
    }
}
void solve(){
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << de[i] << " ";
        }
    }
    else{
        int cnt = ke.size();
        int a[n + 1][cnt + 1];
        memset(a, 0, sizeof(a));
        cout << n << " " << cnt << endl;
        for(int i = 0; i < cnt; i++){
            int x = adj[i].first, y = adj[i].second;
            a[x][i + 1] = 1;
            if(x != y){
                a[y][i + 1] = 1;
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= cnt; j++){
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
    cin >> t;
    nhap();
    solve();
}
