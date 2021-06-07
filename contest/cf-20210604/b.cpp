#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

long long gcd(long long a, long long b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

ll calc(vector<ll> evens, vector<ll> odds) {
  ll ret = 0;
  ll s_evens = evens.size();
  ll s_odds = odds.size();
  ll s_all = s_evens + s_odds;

  // 偶数分
  ret += (s_odds + s_all - 1) * s_evens / 2;

  // 奇数分
  rep(i, 0, s_odds - 1) {
    rep(j, i + 1, s_odds) {
      if (gcd(odds[i], odds[j]) > 1) {
        ret += 1;
      }
    }
  }
  return ret;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll n;
    cin >> n;
    vector<ll> evens;
    vector<ll> odds;
    rep(i, 0, n) {
      ll tmp;
      cin >> tmp;
      if (tmp % 2 == 0) {
        evens.push_back(tmp);
      } else {
        odds.push_back(tmp);
      }
    }
    cout << calc(evens, odds) << endl;
  }
}