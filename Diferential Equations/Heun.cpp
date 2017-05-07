#include <iostream>
#include <cmath>

using namespace std;

double df( double x, double y ) {
    return 4 * exp ( 0.8 * x ) - 0.5 * y;
}

double euler( double x0, double y0 ) {

    double h = 0.5;     //Intervalo
    double y1 = 0;
    y1 = y0 + df( x0, y0 ) * h;

    return y1;
}

double Heun( double x0, double y0 ) {

    double y1 = 0;
    y1 = y0 + ( df( x0, y0 ) +  df( x0 + 1, euler(x0, y0) ) * h ) / 2;

    cout << y1 << endl;
}

int main() {

    Heun( 0, 2 );

    return 0;
}