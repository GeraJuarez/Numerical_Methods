#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void CalcularErrorRegresionPolinomial(int n, int m, double Y, double a0, double a1, double a2) {
    ifstream p_fileX;
    ifstream p_fileY;
    p_fileX.open("Data/Xdata.dat");
    p_fileY.open("Data/Ydata.dat");

    double x, y;
    double Sr = 0, St = 0, r = 0, Syx = 0;
    double yprom = Y / n;   //Y Promedio

    if ( p_fileX.is_open() ) {
        
        while ( !p_fileX.eof() && !p_fileY.eof() ) {
            
            p_fileX >> x;
                
            p_fileY >> y;
            
            Sr += pow ( ( y - a0 - a1 * x - a2 * x * x ), 2 );
            St += pow ( y - yprom, 2 );

        }
    }
    
    p_fileX.close();
    p_fileY.close();

    Syx = sqrt ( Sr / ( n - (m + 1) ) );
    r = sqrt ( (St - Sr) / St );

}


int main(){
    ifstream p_fileX;
    ifstream p_fileY;
    p_fileX.open("Data/Xdata.dat");
    p_fileY.open("Data/Ydata.dat");
    
    int n = 0;      //Contador

    double a0, a1;      //Coeficiente para la fucion de la recta
    double x, y;        //Valores de x - y
    double yprom;       //Promedio de las Ys
    double XY = 0.0, XY2 = 0.0;                     //Sumatorias de x * y, x^2 * y
    double X = 0.0, x2 = 0.0, x3 = 0.0, x4 = 0.0;  //Sumatoria de potencias de x
    double Y = 0.0;                                 //Sumatoria de y

    if ( p_fileX.is_open() ) {
        
        while ( !p_fileX.eof() && !p_fileY.eof() ) {
            
            p_fileX >> x;
                
            p_fileY >> y;
            
            cout << x << "\t, " << y << endl;
            
            //Sumatoria de Xs
            X += x;
            x2 += x * x;
            x3 += pow ( x, 3 );
            x4 += pow ( x, 4 );
            
            //Sumatoria de Y
            Y += y;
            
            //Sumatorias de XY
            XY += x * y;
            XY2 += x * x * y;
            
            n ++;
        }
        
        cout << "Sistema de ecuaciones encontrada" << endl;
        cout << n  << " * a0 + " << X  << " * a1 + " << x2 << " * a2 = " << Y   << endl;
        cout << X  << " * a0 + " << x2 << " * a1 + " << x3 << " * a2 = " << XY  << endl;
        cout << x2 << " * a0 + " << x3 << " * a1 + " << x4 << " * a2 = " << XY2 << endl;
    }
    
    p_fileX.close();
    p_fileY.close();
        
    
    return 0;
}

/*1


   105.04317  
  - 6.6182528  
    0.3604554  
*/