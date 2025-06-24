#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair <int, int>
#define iii pair <pair <int,int>>
void File(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
}
int n, t, a[1005][1005], in_de[1005], out_de[1005];
set <ii> adj;
void nhap(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int x; cin >> x;
            out_de[i]++;
            in_de[x]++;
            adj.insert({i, x});
        }
    }
}
void solve(){
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << in_de[i] << " " << out_de[i] << endl;
        }
    }
    else{
        cout << n << " " << adj.size() << endl;
        for(auto x : adj){
            cout << x.first << " " << x.second << endl;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   File();
   cin >> t;
   nhap();
   solve();
}
