#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const MOD = 1e9 + 7;
using ii = pair <int,int>;
using iii = pair <int, pair<int, int>>;
#define fi first
#define se second
int n, m, a[1005][1005];
stack <int> st;
bool visited[10005];
vector <int> ke[1005];
vector <int> t_ke[1005];
vector <int> adj[1005];
void File(){
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
}
void nhap(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j]){
                ke[i].push_back(j);
                t_ke[j].push_back(i);
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
}
void DFS1(int u){
    visited[u] = true;
    for(auto x : ke[u]){
        if(!visited[x]){
            DFS1(x);
        }
    }
    st.push(u);
}
void DFS2(int u){
    visited[u] = true;
    for(auto x : t_ke[u]){
        if(!visited[x]){
            DFS2(x);
        }
    }
}
void DFS3(int u){
    visited[u] = true;
    for(auto x : adj[u]){
        if(!visited[x]){
            DFS3(x);
        }
    }
}
int solve(){
    int dem = 0;
    for(int i = 1; i <= n;i++){
        if(!visited[i]){
            DFS1(i);
        }
    }
    memset(visited, false, sizeof(visited));
    while(!st.empty()){
        auto it = st.top(); st.pop();
        if(!visited[it]){
            DFS2(it);
            ++dem;
        }
    }
    if(dem == 1) return 1;
    memset(visited, false, sizeof(visited));
    DFS3(1);
    for(int i = 1; i <= n; i++){
        if(!visited[i]) return 0;
    }
    return 2;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    File();
    nhap();
    cout << solve() << endl;
}
