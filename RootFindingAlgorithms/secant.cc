#include <iostream>
#include <cmath>

using namespace std;
double EPSILON = 0.001;

double f (double x) {

    return x * log10(x) - 10;
    //return exp (-x) - x;
    //return log (x);
    //return pow(x,2);
    //return (sin(x) + 2 * x - 1);
    //return pow(x-1, 3) + 0.512;
    //return sin(x);
}

void finish( double x, int count ){
    cout << "One root is: " << x << endl; 
    cout << "Iterations: " << count; 
    return;
}

int main() {
    double x0, x1, xn, rb;  //rb -> first root evaluated
    int count = 1;          //counter
    x0 = 8;                 // -> Entry points 
    x1 = 9;                 // -> Entry points
    
    //Check entry points
    if ( f(x0) == 0 ) {
        finish( x0, 0 );
    }
    if ( f(x1) == 0 ) {
        finish( x1, 0 );
    }
    //end check entry points
    
    //Start loop
    do {
        //Evaluate entry points
        double fX0 = f( x0 );
        double fX1 = f( x1 );
        
        //Evaluate new x
        xn = x1 - ( fX1 ) * ( x0 - x1) / ( fX0 - fX1 );
        
        //Get Eaprox% and Print
        double Eap = abs( (xn - x1)  / xn ) * 100;
        cout << "Current iteration: " << count << "\t";
        cout << "X new Value: " << xn << "\t";
        cout << "Error Iterativo Porcentual: " << Eap << endl;
        //End Get Eaprox% and print
        
        //Check new X
        if ( abs( f(xn) ) <= EPSILON ) {
            break;
        }
        cout<<xn<<endl;
        //Changing points
        x0 = x1;
        x1 = xn;
        
        count++;
    } while (true);
    
    finish( xn, count );
    
    return 0;
}