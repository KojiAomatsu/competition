#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A, B;
  cin >> A >> B;

  double pc = (A - B) * 100.0 / A;
  printf("%.5f", pc);
}
