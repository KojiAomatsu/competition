#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

void solve(ll a, ll b) {
  if (a > b) {
    cout << ">" << endl;
  } else if (a < b) {
    cout << "<" << endl;
  } else {
    cout << "=" << endl;
  }
}

int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  bool is_even;
  if (C % 2 == 0) {
    is_even = true;
  } else {
    is_even = false;
  }
  if (A >= 0 && B >= 0) {
    solve(A, B);
    return 0;
  } else if (A < 0 && B >= 0) {
    if (is_even) {
      solve(abs(A), B);
      return 0;
    } else {
      solve(0, 1);
      return 0;
    }
  } else if (A >= 0 && B < 0) {
    if (is_even) {
      solve(A, abs(B));
      return 0;
    } else {
      solve(1, 0);
      return 0;
    }
  } else {
    if (is_even) {
      solve(B, A);
      return 0;
    } else {
      solve(A, B);
      return 0;
    }
  }
}
