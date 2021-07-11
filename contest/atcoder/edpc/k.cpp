#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

bool dp[110000]; // winfirst?

int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, 0, N) { cin >> A[i]; }
  rep(i, 1, K + 1) {
    bool isWinSecond = false;
    rep(j, 0, N) {
      if (i - A[j] >= 0) {
        if (!dp[i - A[j]]) isWinSecond = true;
      }
    }
    dp[i] = isWinSecond;
  }
  cout << (dp[K] ? "First" : "Second") << endl;
}