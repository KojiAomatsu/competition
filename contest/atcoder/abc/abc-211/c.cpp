#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll mod = 1E9 + 7;
ll dp[10][110000];
map<char, int> dic;

int main() {
  dic['c'] = 0;
  dic['h'] = 1;
  dic['o'] = 2;
  dic['k'] = 3;
  dic['u'] = 4;
  dic['d'] = 5;
  dic['a'] = 6;
  dic['i'] = 7;
  string S;
  cin >> S;

  rep(j, 1, S.size() + 1) {
    char tar = S[j - 1];
    rep(i, 0, 8) { dp[i][j] = dp[i][j - 1]; }

    if (tar == 'c') {
      dp[0][j] += 1;
      continue;
    }
    if (dic[tar] > 0) {
      dp[dic[tar]][j] += dp[dic[tar] - 1][j - 1];
      dp[dic[tar]][j] %= mod;
    }
  }

  ll ans = dp[7][S.size()] % mod;
  cout << ans << endl;
}