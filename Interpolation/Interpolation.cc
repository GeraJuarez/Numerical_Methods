#include <iostream>
#include <cmath>
#include <vector>

using namespace std;    

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

/**
    Metodo utilizado en la interpolacion Polinomial de Newton
*/
double divisionDiscreta( double *y, double *x, int n, int i, int j, vector<double> *B ) {

    if ( n == 1 ) {

        if ( i == 0 ) {

            B->push_back( y[i] );
            cout << "f(x0): " << y[i] << endl;
        }

        return y[i];
    } else {
        //cout << "xi: " << i << endl;
        //cout << "xj: " << j << endl;
        double val = ( divisionDiscreta( y, x, n - 1, i, j + 1, B ) - divisionDiscreta( y, x, n - 1, i - 1, j, B ) ) / ( x[i] - x[j] );
        if ( j == 0 ) {
            B->push_back( val );
        }
        cout << "f[ x" << i << ", x" << j << " ]: " << val << endl;
        return val;
    }
}

void interpolacionPolinomialNewton() {
    /* Nota: La suma de los binomios son conmutativas */
    double y[] = 
    //{2.31, 3.36, 4.59, 6};
    //{0, 1.386294, 1.791759, 1.609438};
    {0.1353, 7.3890, 20.0855};

    double x[] = 
    //{0.1, 0.4, 0.7, 1};
    //{1, 4, 6, 5};
    {-2, 2, 3};

    double x_inc = -1;

    vector<double> B;
    
    int n = sizeof( y ) / sizeof( y[0] );

    divisionDiscreta( y, x, n, n - 1, 0, &B );

    // 
    int j = B.size();
    double v = 0;

    cout << "Polinomio: ";                      //Print Function
    while ( j --> 0 ) {

        cout << B[j];                           //Print Function

        double temp = B[j];
        int k = j;
        while ( k --> 0 ) {
            
            cout << "(x - " << x[k] << ")";     //Print Function
            temp *= ( x_inc - x[k] );
        }

        if ( j != 0)                            //Print Function
            cout << " + ";                      //Print Function

        v += temp;
    }
    
    cout << "\nf(x) = " << v << endl;

    // El polinomio es: b0 + b1(x - x0) + b2(x - x0)(x - x1) + b3 (x - x0)(x - x1)(x - x2)
}

/**
    Formula utilizda en la iterpolacion de Lagrange
*/
double L( int i, double x_incognita, double *x, int n ) {

    int j = 0;
    double val = 1;

    while ( j < n ) {

        if ( i != j ) {

            val *= ( x_incognita - x[j] ) / ( x[i] - x[j] );
        }

        j++;
    }

    return val;
}

double f( double *y, double *x, double x_incognita, int n ) {

    int i = 0;

    double val = 0;

    while ( i < n ) {

        val += L( i, x_incognita, x, n ) * y[i];
        i++;
    }

    return val;
}

void InterpolacionLagrange() {

    double y[] = 
    //{2.31, 3.36, 4.59, 6};
    {0, 1.386294, 1.791759, 1.609438};

    double x[] = 
    //{0.1, 0.4, 0.7, 1};
    {1, 4, 6, 5};

    int n = sizeof( y ) / sizeof( y[0] );
    double x_incognita = 10;

    cout << "y calculada: " << f( y, x, x_incognita, n ) << endl;;
}

int main() {
    double y0, y1, y2, x0, x1, x2;

    // y1 = 86.4;
    // y2 = 92.5;

    // x1 = 1.0;
    // x2 = 1.5;

    // x = 1.25;

    // interpolacionLineal ( y1, y2, x1, x2, x );

    y0 = 0;
    y1 = 1.386294;
    y2 = 1.791759;
    
    x0 = 1;
    x1 = 4;
    x2 = 6;

    //interpolacionCuadrtica( y0, y1, y2, x0, x1, x2 );

    interpolacionPolinomialNewton();

    //InterpolacionLagrange();

    return 0;
}