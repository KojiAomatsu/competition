#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

double memo[110][110][110];

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  rep(sum, 0, 300) {
    rep(a, 0, 100) {
      rep(b, 0, 100) {
        ll c = sum - a - b;
        if (c > 99 || c < 0) {
          continue;
        }
        if (a != 99) {
          memo[99 - a][99 - b][99 - c] += (double)(99 - a) / (297 - sum) * (1.0 + memo[99 - a + 1][99 - b][99 - c]);
        }
        if (b != 99) {
          memo[99 - a][99 - b][99 - c] += (double)(99 - b) / (297 - sum) * (1.0 + memo[99 - a][99 - b + 1][99 - c]);
        }
        if (c != 99) {
          memo[99 - a][99 - b][99 - c] += (double)(99 - c) / (297 - sum) * (1.0 + memo[99 - a][99 - b][99 - c + 1]);
        }
      }
    }
  }

  printf("%.9f", memo[A][B][C]);
}
