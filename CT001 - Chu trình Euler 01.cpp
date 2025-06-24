#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl "\n"
#define ii pair <int,int>
#define iii pair <pair<int,int>>
int n, m, s, degree[10005], t;
set <int> adj[10005];
bool visited[10005];
void nhap(){
    if(t == 1){
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
            degree[x]++;
            degree[y]++;
        }
    }
    else{
        cin >> n >> m >> s;
        for(int i = 0; i < m; i++){
            int x, y; cin >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
            degree[x]++;
            degree[y]++;
        }
    }
}
bool BFS(){
    queue <int> q;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        auto x = q.front(); q.pop();
        for(auto v : adj[x]){
            if(!visited[v]){
                q.push(v);
                visited[v] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]) return false;
    }
    return true;
}
int solve(){
    if(!BFS()) return 0;
    int dem = 0;
    for(int i = 1; i <= n; i++){
        if(degree[i] % 2) ++dem;
    }
    if(dem == 0) return 1;
    else if(dem != 2) return 2;
    return 0;
}
void Euler(int s){
    stack <int> st;
    st.push(s);
    vector <int> res;
    while(!st.empty()){
        auto x = st.top();
        if(adj[x].size()){
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        }
        else{
            st.pop();
            res.push_back(x);
        }
    }
    reverse(begin(res), end(res));
    for(auto x : res){
        cout << x << " ";
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    nhap();
    if(t == 1){
        cout << solve() << endl;
    }
    else{
        Euler(s);
        cout << endl;
    }
}
