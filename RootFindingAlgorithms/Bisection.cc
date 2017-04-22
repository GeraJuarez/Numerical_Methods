#include <iostream>
#include <cmath>

using namespace std;

double EPSILON = 0.0000000001;

double f (double x) {
    //return (sin(x) + 2 * x - 1);
    //return  2 * pow( x, 3 ) - 5 * pow( x, 2 ) + 3 * x;
    //return ( 2 * pow( x, 4 ) + pow( x, 3 ) - 8 * pow( x, 2 ) - x + 6 ) / ( x + 2 );
    //return  x / ( pow( x, 2 ) - 2 );
    //return log ( x );
    //return 1 / x;
    //return pow ( x, 2);
    //return -26 + 85*x - 91*pow(x,2) + 44*pow(x,3) - 8*pow(x,4) + pow(x,5);
    //return -13 - 20*x + 19*pow(x,2) - 3*pow(x,3);
    return pow(x,3);
}

int main() {
    double x1, x2, xM, xB = 0;
    int cont = 1;
    
    cout << "give x1: ";
    cin >> x1;
    
    cout << "give x2: ";
    cin >> x2;
    
    if ( f( x1 ) == 0) {
        cout << "One root is: " << x1; 
        return(0);
    }
    
    if ( f( x2 ) == 0) {
        cout << "One root is: " << x2; 
        return(0);
    }
    
    //start loop
    do {
        if ( f( x1 ) * f ( x2 ) < 0) {
            xM = ( x1 + x2 ) / 2;
            
            if ( f( xM ) * f( x1 ) < 0 ) {
                x2 = xM;
            } else
                x1 = xM;
                
            cont++;
        }
        else {
            cout << "No hubo cambio";
            return(0);
        }
        
        double Ea = abs( ((xM - xB) / xM ) ) * 100;
        cout << "xr: " << xM << "\t";
        cout << "Eaprox: " << Ea << endl;
        
        //if ( abs( f( xM ) ) < EPSILON)
        if ( Ea <= 0.05)
            break;
        xB = xM;
        
    } while ( true );
    
    cout << "One root is: " << xM << endl;
    cout << "Iterations: " << cont << endl;
    cout << "Error Iterativo: " << (xM - xB) / xM;
    
    return(0);
}