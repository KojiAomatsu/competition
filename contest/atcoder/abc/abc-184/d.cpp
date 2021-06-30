#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

double memo[110][110][110];

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  memo[99][99][99] = 1.0;
  rep(i, 1, 300) {
    while (true) {
      int a, b, c;
      a, b = 0;
      c = i;
      memo[99 - a][99 - b][99 - c] = memo[99 - a][99 - b][99 - c];
    }
  }

  printf("%.8f", memo[A][B][C]);
}
