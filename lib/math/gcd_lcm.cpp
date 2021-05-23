#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

long long gcd(vector<long> li) {
  int n = li.size();
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return li[0];
  }
  long long a;
  a = gcd(li[0], li[1]);
  if (n == 2) {
    return a;
  }

  for (int i = 2; i < n; i++) {
    a = gcd(a, li[i]);
  }
  return a;
}

long long lcm(long long a, long long b) { return a * b / gcd(a, b); }

long long lcm(vector<long long> li) {
  long long n = li.size();
  long long a = 1;
  for (int i = 0; i < n; i++) {
    a = lcm(a, li[i]);
  }
  return a;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << gcd({a, b, c}) << endl;
  cout << lcm({a, b, c}) << endl;
}