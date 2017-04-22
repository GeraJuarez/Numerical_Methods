#include <iostream>
#include <cmath>
#include <vector>

using namespace std;    

// Method that evaluates the x in a function
double f( double x  ) {

    return 0.2 + 25 * x - 200 * pow( x, 2 ) + 675 * pow( x, 3 ) - 900 * pow( x, 4 ) + 400 * pow( x, 5 );
}

void SimpsonRule( int n, double *x, double p0, double p1, double p2 ) {

    cout << "*** Simpson Rule ***" << endl;

    double l = 0;

    l = ( x[n - 1] - x[0] ) * ( f(p0) + 4 * f(p1) + f(p2) ) / 6;

    cout << l << endl;
}

int main() {

    double x[3] = {0 , 0,  0.8};

    int n = 3;

    SimpsonRule( n, x, 0, 0.4, 0.8 );
    //1.367467

    return 0;
}