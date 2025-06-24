#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, s;
vector <int> ke[10005];
bool visited[10005];
vector <vector <int>> res;
vector <int> tmp;
void nhap(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x){
                ke[i].push_back(j);
            }
        }
    }
}
void DFS(int u, int cnt){
    visited[u] = true;
    tmp.push_back(u);
    if(cnt == n){
        for(auto x : ke[u]){
            if(x == s){
                tmp.push_back(s);
                res.push_back(tmp);
                tmp.pop_back();
                break;
            }
        }
    }
    else{
        for(auto x : ke[u]){
            if(!visited[x]){
                DFS(x, cnt + 1);
            }
        }
    }
    tmp.pop_back();
    visited[u] = false;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
     freopen("CT.INP", "r", stdin);
     freopen("CT.OUT", "w", stdout);
    nhap();
    DFS(s, 1);
    for(auto x : res){
        for(auto it : x){
            cout << it << " ";
        }
        cout << endl;
    }
    cout << res.size() << endl;
}
