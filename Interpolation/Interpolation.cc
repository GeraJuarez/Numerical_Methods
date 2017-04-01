#include <iostream>
#include <cmath>
#include <vector>

using namespace std;    
double EPSILON = 0.00001;       //Error


void interpolacionLineal( double y1, double y2, double x1, double x2, double x ) {

    double y = 0.0;

    y = y1 + ( y2 - y1 ) * ( x - x1 ) / ( x2 - x1 );

    cout << "Valor interpolado es (y): " << y << endl;
}

void interpolacionCuadrtica (  double y0, double y1, double y2, double x0, double x1, double x2 ) {

    double b0 = y0;

    // Diferencia dividida discreta
    double b1 = ( y1 - y0 ) / ( x1 - x0 );

    double b2 = ( ( ( y2 - y1 ) / ( x2 - x1 ) ) - b1 ) / ( x2 - x0);

    double a = b2;
    double b = ( b1 - b2 * x1 - b2 * x0 );
    double c = ( b0 - b1 * x0 + b2 * x0 * x1 );

    cout << "\n++++++++++++++++++++++++++++++" << endl;
    cout << "b0: " << b0 << "\tb1: " << b1 << "\tb2: " << b2 << endl;
    cout << "Funcion cuadratica: " << a << "x^2 + " << b << "x + " << c << endl << endl;
}

double divisionDiscreta( double *y, double *x, int n, int i, int j ) {

    if ( n == 1 ) {

        return y[i];
    } else {
        
        double val = ( divisionDiscreta( y, x, n - 1, i, j + 1 ) - divisionDiscreta( y, x, n - 1, i - 1, j ) ) / x[i] - x[j];
        return val;
    }
}

void interpolacionPolinomialNewton() {
    double y[] = {1, 1};
    double x[] = {1, 1};
    int n = sizeof( y ) / sizeof( y[0] );

    divisionDiscreta( y, x, n, n - 1, 0 );

}

int main() {
    double y0, y1, y2, x0, x1, x2;

    // y1 = 86.4;
    // y2 = 92.5;

    // x1 = 1.0;
    // x2 = 1.5;

    // x = 1.25;

    // interpolacionLineal ( y1, y2, x1, x2, x );
    interpolacionPolinomialNewton();

    y0 = 0;
    y1 = 1.386294;
    y2 = 1.791759;
    
    x0 = 1;
    x1 = 4;
    x2 = 6;

    //interpolacionCuadrtica( y0, y1, y2, x0, x1, x2 );

    return 0;
}