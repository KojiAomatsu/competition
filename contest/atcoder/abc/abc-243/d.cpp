#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N, X;
  cin >> N >> X;
  string S;
  cin >> S;
  stack<char> st;
  rep(i, 0, N) {
    char tar = S[i];
    if (st.empty()) {
      st.push(tar);
      continue;
    }
    if (tar == 'U') {
      if (st.top() != 'U') {
        st.pop();
        continue;
      }
    }
    st.push(tar);
  }
  stack<char> rev;
  while (!st.empty()) {
    rev.push(st.top());
    st.pop();
  }
  while (!rev.empty()) {
    char t = rev.top();
    rev.pop();
    if (t == 'U') {
      X /= 2;
    } else if (t == 'L') {
      X = X * 2;
    } else {
      X = X * 2 + 1;
    }
  }

  cout << X << endl;
}