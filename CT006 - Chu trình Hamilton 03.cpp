#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair <int, int>
int n, s;
vector <int> tmp;
vector <vector <int>> res;
vector <ii> adj[10005];
bool visited[10005];
int ans = 1e9;
void nhap(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x && x != 10000){
                adj[i].push_back({j, x});
            }
        }
    }
}
void DFS(int u, int cnt, int sum){
    visited[u] = true;
    tmp.push_back(u);
    if(cnt == n){
        for(auto x : adj[u]){
            if(x.first == s){
                tmp.push_back(s);
                sum += x.second;
                if(sum < ans){
                    ans = sum;
                    if(res.size()){
                        res.pop_back();
                        res.push_back(tmp);
                    }
                    else{
                        res.push_back(tmp);
                    }
                }
                tmp.pop_back();
                sum -= x.second;
            }
        }
    }
    else{
        for(auto v : adj[u]){
            if(!visited[v.first]){
                sum += v.second;
                DFS(v.first, cnt + 1, sum);
                sum -= v.second;
            }
        }
    }
    tmp.pop_back();
    visited[u] = false;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    nhap();
    DFS(s, 1, 0);
    if(ans != 1e9){
        cout << ans << endl;
    }
    else{
        cout << 0 << endl;
    }
    for(auto x : res){
        for(auto it : x){
            cout << it << " ";
        }
        cout << endl;
    }
}
