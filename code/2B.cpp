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
    //freopen("20.in", "r", stdin);
    // freopen("20(1) .sol", "w", stdout);
    int q = input();
    while(q--){
        int n = input();
        vector<int> ans;
        for(int i = 1; i < n; ++i)
            if(__gcd(i, n) == 1) ans.push_back(i);
        cout << sz(ans) << "\n";
        for(int cur: ans) cout << cur << " ";
        cout << "\n";  
    }
    return 0;
}