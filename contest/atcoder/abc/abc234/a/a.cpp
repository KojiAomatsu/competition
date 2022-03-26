#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int f(int x) { return x * x + x * 2 + 3; }

int main() {
  ll N;
  cin >> N;
  cout << f(f(f(N) + N) + f(f(N))) << endl;
  return 0;
}