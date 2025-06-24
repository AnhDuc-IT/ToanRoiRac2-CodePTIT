#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, s;
vector <int> tmp;
vector <vector<int>> res;
vector <int> ke[1005];
bool visited[1005];
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
    tmp.push_back(u);
    visited[u] = true;
    if(cnt == n){
        for(auto x : ke[u]){
            if(x == s){
                tmp.push_back(x);
                res.push_back(tmp);
                tmp.pop_back();
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
    tmp.pop_back();
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
