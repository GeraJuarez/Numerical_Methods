#include <iostream>
#include <cmath>

using namespace std;

double df( double x ) {

    return - ( 2* pow (x, 3 ) ) + ( 12 * pow( x, 2 ) ) - ( 20 * x ) + 8.5;
}

double euler( double x0, double y0, double xDeseada ) {

    double h = 0.5;     //Intervalo
    double y1;

    while ( x0 < xDeseada ) {

        cout << "x:" << x0 << " y:" << y0 << endl;
        y1 = y0 + ( df( x0 ) * h );
        x0 += h;
        y0 = y1;
    }
    cout << "\ny at " << xDeseada << ": " << y0 << endl;
}

int main() {

    euler( 0, 1, 4 );

    return 0;
}
