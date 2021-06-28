#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// メビウス関数 エラトステネスの篩 実装例

bool isPrime[1001000];
int mebius[1001000];

int main() {
  ll L, R;
  cin >> L >> R;

  rep(i, 2, R + 1) {
    isPrime[i] = true;
    mebius[i] = 1;
  }
  rep(i, 2, R / 2 + 1) {
    if (!isPrime[i]) {
      continue;
    }

    mebius[i] = -1;
    for (ll j = i * 2; j <= R; j += i) {
      isPrime[j] = false;
      if (j % (i * i) == 0) {
        mebius[j] = 0;
      } else if (mebius[j] != 0) {
        mebius[j] *= -1;
      }
    }
  }

  ll sum = 0;
  rep(i, 2, R) {
    ll num = R / i - (L - 1) / i;
    sum -= mebius[i] * num * (num - 1) / 2;
  }

  rep(i, max(L, 2ll), R / 2 + 1) {
    ll num = R / i - (L - 1) / i;
    if (num > 1) {
      sum -= num - 1;
    }
  }

  cout << sum * 2 << endl;
}
