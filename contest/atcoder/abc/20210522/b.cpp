#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int n = s.length();

  string result = "";

  for (int j = 0; j < n; j++) {
    int i = n - 1 - j;
    if (s[i] == '0')
      result += "0";
    if (s[i] == '1')
      result += "1";
    if (s[i] == '6')
      result += "9";
    if (s[i] == '8')
      result += "8";
    if (s[i] == '9')
      result += "6";
  }
  cout << result << endl;
}