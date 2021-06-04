#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

string calc(ll length, ll iteration, string target) {
  rep(i, 0, iteration) {
    string new_str = "";
    // index 0
    if (target[1] == '1') {
      new_str.push_back('1');
    } else {
      new_str.push_back(target[0]);
    }
    rep(j, 1, length) {
      char target_char = target[j];
      char prev_char = target[j - 1];
      if (target_char == '1') {
        new_str.push_back('1');
        continue;
      }
      // target_char == '0'
      if (j == length - 1) {
        if (prev_char == '1') {
          new_str.push_back('1');
          continue;
        } else {
          new_str.push_back(target[j]);
          continue;
        }
      }
      // & char has followers
      if ((prev_char == '0' && target[j + 1] == '1') ||
          (prev_char == '1' && target[j + 1] == '0')) {
        new_str.push_back('1');
      } else {
        new_str.push_back(target_char);
      }
    }
    if (new_str == target) {
      break;
    }
    target = new_str;
  }
  return target;
}

int main() {
  ll N;
  cin >> N;
  rep(i, 0, N) {
    ll tmp1, tmp2;
    string tmp3;
    cin >> tmp1 >> tmp2 >> tmp3;
    cout << calc(tmp1, tmp2, tmp3) << endl;
  }
}