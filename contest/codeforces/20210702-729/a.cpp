#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

bool solve(ll num, vector<ll> li) {
  ll odd_c = 0;
  ll even_c = 0;
  rep(i, 0, 2 * num) {
    if (li[i] % 2 == 1) {
      odd_c++;
    } else {
      even_c++;
    }
  }

  return odd_c == even_c;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll le;
    cin >> le;
    vector<ll> li(2 * le);
    rep(j, 0, 2 * le) { cin >> li[j]; }
    cout << (solve(le, li) ? "Yes" : "No") << endl;
  }
}