#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)

int main() {
  ll N;
  cin >> N;
  ll sold = 108 * N / 100;
  if (sold > 206) {
    cout << ":(" << endl;
  } else if (sold == 206) {
    cout << "so-so" << endl;
  } else {
    cout << "Yay!" << endl;
  }
}
