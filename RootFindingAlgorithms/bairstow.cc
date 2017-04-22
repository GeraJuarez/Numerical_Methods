#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
double EPSILON = 1;

void sinteticWeirdFormula( double *arr, double *arrOr, int size, double r, double s ) {

    arr[size-1] = arrOr[size-1];
    arr[size-2] = arr[size-1] * r + arrOr[size-2];
    
    for ( int i = size - 3; i >= 0; i-- ) {
        arr[i] = ( arr[i + 1] * r ) + ( arr[i + 2] * s ) + arrOr[i];
    }

    return;
}

void bairstow ( double *arrVal, double r, double s, int size ) {

    int count = 0;
    
    double arrB[size]; //Initial array B
    double arrC[size]; //Initial array C
    double errorR = 0.0, errorS = 0.0;
    
    if ( size <= 2  ) {

        cout << "Root: " << -arrVal[0] / arrVal[1] << endl;
        cout << "1 iteration since it has only one root" << endl;
        return;
    }
    
    double dr; //delta r
    double ds; //delta s
    
    do {
        sinteticWeirdFormula( arrB, arrVal, size, r, s );

        // for ( int i = 0; i < size; i++ ) {
        //     cout << arrB[i] << "\t";
        // }

        sinteticWeirdFormula( arrC, arrB, size, r, s );
        // cout << endl;
        // for ( int i = 0; i < size; i++ ) {
        //     cout << arrC[i] << "\t";
        // }

        // cout << endl;
        
        /** Cramer
         * A = arrC[2]
         * B = arrC[3]
         * C =  - arrB[1]
         * P = arrC[1] 
         * Q = arrC[2]
         * R = - arrB[0]
         * dr = (CQ - BR) / (AQ - PB)
         * ds = (AR - CP) / (AQ - PB)
        */
        
        dr = ( -arrB[1] * arrC[2] - arrC[3] * -arrB[0] ) / ( arrC[2] * arrC[2] - arrC[1] * arrC[3] );
        ds = ( -arrB[0] * arrC[2] - arrC[1] * -arrB[1] ) / ( arrC[2] * arrC[2] - arrC[1] * arrC[3] );
        
        errorR = ( dr / r ) * 100;
        errorS = ( ds / s ) * 100;
        
        r += dr;
        s += ds;
        count++;
    } while ( !(abs(errorR) <= EPSILON && abs(errorS) <= EPSILON) );

    bool imaginary = false;
    double root = r * r + 4 * s;
    double x = r / 2;

    if ( root < 0 ) { //imaginary root

        imaginary = true;
        root = abs ( root );
    }
    root = sqrt(root) / 2;

    if ( imaginary ) {

        cout << "Root 1: " << x << " + " << root << "i" << endl;
        cout << "Root 2: " << x << " - " << root << "i" << endl;    
    } else {

        cout << "Root 1: " << x + root << endl;
        cout << "Root 2: " << x - root << endl; 
    }
    
    cout << "r: " << r << endl;
    cout << "s: " << s << endl;
    cout << "Iteraciones: " << count << endl;
    
    cout << "Coeficientes de la nueva funcion x" << endl;
    for ( int i = 0; i < size; i++ ) {
        cout << i - 2 << " : " << arrB[i] << endl;
    }
    
    double newArr[size - 2];
    int k = 0;
    for ( int i = 2; i < size; i++ ) {
        newArr[k++] = arrB[i];
    }
    
    int newSize = sizeof(newArr) / sizeof(newArr[0]);
    
    cout << "----------------------" << endl;
    bairstow( newArr, r, s, newSize );
    
    //The last row is the higher grade constant
    //Use new r and s for next guess
}

int main() {
    //Input Array of function: Coeficientes del polinomio
    //Agregar 0 cuando x de grado intermedio entre uno menor y uno mayor no se presenta
    //0     x1      x2      x3      x4      x5
    double arrVal[] = 
    //{2, -10, 10, 5, -5, 15};
    //{1.25, -3.875, 2.125, 2.75, -3.5, 1};
    {-2.5, 5.25, -4, 1}; 
    //{-2, 1};
    //{-4, 1, 0, 2, 1.2, 8, -3, 3.2, 0, -4, 6.7};
    //{ 7.87245, -1.67326, 11.495, -5.22437, 6.68282, -4.1275, 6.7 };
    //{ 10.3066, -2.09662, 1.53675, -4.08082, 6.7 };
    //{ 7.39095, 8.25449, 6.7 };
    
    int size = sizeof(arrVal) / sizeof(arrVal[0]);
    double r = -0.5;
    double s =  0.5;
    
    bairstow( arrVal, r, s, size );
    
    
    return 0;
}