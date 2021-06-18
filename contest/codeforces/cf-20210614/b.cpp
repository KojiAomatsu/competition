#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

ll solve(ll num, vector<ll> li) {
  if (num == 1) {
    return li[0];
  }
  ll sum = 0;
  ll bef = 0;
  rep(i, 0, num) {
    sum += abs(li[i] - bef);
    bef = li[i];
  }
  sum += li.back();

  ll red = 0;
  rep(i, 0, num) {
    ll mx;
    if (i == 0) {
      mx = li[1];
    } else if (i == num - 1) {
      mx = li[num - 2];
    } else {
      mx = max(li[i - 1], li[i + 1]);
    }
    ll dif = li[i] - mx;
    if (dif > 0) {
      red += dif;
    }
  }

  return sum - red;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll le;
    cin >> le;
    vector<ll> li(le);
    rep(j, 0, le) { cin >> li[j]; }
    cout << solve(le, li) << endl;
  }
}
