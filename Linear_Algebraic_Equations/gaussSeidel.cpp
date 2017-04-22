#include <iostream>
#include <cmath>

using namespace std;
//lambda*xNueva + (1-lambda) * xvieja
double EPSILON = 0.00000001;

int main() {
    double prevX, prevY, prevZ, ErrX, ErrY, ErrZ;
    int numOfFunctions = 3;
    
    //Coeficientes de la funcion 1: Ex: x + y + z = 12
    //Coeficientes de la funcion 2
    //Coeficientes de la funcion 3
    double c[3][4] = {
        {25,5,1,106.8},
        {64,8,1, 177.2},
        {144,12,1,279.2}
        //{2,-1,1,4},
        //{1,2,-1,3},
        //{1,1,1,2}
        //{2, -1, 1,  7},
        //{1, 2, -1,  6},
        //{1,  1, 1, 12} 
    };
    //0.29048   19.69   1.0857
    
    //Add values to start iterations
    double unknow[] = {1, 2, 5}; //unkown values
    int x = 0, y = 1, z = 2;    //Identify index when applying formula
    
    /*  Dummy values  */
    prevX = -9999999;
    prevY = -9999999;  
    prevZ = -9999999;
    
    int cont = 0;
    
    do {
        cont++;
        
        unknow[x] = ( c[0][3] - c[0][y] * unknow[y] - c[0][z] * unknow[z] ) / c[0][0];
        unknow[y] = ( c[1][3] - c[1][x] * unknow[x] - c[1][z] * unknow[z] ) / c[1][1];
        unknow[z] = ( c[2][3] - c[2][x] * unknow[x] - c[2][y] * unknow[y] ) / c[2][2];

        ErrX = abs( ( unknow[x] - prevX ) / unknow[x] );
        ErrY = abs( ( unknow[y] - prevY ) / unknow[y] );
        ErrZ = abs( ( unknow[z] - prevZ ) / unknow[z] );
        
        cout << "Iteraciones: " << cont << endl;
        cout << "ErrorX: " << ErrX << "\tErrorY: " << ErrY << "\tErrorZ: " << ErrZ << endl;
        
        if ( ErrX <= EPSILON && ErrY <= EPSILON && ErrZ <= EPSILON )
            break;
    
        prevX = unknow[0];
        prevY = unknow[1];
        prevZ = unknow[2];
    
    } while ( true );
    
    cout << "Iteraciones: " << cont << endl;
    cout << "ErrorX: " << ErrX << "\tErrorY: " << ErrY << "\tErrorZ: " << ErrZ << endl;
    for ( int i = 0; i < numOfFunctions; i++ ) {
        cout << "Valores: " << unknow[i] << endl;
    }
    
    return 0;
}