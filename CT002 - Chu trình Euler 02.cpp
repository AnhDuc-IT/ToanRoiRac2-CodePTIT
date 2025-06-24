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
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int x; cin >> x;
                if(x){
                    adj[i].insert(j);
                    degree[i]++;
                }
            }
        }
    }
    else{
        cin >> n >> s;
        for(int i = 1; i<= n; i++){
            for(int j = 1; j <= n; j++){
                int x; cin >> x;
                if(x){
                    adj[i].insert(j);
                    degree[i]++;
                }
            }
        }
    }
}
bool check(){
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
    for(int i = 1; i<= n; i++){
        if(!visited[i]) return false;
    }
    return true;
}
int solve(){
    if(!check()) return false;
    int dem = 0;
    for(int i = 1; i <= n; i++){
        if(degree[i] % 2) ++dem;
    }
    if(dem == 0) return 1;
    if(dem == 2) return 2;
    return 0;
}
void Euler(int s){
    stack<int> st;
    vector <int> res;
    st.push(s);
    while(!st.empty()){
        auto x = st.top();
        if(adj[x].size()){
            auto y = *adj[x].begin();
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
    for(auto x : res) cout << x << " ";
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    nhap();
    if(t == 1){
        cout << solve();
    }
    else{
        Euler(s);
    }
}
