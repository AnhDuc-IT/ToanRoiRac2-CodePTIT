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
void nhap(){
    cin >> t >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x && x != 10000){
                adj.insert({i, {j, x}});
                in_de[i]++;
                out_de[j]++;
            }
        }
    }
}
void solve(){
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << out_de[i] << " " << in_de[i] << endl;
        }
    }
    else{
        cout << n << " " << adj.size() << endl;
        for(auto x : adj){
            cout << x.first << " " << x.second.first << " " << x.second.second << endl;
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
