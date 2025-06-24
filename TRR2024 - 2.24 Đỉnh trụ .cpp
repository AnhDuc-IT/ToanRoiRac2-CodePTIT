#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
using ii = pair <int,int>;
using iii = pair <int, pair<int, int>>;
#define fi first
#define se second
int n, m, a[1005][1005];
bool visited[10005];
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
void BFS(int u){
    queue <int> q;
    q.push(u);
    while(!q.empty()){
        auto it = q.front(); q.pop();
        for(auto x : ke[it]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
int tplt(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ++cnt;
            BFS(i);
        }
    }
    return cnt;
}
void solve(){
    auto tmp = tplt();
    int dem = 0;
    vector <int> res;
    for(int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        if(tplt() > tmp){
            ++dem;
            res.push_back(i);
        }
    }
    cout << dem << endl;
    if(dem > 0){
        for(auto it : res){
            cout << it << " ";
        }
    }
}
int main()
{
    ios :: sync_with_stdio(false);
    cin.tie(0);
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    nhap();
    solve();
}
