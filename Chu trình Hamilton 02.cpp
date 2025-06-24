#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, s;
vector <int> ke[10005];
bool visited[10005];
vector <int> temp;
vector <vector <int>> res;
void nhap(){
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
}
void DFS(int u, int cnt){
    temp.push_back(u);
    visited[u] = true;
    if(cnt == n){
        for(auto x : ke[u]){
            if(x == s){
                temp.push_back(x);
                res.push_back(temp);
                temp.pop_back();
                break;
            }
        }
    }
    else{
        for(auto v : ke[u]){
            if(!visited[v]){
                DFS(v, cnt + 1);
            }
        }
    }
    temp.pop_back();
    visited[u] = false;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    nhap();
    DFS(s, 1);
    cout << res.size() << endl;
    for(auto x : res){
        for(auto it : x){
            cout << it << " "; 
        }
        cout << endl;
    }
}
