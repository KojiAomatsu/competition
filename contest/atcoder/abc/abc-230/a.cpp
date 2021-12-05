#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A;
  cin >> A;
  if (A >= 42) {
    A++;
  }
  printf("AGC%03d", A);
  // cout << "AGC" << std::setfill('0') << std::setw(3) << A;
}