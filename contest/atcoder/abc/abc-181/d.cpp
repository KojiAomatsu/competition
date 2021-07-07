#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string s;
  cin >> s;
  map<char, ll> nums;
  rep(i, 0, s.size()) { nums[s[i]]++; }
  if (3 - s.size() > 0) {
    nums['0'] += 3 - s.size();
  }
  rep(i, 1, 125) {
    ll n = i * 8;
    map<char, ll> exi;
    bool goahead = true;
    bool zerof = false;
    rep(j, 0, 3) {
      ll d = n % 10;
      if (d == 0) {
        exi['0']++;
        zerof = true;
        n /= 10;
        continue;
      }
      if (zerof == true) {
        goahead = false;
      }
      char dc = '0' + d;
      exi[dc]++;
      n /= 10;
    }
    if (!goahead) {
      continue;
    }
    bool ok = true;
    for (auto ele : exi) {
      if (ele.second > nums[ele.first]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}