#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  vector<bool> isPrime(300, true);
  rep(i, 2, 40) {
    rep(j, 2, 200) {
      if (i * j > 205) continue;
      isPrime[i * j] = false;
    }
  }
  bool fl = false;
  rep(i, A, B + 1) {
    // 全部素数にならなければ Takahashi win
    bool allComp = true;
    rep(j, C, D + 1) {
      if (isPrime[i + j]) {
        allComp = false;
      }
    }
    if (allComp) {
      fl = true;
      break;
    }
    // どれか素数になればcontinue
  }
  // Aoki win
  cout << (fl ? "Takahashi" : "Aoki") << endl;
}