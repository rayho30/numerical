#include <bits/stdc++.h>
using namespace std;

double f(int n) {
   double fact = 1;
   for (int i = 1; i <= n; i++) {
      fact *= i;
   }
   return fact;
}

double sol(vector<int> v, double p) {
   double ans = v[0];
   double term = 1;

   for (int i = 1; i < v.size(); i++) {
      term *= (p - (i - 1));
      ans += (term / f(i)) * v[i];
   }
   return ans;
}

void out(const vector<int>& v, int s) {
   int x = v.size() - s;
   for (int i = 0; i < x; i++) {
      cout << "  ";
   }

   for (auto x : v) {
      cout << x << " ";
   }
   cout << endl;
}

int main() {
   int x;
   cout << "Enter the number of elements: ";
   cin >> x;

   vector<int> Y;
   vector<int> X;
   vector<int> ynot;
   cout << "Enter the elements (X and F(x)): ";
   for (int i = 0; i < x; i++) {
      int val, key;
      cout << "Enter X: ";
      cin >> key;
      cout << "Enter F(x): ";
      cin >> val;
      X.push_back(key);
      Y.push_back(val);
   }

   ynot.push_back(Y[0]);
   int ter;
   cout << "Enter the value of X to estimate F(x) at: ";
   cin >> ter;

   int h, xnot;
   for (int i = 1; i < x; i++) {
      if (ter > X[i - 1] && ter < X[i]) {
         h = X[i] - X[i - 1];
         xnot = X[i - 1];
         break;
      }
   }

   double p = (double)(ter - xnot) / h;

   cout << "The table of Newton's forward differences: " << endl;
   out(Y, x);

   while (Y.size() > 1) {
      vector<int> tmp;
      for (size_t i = 1; i < Y.size(); i++) {
         int nxt = Y[i] - Y[i - 1];
         tmp.push_back(nxt);
      }
      ynot.push_back(tmp[0]);
      out(tmp, x);
      Y = tmp;
   }

   double ans = sol(ynot, p);
   cout << "At X = " << ter << ", the estimated F(x) is = " << ans << endl;

   return 0;
}
