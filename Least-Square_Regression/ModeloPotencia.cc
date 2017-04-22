#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    ifstream p_fileX;
    ifstream p_fileY;
    p_fileX.open("Data/Xdata.dat");
    p_fileY.open("Data/Ydata.dat");

    double XY = 0.0, X = 0.0, Y = 0.0, X2 = 0.0, n = 0.0;
    double a0, a1, ALPHA, BETA;      //Coeficiente para la fucion de la recta
    double yprom;       //Promedio de las Ys
    double x[31];       //Valores de x
    double y[31];       //Valores de y
    
    int i = 0;

    if ( p_fileX.is_open() ) {
        while ( !p_fileX.eof() && !p_fileY.eof() ) {
            
            p_fileX >> x[i];
                
            p_fileY >> y[i];
            
            cout << x[i] << ", " << y[i] << endl;
            
            y[i] = log10 ( y[i] );
            x[i] = log10 ( x[i] );
            
            X += x[i];
            Y += y[i];
            XY += x[i] * y[i];
            X2 += x[i] * x[i];
            n += 1.0;
            i++;
        }
        
        a1 = ( n * XY - X * Y ) / ( n * X2 - X * X );
        a0 = Y / n - a1 * X / n;
        
        ALPHA = pow( 10,  a0 );
        BETA = a1;
        cout << "y = " << ALPHA << " * x^" << BETA << endl;
    }
    p_fileX.close();
    p_fileY.close();
    
    yprom = Y / n;
    double st = 0.0;    //suma total de cuadrados alrededor de la media
    double sr = 0.0;    //suma de cuadrados de residuos, alrededor dela linea de regresion
    double Sxy = 0.0;   //Error de estandard de estimacion
    double r = 0.0;     //Coeficiente de correlacion
    
    //Calcular Sr y St
    for ( int j = 0; j < n; j++ ) {
        sr += pow ( pow ( 10, y[j] ) - ALPHA * pow ( pow ( 10, x[j]) , BETA ) , 2 );
        st += pow ( pow ( 10, y[j] ) - yprom, 2 );
    }
    
    //VAraicion estndar St / n-1
    //Coeficiente de Variancion c.v = desviacion estantar / Ypromedio
    
    //Calcular Sxy
    Sxy = sqrt( sr / (n - 2) );
    
    //Calcular coeficiente de correlacion r
    r = sqrt ( ( st - sr ) / st );
    
    
    //Print
    cout << "Sr: " << sr << "\tSt: " << st << endl;
    cout << "Error estandar: " << Sxy << "\tCorrelacion(r) :" << r << endl;
    
    return 0;
}