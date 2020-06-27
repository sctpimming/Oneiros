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

const int mxn = 1e5+10, mxg = 110;
int dp[mxn][mxg], volume[mxn];
int solve(int cur, int g){
    if(cur <= 0) return 0;
    if(dp[cur][g] > 0) return dp[cur][g];
    if(g > 0) return dp[cur][g] = max({volume[cur] + solve(cur-2, g), solve(cur-1, g), volume[cur] + solve(cur-1, g-1)});
    else return dp[cur][g] = max(volume[cur] + solve(cur-2, g), solve(cur-1, g));
}
int main(){
    ios::sync_with_stdio(false);
    int n = input(), g = input();
    for(int i = 1; i <= n; ++i) volume[i] = input();
    cout << solve(n, g); 
    return 0;
}