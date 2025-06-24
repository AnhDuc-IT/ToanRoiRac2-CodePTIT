#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair <int, int>
#define MOD 1e9 + 7;
void File(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
}
int n, m, t, de[10005];
vector <ii> ke;
void nhap(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        ke.push_back({x, y});
        de[x]++;
        de[y]++;
    }
}
void solve(){
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << de[i] << ' ';
        }
    }
    else{
        cout << n << " " << m << endl;
        int dem = ke.size();
        vector <vector<int>> a(n + 1, vector <int> (dem + 1, 0));
        for(int i = 0; i < dem; i++){
            int x = ke[i].first, y = ke[i].second;
            a[x][i + 1] = 1;
            if(x != y){
                a[y][i + 1] = 1;
            }
        }
        for(int i = 1; i <= n;i++){
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
    cin >> t;
    nhap();
    solve();
}
