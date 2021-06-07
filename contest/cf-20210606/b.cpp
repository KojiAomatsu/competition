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
      string n0(cur.size() + 1, 'a');
      cur = n0;
    }
    if (find(cur.begin(), cur.end(), '{') != cur.end()) {
      ll sz = cur.size();
      rep(i, 0, sz) {
        if (cur[sz - i - 1] != 'z' && cur[sz - i - 1] != '{') {
          cur[sz - i - 1] = cur[sz - i - 1] + 1;
          rep(j, sz - i, sz) { cur[j] = 'a'; }
          break;
        } else if (i == sz - 1) {
          string ne(sz + 1, 'a');
          cur = ne;
        }
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