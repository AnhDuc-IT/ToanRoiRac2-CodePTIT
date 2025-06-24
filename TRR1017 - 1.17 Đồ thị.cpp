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
set <ii> adj;
int n, t, m, in_de[1005], out_de[1005];
int a[1005][1005];
void nhap(){
    cin >> t >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        a[x][i + 1] = 1;
        a[y][i + 1] = -1;
        in_de[y]++;
        out_de[x]++;
    }
}
void solve(){
    if(t == 1){
        for(int i = 1; i <= n ;i++){
            cout << in_de[i] << " " << out_de[i] << endl;
        }
    }
    else{
        cout << n << " " << m << endl;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
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
   nhap();
   solve();
}
