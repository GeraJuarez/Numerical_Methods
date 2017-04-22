#include <iostream>
#include <cmath>
#include <vector>

using namespace std;    

// Method that evaluates the x in a function
double f( double x  ) {

    return 0.2 + 25 * x - 200 * pow( x, 2 ) + 675 * pow( x, 3 ) - 900 * pow( x, 4 ) + 400 * pow( x, 5 );
}

void TrapezoidalRule ( int n, double *x ) {

    cout << "=== Trapezoidal Rule ===" << endl;

    double l = 0;

    for ( int i = 1; i < n - 1; i++ ) {

        l += f( x[i] );
    }

    l = f( x[0] ) + l * 2 + f( x[n - 1] );
    l *= ( x[n - 1] - x[0] );
    l /= ( 2 * (n - 1) );                   // n - 1 to return to the original number of segments

    cout << "Area = " << l << endl;
}

int main() {

    double *x;

    double a = 0;
    double b = 0.8;

    int n = 6;   //<- Value to be changed
    
    x = new double[n + 1];

    double frag = ( b - a ) / n;
    cout << "h: " << frag << endl;

    for ( int i = 1; i < n; i++ ) {
        
        x[i] = x[i - 1] + frag;
    }

    x[0] = a;
    x[n] = b;

    n++;
    TrapezoidalRule( n, x );

    return 0;
}