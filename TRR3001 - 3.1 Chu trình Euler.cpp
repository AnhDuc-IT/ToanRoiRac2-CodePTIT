#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair <int, int>;
#define MOD 1e9 + 7;
set <int> ke[10005];
vector <pair <int, int>> edge;
bool visited[10005];
int degree[10005];
int n, m, t;
void nhap(){
    if(t == 1){
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int x; cin >> x;
                if(x == 1){
                    ke[i].insert(j);
                    degree[i]++;
                }
            }
        }
    }
    else{
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int x; cin >> x;
                if(x == 1){
                    ke[i].insert(j);
                    degree[i]++;
                }
            }
        }
    }
}
bool check(){
    visited[1] = true;
    queue <int> q;
    q.push(1);
    while(!q.empty()){
        auto it = q.front(); q.pop();
        for(auto x : ke[it]){
            if(!visited[x]){
                q.push(x);
                visited[x] = true;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(visited[i] == false) return false;
    }
    return true;
}
int solve(){
    if(check() == false) return 0;
    int dem = 0;
    for(int i = 1; i <= n; i++){
        if(degree[i] % 2 == 1){
            ++dem;
        }
    }
    if(dem == 0){
        return 1;
    }
    else if(dem == 2){
        return 2;
    }
    return 0;
}
void Euler(int s){
    stack <int> st;
    st.push(s);
    vector <int> EC;
    while(!st.empty()){
        int x = st.top();
        if(ke[x].size() != 0){
            int y = *ke[x].begin();
            st.push(y);
            ke[y].erase(x);
            ke[x].erase(y);
        }
        else{
            st.pop();
            EC.push_back(x);
        }
    }
    reverse(begin(EC), end(EC));
    for(auto it : EC){
        cout << it << " ";
    }
}
int main(){
    ios :: sync_with_stdio(false);
    cin.tie(0);
   freopen("CT.INP", "r", stdin);
   freopen("CT.OUT", "w", stdout);
    cin >> t;
    nhap();
    if(t == 1){
        cout << solve() << endl;
    }
    else{
        Euler(m);
    }
}
