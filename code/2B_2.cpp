#include<bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;

#define rep(i,k,n) for(int i=(k); i != int(n); ++i)
#define sz(x) x.size()
#define all(x) x.begin(), x.end()

#define dbg(x) cerr << #x << '=' << x << '\n'
#define dbg2(x, y) cerr << #x << '=' << x << ' ' << #y << '=' << y << '\n' 

#define input() (*istream_iterator<int>(cin))
#define strin() (*istream_iterator<string>(cin))

int main(){
    ios::sync_with_stdio(false);
    int q = input();
    while(q--){
        int n = input(), ans = n;
        vector<bool> v(n+1, false);
        v[0] = true;
        ans--;
        for(int i = 2; i <= n; ++i){
            if(v[i]) continue;
            if(n%i == 0){
                for(int j = 1; j*i <= n; ++j){
                    if(v[j*i]) continue;
                    v[j*i] = true;
                    ans--;
                }
            }
        }
        ans = count_if(all(v), [](bool cur){return !cur;});
        cout << ans << '\n';
        for(int i = 1; i < n; ++i) 
            if(not v[i]) cout << i << " ";
        cout << "\n";
    }
    return 0;
}