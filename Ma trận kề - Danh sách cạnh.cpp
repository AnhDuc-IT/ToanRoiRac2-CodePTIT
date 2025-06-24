#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ii pair <int, int>
int n, m, s, t;
set <ii> se;
vector <vector<int>> res;
vector <int> tmp;
bool visited[10005];
int ans = 1e9;
int de[10005];
void nhap(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int x; cin >> x;
            if(x){
                de[i]++;
                if(i < j){
                    se.insert({i, j});
                }
                else{
                    se.insert({j, i});
                }
            }
        }
    }
}
void solve(){
    if(t == 1){
        for(int i = 1; i <= n; i++){
            cout << de[i] << " ";
        }
    }
    else{
        cout << n << " " << se.size() << endl;
        for(auto x : se){
            cout << x.first << " " << x.second << endl;
        }
    }
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    nhap();
    solve();
}
