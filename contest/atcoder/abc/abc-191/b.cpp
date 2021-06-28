#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, X;
  cin >> N >> X;
  rep(i, 0, N) {
    ll num;
    cin >> num;
    if (num != X) {
      cout << num << " ";
    }
  }
  cout << endl;
}
