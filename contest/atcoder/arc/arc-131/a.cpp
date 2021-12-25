#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A, B;
  cin >> A >> B;
  ll pre;
  if (B % 2 == 0) {
    pre = B / 2;
  } else {
    pre = (B / 2) * 10 + 5;
  }
  cout << pre << 0 << A << endl;
}
