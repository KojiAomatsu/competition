#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll dp[10][1100][10][3]; // i までで j の集合が 合計 k 個で l: connected ?

int main() {
  int N, K;
  cin >> N >> K;
  vector<string> S(N);
  rep(i, 0, N) {
    string si;
    cin >> si;
    S[i] = si;
  }

  rep(i, 0, 8) {
    rep(k, 0, 1 << 8) {
      bool conti = true;
      rep(j, 0, 8) {
        if (k & 1 << j) {
          if (S[i][j] == '#') {
            conti = false;
            break;
          }
        }
      }
      if (conti == false) break;
    }
  }
}