#include <iostream>
#include <cmath>

using namespace std;

double df( double x, double y ) {
    return 4 * exp ( 0.8 * x ) - 0.5 * y;
}

double euler( double x0, double y0, double h ) {

    double y1 = 0;
    y1 = y0 + df( x0, y0 ) * h;

    return y1;
}

void Heun( double x0, double y0, double h, double x_deseada ) {

    cout << "**** Heun's Method ****" << endl;

    double y1 = 0;

    while ( x0 < x_deseada ) {

        y1 = y0 + ( df( x0, y0 ) +  df( x0 + 1, euler(x0, y0, h) ) * h ) / 2;
        cout << y1 << endl;
        x0 += h;
        y0 = y1;
    }

    cout << "\ny_Heun = " << y0 << endl;
    
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

    //Heun( x, y, h, x_deseada );
    Midpoint( x, y, h, x_deseada );

    return 0;
}

/* Under development
double euler2( double x0, double y0, double h ) {

    double y1 = 0;
    y1 = y0 + df( x0, y0 ) * h / 2;

    return y1;
}

void Midpoint( double x0, double y0, double h, double x_deseada ) {

    cout << "**** Midpoint or improved polygon Method ****" << endl;

    double y1 = 0;

    while ( x0 < x_deseada ) {

        y1 = y0 + ( df( x0, y0 ) +  df( x0 + 1, euler2(x0, y0, h) ) * h / 2 );
        cout << y1 << endl;
        x0 += h;
        y0 = y1;
    }

    cout << "\ny_Heun = " << y0 << endl;
    
}
*/