#include <iostream>
#include <cmath>
#include <vector>

using namespace std;    

// Method that evaluates the x in a function
double f( double x  ) {

    //return 0.2 + 25 * x - 200 * pow( x, 2 ) + 675 * pow( x, 3 ) - 900 * pow( x, 4 ) + 400 * pow( x, 5 );
    return exp ( x * x );
}

void SimpsonRule( int n, double *x ) {

    cout << "*** Simpson Rule 1/3 ***" << endl;
    
    double l = 0;
    double oddSum = 0;
    double pairSum = 0;
    
    for ( int i = 1; i < n - 1; i++ ) {
        
        if ( i % 2 == 0 )
            pairSum += f( x[i] );
        else 
            oddSum += f( x[i] );

    }

    l = ( x[n - 1] - x[0] ) * ( f( x[0] ) + 4 * oddSum + 2 * pairSum + f( x[n - 1] ) ) / ( 3 * (n - 1) );

    cout << "Area under the function = " << l << endl;
}

void SimpsonRule3() {

    double x[4] = {0, 0, 0, 0};
    int n = 4;

    cout << "*** Simpson Rule 3/8 ***" << endl;
    
    double l = 0;

    l = ( x[n - 1] - x[0] ) * ( f(x[0]) + 3 * f(x[1]) + 3 * f(x[2]) + f(x[3]) ) / 8;

    cout << "Area under the function = " << l << endl;
}

int main() {

    //double x[4] = {0, 0.5, 1};

    //int n = sizeof(x) / sizeof(x[0]);

    double *x;

    double a = 0;
    double b = 1;

    int n = 4;  //<- Value to be changed
    
    x = new double[n + 1];

    double frag = ( b - a ) / n;
    for ( int i = 1; i < n; i++ ) {
        
        x[i] = x[i - 1] + frag;
    }

    x[0] = a;
    x[n] = b;

    n++;

    SimpsonRule( n, x );

    return 0;
}