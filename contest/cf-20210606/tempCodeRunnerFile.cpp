#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

string solve(ll num, string str) {
  string cur = "";
  while (true) {
    if (cur.size() == 0) {
      cur.push_back('a');
    } else if (cur[0] == '{') {
      ll sz = cur.size();
      string subs(sz, 'a');
      cur = subs;
    }
    if (find(cur.begin(), cur.end(), '{') != cur.end()) {
      auto pos = find(cur.begin(), cur.end(), '{') - cur.begin();
      cur[pos - 1] = cur[pos - 1] + 1;
      while (find(cur.begin(), cur.end(), '{') != cur.end()) {
        auto po = find(cur.begin(), cur.end(), '{') - cur.begin();
        cur[po] = 'a';
      }
      if (cur[0] == '{') {
        ll sz = cur.size();
        string subs(sz, 'a');
        cur = subs;
      }
    }
    if (str.find(cur) == string::npos) {
      break;
    }
    string subs;
    subs = cur.substr(0, cur.size() - 1);
    char last = cur.back();
    subs.push_back(last + 1);
    cur = subs;
  }
  return cur;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll le;
    string str;
    cin >> le >> str;
    cout << solve(le, str) << endl;
  }
}