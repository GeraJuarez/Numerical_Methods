#include <iostream>
#include <cmath>

using namespace std;

double df( double x ) {

    return - ( 2* pow (x, 3 ) ) + ( 12 * pow( x, 2 ) ) - ( 20 * x ) + 8.5;
}

double euler( double x0, double y0, double xDeseada, double h ) {

    double y1;

    while ( x0 < xDeseada ) {

        cout << "x:" << x0 << "\ty:" << y0 << endl;
        y1 = y0 + ( df( x0 ) * h );
        x0 += h;
        y0 = y1;
    }
    cout << "\ny at " << xDeseada << " = " << y0 << endl;
}

int main() {

    double x;
    double y;
    double h;   //Intervalo
    double x_deseada;

    cout << "Initial x: ";  cin >> x;
    cout << "Initial y: ";  cin >> y;
    cout << "Wanted x: ";   cin >> x_deseada;
    cout << "Steps: ";      cin >> h;

    euler( x, y, x_deseada, h );

    return 0;
}
