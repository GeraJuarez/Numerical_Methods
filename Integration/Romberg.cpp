#include <iostream>
#include <cmath>

using namespace std;

/* Code shared by Arturo Fornes */
/* Slightly modified for my own understanding */

// Method that evaluates the x in a function
double f( double x ) {
    //return exp( x * x );
    return 1 / x;
}

// Trapezoidal Method
double trapezoid( double a, double b, int n ) {
    double h = (b - a) / n;
    double sum = 0;

    for ( double i = a + h; i < b; i += h ) {
        sum += 2 * f(i);
    }

    sum += f(b) + f(a);
    sum *= h / 2;
    cout << "Trapezoid Approximation = " << sum << endl;
    return sum;
}

double romberg_formula( double a, double b, int k ) {
    return ( pow(4, k) * b - a ) / ( pow(4, k) - 1 );
}

double romberg( int no_of_approximations, double a, double b ) {

    int *number = new int[no_of_approximations];                    //Array with the number of trapezoids for each approximation
    double *approximations = new double[no_of_approximations];      //Array with approximations of the trapezoids

    for ( int i = 0; i < no_of_approximations; i++ ) {
        //Read the number of trapezoids used in each approximation
        cout << "Number of Trapezoids for approximation " << i << " = ";
        cin >> number[i];
    }

    for ( int i = 0; i < no_of_approximations; i++ ) {
        //Use trapezoidal rule 'no_of_appoximations' times with its respective number of trapezoids 'number'
        approximations[i] = trapezoid( a, b, number[i] );
    }

    for ( int j = 1; j < no_of_approximations; j++ ) {
        for ( int i = 0; i < no_of_approximations - j; i++ ) {
            //Iterates Romberg formula
            approximations[i] = romberg_formula( approximations[i], approximations[i + 1], j );
        }
    }

    cout << "Integral = " << approximations[0] << endl;

    return approximations[0];
}

int main() {

    double a, b;                                                                    //Range of the integral                  
    int no_of_approximations;                                                       //Number of trapezoidal rules to be used
    cout << "Initial value (a): "; cin >> a;                                        //Read a
    cout << "Final value (b): "; cin >> b;                                          //Read b
    cout << "Number of Initial Approximations: "; cin >> no_of_approximations;      //Read # of approximations
    romberg( no_of_approximations, a, b );

    return 0;
}