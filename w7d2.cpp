//Math 231E Week 7 Discussion 2 Worksheet 7A
//Problem 1 g: Imagine that you had to compute the integral ∫x^64e^xdx. Write out in words the way you would attack this problem in the most efficient manner. 
//My solution

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Recursive function to compute the polynomial P_n(x)
vector<int> polynomial(int n) {
    if (n == 0) {
        return { 1 };  // Base case: P_0(x) = 1
    }

    // Recursive step: P_n(x) = x^n - n * P_{n-1}(x)
    vector<int> prevPoly = polynomial(n - 1);

    vector<int> currPoly(n + 1, 0);  // Create a polynomial of degree n

    // Add x^n term
    currPoly[n] = 1;

    // Subtract n * P_{n-1}(x) from the current polynomial
    for (int i = 0; i < prevPoly.size(); ++i) {
        currPoly[i] -= n * prevPoly[i];
    }
    return currPoly;
}

// Function to format the polynomial as a string
string formatPolynomial(const vector<int>& poly) {
    string result;
    bool isFirstTerm = true;

    for (int i = poly.size() - 1; i >= 0; --i) {
        int coeff = poly[i];
        if (coeff != 0) {
            if (!isFirstTerm) {
                result += (coeff > 0) ? " + " : " - ";
            }
            else {
                if (coeff < 0) result += "-";
                isFirstTerm = false;
            }
            if (abs(coeff) != 1 || i == 0) {
                result += to_string(abs(coeff));
            }
            if (i > 0) {
                result += "x";
                if (i > 1) {
                    result += "^" + to_string(i);
                }
            }
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    vector<int> poly = polynomial(n);
    cout << "The value of the integral for n = " << n << " is: e^x * (" << formatPolynomial(poly) << ")" << endl;

    return 0;
}
