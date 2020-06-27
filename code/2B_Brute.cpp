#include<bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;

#define sz(x) x.size()
#define all(x) x.begin(), x.end()

#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << '=' << a << endl;
    err(++it, args...);
}

#define input() (*istream_iterator<int>(cin))
#define strin() (*istream_iterator<string>(cin))

int main(){
    ios::sync_with_stdio(false);
    int q = input();
    while(q--){
        int n = input();
        vector<int> ans;
        for(int cur = 1; cur < n; ++cur){
            vector<bool> flag(n+1, false);
            int nx = cur, sw = true;
            while(not flag[nx]){
                flag[nx] = true;
                nx += cur;
                if(nx > n) nx %= n;
            }
            for(int i = 1; i <= n; ++i)
                if(not flag[i]) sw = false;
            if(sw) ans.push_back(cur);
        }
        cout << sz(ans) << "\n";
        for(int cur: ans) cout << cur << " ";
        cout << "\n";
    }
    return 0;
}