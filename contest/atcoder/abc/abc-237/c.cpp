#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  string S;
  cin >> S;
  bool is_a_mode = true;
  int head = 0, tail = S.size() - 1;
  while (head < tail) {
    if (is_a_mode) {
      if (S[tail] == 'a') {
        if (S[head] == 'a') {
          head++;
          tail--;
        } else {
          tail--;
        }
      } else {
        if (S[head] != S[tail]) {
          cout << "No" << endl;
          return 0;
        } else {
          head++;
          tail--;
          is_a_mode = false;
        }
      }
    } else {
      if (S[head] != S[tail]) {
        cout << "No" << endl;
        return 0;
      } else {
        head++;
        tail--;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}