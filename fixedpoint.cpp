#include <bits/stdc++.h>
using namespace std;

double f(double x) { return (x * x - 5 * x + 1); }
double equ(double x) {
  return (x * x + 1) / 5;
}

int main() {
  cout << "Root found for fixed point: ";
  double root = 0.5;
  double prev = root;
  int count = 0;
  while (count < 1000) {
    prev = root;
    root = equ(prev);
    if (fabs(root - prev) < 0.01) break;
    count++;
  }
  cout << prev << endl;

  return 0;
}
