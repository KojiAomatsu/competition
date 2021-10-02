#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll A, B, C;
  cin >> A >> B >> C;

  ll bot = A / C;
  ll ne = bot * C;
  if (A > ne) {
    ne += C;
  }
  if (B < ne) {
    ne = -1;
  }
  cout << ne << endl;
}