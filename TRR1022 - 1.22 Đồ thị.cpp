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
set <iii> adj;
int n, t, m, in_de[1005], out_de[1005];
    vector <vector<int>> a(100 + 1, vector<int>(100 + 1, 1e4));
void nhap(){
    cin >> t >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        a[x][y] = w;
        in_de[y]++;
        out_de[x]++;
    }
}
void solve(){
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << in_de[i] << " " << out_de[i] << endl;
        }
    }
    else{
        cout << n << endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) cout << 0 << " ";
                else cout << a[i][j] << " ";
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
