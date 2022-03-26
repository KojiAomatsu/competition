#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string S;
  cin >> S;
  ll Q;
  cin >> Q;
  ll len = S.size();
  rep(i, 0, Q) {
    ll ti, ki;
    cin >> ti >> ki;
    ll _ki = ki;
    vector<ll> decomp;
    while (_ki > 0) {
      decomp.push_back(_ki % 2);
      _ki /= 2;
    }

    ll dig = decomp.size() - 1;
    reverse(decomp.begin(), decomp.end());
    ll tws = pow(2ll, dig);
    ll rem = ki - tws;
    char tar = S[0];
    if (ti < dig || (ti == dig && rem > 0)) {
      ll tw = pow(2ll, ti);
      ll re = ki % tw;
      ll div = ki / tw;
      tar = S[div - 1 + (re > 0 ? 1 : 0)];
      ki = (re > 0 ? re : tw);
    }
    // go with tar and ki
    ll tar_t = 0;
    ll cur = 1;
    while (true) {
      if (ki <= cur) {
        break;
      }
      tar_t++;
      cur *= 2;
    }
    ll dif = ti - tar_t;
    tar = 'A' + ((tar - 'A') + dif) % 3;
    while (cur > 1) {
      if (ki <= cur / 2) {
        tar = 'A' + ((tar - 'A') + 1) % 3;
      } else {
        tar = 'A' + ((tar - 'A') + 2) % 3;
        ki = ki - cur / 2;
      }
      cur /= 2;
    }
    cout << tar << endl;
  }
}