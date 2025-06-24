#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair <int, int>
int n, s, t, q;
int parent[1005];
bool visited[1005];
vector <int> res[1005];
void File(){
    freopen("TK.INP", "r" ,stdin);
    freopen("TK.OUT", "w", stdout);
}
int a[1004][1005];
vector <int> ke[10005];
void nhap(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j]){
                ke[i].push_back(j);
            }
        }
    }
}
void BFS(int u, vector <int> &a){
    queue <int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        auto x = q.front(); q.pop();
        a.push_back(x);
        for(auto v : ke[x]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
            }
        }
    }
}
void solve(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++cnt;
            BFS(i, res[cnt]);
            sort(begin(res[cnt]), end(res[cnt]));
        }
    }
    cout << cnt << endl;
    for(int i = 1; i <= cnt; i++){
        for(auto it : res[i]){
            cout << it << " ";
        }
        cout << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    File();
    nhap();
    solve();
}
