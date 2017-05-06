#include <iostream>
#include <cmath>
#include <vector>

using namespace std;    

// Method that evaluates the x in a function
double f( double x  ) {

    return 0.2 + 25 * x - 200 * pow( x, 2 ) + 675 * pow( x, 3 ) - 900 * pow( x, 4 ) + 400 * pow( x, 5 );
    //return exp ( x * x );
}

//Simpson Rule 1/3
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

//Simpson Rule 3/8
void SimpsonRule3() {

    double x[4];

    cout << "*** Simpson Rule 3/8 ***" << endl;

    for ( int i = 0; i < 4; i++ ) {
        cout << "Write point " << i + 1 << ": ";
        cin >> x[i];
    }
    
    double l = 0;
    l = ( x[3] - x[0] ) * ( f(x[0]) + 3 * f(x[1]) + 3 * f(x[2]) + f(x[3]) ) / 8;

    cout << "Area under the function = " << l << endl;
}

int main() {

    //double x[4] = {0, 0.5, 1};

    //int n = sizeof(x) / sizeof(x[0]);

    double *x;
    double a;
    double b;
    int n;
    int c;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    cout << "Enter '1' to use 1/3 Rule \nor any other character to use 3/8 Rule: ";
    cin >> c;

    if ( c != 1 )
        SimpsonRule3();
    else {

        cout << "Enter number of divisions: ";
        cin >> n;

        x = new double[n + 1];
        double frag = ( b - a ) / n;

        for ( int i = 1; i < n; i++ ) {
            x[i] = x[i - 1] + frag;
        }

        x[0] = a;
        x[n] = b;

        SimpsonRule( n + 1, x );
    }

    cout << "\n***Remember to change function when doing testings***\n" << endl;

    return 0;
}