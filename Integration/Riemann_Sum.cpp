#include <iostream>
#include <cmath>
#include <vector>

using namespace std;    

// Method that evaluates the x in a function
double f( double x  ) {

    return 0.2 + 25 * x - 200 * pow( x, 2 ) + 675 * pow( x, 3 ) - 900 * pow( x, 4 ) + 400 * pow( x, 5 );
}

// Rienmann Sum from the right
void RienmannSumRight( int n, double *x ) {

    cout << "=== Riemann from the Right ===" << endl;

    double sum = 0;

    for ( int i = 1; i < n; i ++ ) {

        sum += f( x[i] ) * ( x[i] - x[i - 1] );
    }

    cout << "Area = " << sum << endl;
}

// Rienmann Sum from the left
void RienmannSumLeft( int n, double *x ) {

    cout << "=== Riemann from the Left ===" << endl;

    double sum = 0;

    for ( int i = 1; i < n; i ++ ) {

        sum += f( x[i - 1] ) * ( x[i] - x[i - 1] );
    }

    cout << "Area = " << sum << endl;
}

int main() {
    
    double *x;

    double a = 0;
    double b = 0.8;

    int n = 2;
    
    x = new double[n + 1];

    double frag = ( b - a ) / n;
    cout << "h: " << frag << endl;

    for ( int i = 1; i < n; i++ ) {
        
        x[i] = x[i - 1] + frag;
    }

    x[0] = a;
    x[n] = b;

    n++;

    RienmannSumLeft( n, x );
    RienmannSumRight( n, x );

    return 0;
}