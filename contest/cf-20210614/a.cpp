#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

// codeforces 交互にgridを埋める問題

void solve(ll n, ll m, vector<string> lines) {
  ll ans = 0;
  bool flag = false;
  pair<ll, char> first_ele;
  rep(i, 0, n) {
    if (flag) {
      break;
    }
    rep(j, 0, m) {
      if (flag) {
        break;
      }
      if (lines[i][j] == 'R' || lines[i][j] == 'W') {
        flag = true;
        first_ele = {(i + j) % 2, lines[i][j]};
      }
    }
  }
  if (flag == false) {
    cout << "Yes" << endl;
    string tmp1 = "";
    string tmp2 = "";
    rep(t, 0, m) {
      if (t % 2 == 0) {
        tmp1 += 'W';
        tmp2 += 'R';
      } else {
        tmp1 += 'R';
        tmp2 += 'W';
      }
    }
    rep(i, 0, n) {
      cout << tmp1 << endl;
      swap(tmp1, tmp2);
    }
    return;
  }

  rep(i, 0, n) {
    rep(j, 0, m) {
      char c = lines[i][j];
      if (c == '.')
        continue;
      if ((i + j) % 2 == first_ele.first) {
        if (c != first_ele.second) {
          cout << "No" << endl;
          return;
        }
      } else {
        if (c == first_ele.second) {
          cout << "No" << endl;
          return;
        }
      }
    }
  }

  cout << "Yes" << endl;
  string tmp1 = "";
  string tmp2 = "";
  rep(t, 0, m) {
    if (t % 2 == 0) {
      tmp1 += 'W';
      tmp2 += 'R';
    } else {
      tmp1 += 'R';
      tmp2 += 'W';
    }
  }
  if (first_ele.first == 0 && first_ele.second == 'R') {
    swap(tmp1, tmp2);
  } else if (first_ele.first == 1 && first_ele.second == 'W') {
    swap(tmp1, tmp2);
  }
  rep(i, 0, n) {
    cout << tmp1 << endl;
    swap(tmp1, tmp2);
  }
  return;
}

int main() {
  ll t;
  cin >> t;
  rep(i, 0, t) {
    ll n, m;
    cin >> n >> m;
    vector<string> li(n);
    rep(j, 0, n) { cin >> li[j]; }
    solve(n, m, li);
  }
}
