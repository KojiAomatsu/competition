#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string a, b;
  cin >> a >> b;
  map<int, ll> freqa;
  map<int, ll> freqb;
  rep(i, 0, a.size()) { freqa[a[i] - '0']++; }
  rep(i, 0, b.size()) { freqb[b[i] - '0']++; }

  string ansa = "";
  string ansb = "";
  bool is_over = false;
  // bの最初にzeroがあれば確認して is_over = true にする処理を入れる
  // ...
  for (int i = 9; i >= 0; i--) {
    int goal = 10;
    if (is_over) {
      goal = 9;
    }
    int cur = goal - i; // これ以上なら足し合わせられる
    while (true) {
      if (freqa[i] <= freqb[cur]) {
        for (int k = 0; k < freqa[i]; k++) {
          ansa += '0' + i;
          ansb += '0' + cur;
        }
        freqb[cur] -= freqa[i];
        freqa[i] = 0;
        break;
      } else {
        for (int k = 0; k < freqb[i]; k++) {
          ansa += '0' + i;
          ansb += '0' + cur;
        }
        freqa[i] -= freqb[cur];
        freqb[cur] = 0;
      }

      cur++;
      if (cur > 9) {
        break;
      }
    }
  }
  string tmpa = "";
  string tmpb = "";
  for (auto fa : freqa) {
    rep(i, 0, fa.second) { tmpa += '0' + fa.first; }
  }
  reverse(tmpa.begin(), tmpa.end());
  ansa += tmpa;
  for (auto fb : freqb) {
    rep(i, 0, fb.second) { tmpb += '0' + fb.first; }
  }
  reverse(tmpb.begin(), tmpb.end());
  ansb += tmpb;

  cout << ansa << endl;
  cout << ansb << endl;
}