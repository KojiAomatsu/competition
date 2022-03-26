#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll V, A, B, C;
  vector<ll> P(3);
  vector<string> T = {"F", "M", "T"};
  cin >> V >> A >> B >> C;
  P[0] = A;
  P[1] = B;
  P[2] = C;
  ll cur = 0;
  while (V >= 0) {
    V -= P[cur];
    if (V < 0) {
      cout << T[cur] << endl;
      return 0;
    }
    cur++;
    cur %= 3;
  }
}