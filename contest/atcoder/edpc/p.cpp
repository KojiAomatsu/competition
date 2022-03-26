#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)
using mint = atcoder::modint1000000007;

mint dp[111000][2]; // 1 black, 0 while
unordered_map<int, vector<int>> edges;

ll dfs(int parent, int i, int black) {
  if (dp[i][black].val()) return dp[i][black].val();
  mint ans = 1;
  for (auto ed : edges[i]) {
    if (ed == parent) continue;
    if (black) {
      ans *= dfs(i, ed, 0);
    } else {
      ans *= (dfs(i, ed, 0) + dfs(i, ed, 1));
    }
  }
  dp[i][black] = ans;
  return ans.val();
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N - 1) {
    ll xi, yi;
    cin >> xi >> yi;
    xi--;
    yi--;
    edges[xi].push_back(yi);
    edges[yi].push_back(xi);
  }

  mint ans = dfs(-1, 0, 0) + dfs(-1, 0, 1);
  cout << ans.val() << endl;
}