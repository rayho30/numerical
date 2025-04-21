#include <bits/stdc++.h>
#define f1(x, y, z) (85 - 6 * y + z) / 27
#define f2(x, y, z) (72 - 6 * x - 2 * z) / 15
#define f3(x, y, z) (110 - x - y) / 54
using namespace std;

int main() {
  float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e;
  int step = 1;

  // Setting precision and writing floating point values in fixed-point notation.
  cout << setprecision(4) << fixed;

  cout << "Enter tolerable error: ";
  cin >> e;
  cout << endl << "Count  x        y          z" << endl;
  do {
    x1 = f1(x0, y0, z0);
    y1 = f2(x0, y0, z0);
    z1 = f3(x0, y0, z0);
    cout << step << "\t" << x1 << "\t" << y1 << "\t" << z1 << endl;
    // Error
    e1 = fabs(x0 - x1);
    e2 = fabs(y0 - y1);
    e3 = fabs(z0 - z1);
    step++;
    // Set value for next iteration
    x0 = x1;
    y0 = y1;
    z0 = z1;
  } while (e1 > e && e2 > e && e3 > e);

  cout << endl << "Solution: x = " << x1 << ", y = " << y1 << " and z = " << z1;
  return 0;
}
