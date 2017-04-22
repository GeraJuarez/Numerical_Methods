#include <iostream>
#include <cmath>

using namespace std;
double ALMOST_CERO = 0.0000000000001;
double EPSILON = 0.000000001;

double f (double x) {
    //return pow ( x, 3 ) + 5 * x - 10;
    return (sin(x) + 2 * x - 1);
    //return exp (x) + x;
    //return pow (x, 10) - 1;
    //return pow(x-1, 3) + 0.512;  //Divergence at inflection point
    //return pow(x,3) - 0.03 * pow(x,2) + 2.4 * pow(10,-6); //Division by 0
    //return pow(x,2) + 2; //No roots: oscilation
    //return -2 + 6 * x - 4 * pow(x,2) + 0.5 * pow(x,3); //guess: 4.2, 4.43 ejercicio 6.5 pag 172
    //return (pow (x,3) )/ pow (x-1,2); //Divergence point start:-1
    //return sin(x);
    //return -3 / (4 * pow(x, 2));
    //return log (abs(x)); //divergence
    //return log((pow(x,2)*7)/((pow(x,3)*5)-(2*x)));
    //return 1/x;
    //return pow(x,2);
}

double dF (double x) {
    return 2 * x;
}

void finish( double x, int count ){
    cout << "One root is: " << x << endl; 
    cout << "Iterations: " << count; 
    return;
}

int main() {
    double x0, x1, df, xb, fX, Ea;
    int count = 1;      //Counter for iterations
    x0 = 5;            // --> Declare x0, Guess

    if ( f(x0) == 0 ) {
        
        finish( x0, 0 );
    } else {
        //Start loop
        do {
            fX = f ( x0 );
            //Get derivate by derivate formula
            //x1 = x0 - ( f(x0) / dF(x0) );
            
            //Derivate by (y2 - y1)/(x2 - x1) "It does not need to calculate the derivate of the function"
            df = ( f( x0 + ALMOST_CERO ) - fX ) / ( ALMOST_CERO );
            
            // Getting x1
            x1 = x0 - ( fX / df );
            
            //Getting Eaprox
            Ea = abs( ((x0 - xb) / x0 ) ) * 100;
            
            cout << "x Value: " << x0 << "\t";
            cout << "Eaprox: " << Ea << endl;
            
            if ( abs( fX ) < EPSILON )
            //if ( Ea <= 0.1 ) 
                break;
            
            xb = x0;
            x0 = x1;
            count++;
        } while ( true );
        cout << "Error Iterativo: " << Ea << endl;
        finish( x0, count);
    } 
    return(0);
}