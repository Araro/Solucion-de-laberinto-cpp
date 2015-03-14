//============================================================================
// Name        : Laberinto.cpp
// Author      : Eric Gonzalez Vallejo
// Version     : 1.1
// Copyright   : Derechos Reservados 2014
// Description : Solucion de laberinto
//============================================================================

    #include <iostream>
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#include "concolor.h"
	#include <time.h>

    using namespace std;

    #define FILAS 10
    #define COLUMNAS 11

    void despliegaArreglo ( const char laberinto[][ 11 ] );
    void posicionRobot (int m, int n);
    void delay(void);

    int x,y,m,n,k,l,a,b,t,d;
    int contador = 0;
    int salida = 1;
    int orientacion = 1;
    int pasada = 0;

    char laberinto[ 10 ][ 11 ] = {
    							   {'1','1','1','1','1','1','1','1','1','1','\0'},
    							   {'1','0','0','0','0','0','1','0','0','1','\0'},
    							   {'1','0','1','1','1','0','1','1','0','1','\0'},
    							   {'1','0','1','0','1','0','1','0','0','1','\0'},
    							   {'2','0','1','0','0','0','1','1','0','1','\0'},
    							   {'1','1','1','0','1','0','0','0','0','1','\0'},
    							   {'1','0','0','0','1','0','1','1','0','1','\0'},
    							   {'1','0','1','0','0','0','1','1','1','1','\0'},
    							   {'1','0','1','0','1','0','0','0','0','1','\0'},
    							   {'1','1','1','1','1','1','1','1','1','1','\0'},
    							 };
    char camino[ 10 ][ 11 ] = {
    							   {'1','1','1','1','1','1','1','1','1','1','\0'},
    							   {'1','0','0','0','0','0','1','0','0','1','\0'},
    							   {'1','0','1','1','1','0','1','1','0','1','\0'},
    							   {'1','0','1','0','1','0','1','0','0','1','\0'},
    							   {'2','0','1','0','0','0','1','1','0','1','\0'},
    							   {'1','1','1','0','1','0','0','0','0','1','\0'},
    							   {'1','0','0','0','1','0','1','1','0','1','\0'},
    							   {'1','0','1','0','0','0','1','1','1','1','\0'},
    							   {'1','0','1','0','1','0','0','0','0','1','\0'},
    							   {'1','1','1','1','1','1','1','1','1','1','\0'},
    							};


    int main()
    {
    	cout << "\n";
    	cout << "\n";
    	cout << cyan << "El laberinto es el siguiente: \n\n" << normal;
        despliegaArreglo (laberinto);
        cout << "\n\n";

        cout << cyan << "En que calle desea posicionar el robot?: " << normal;
        cin >> x;
        m = x - 1;
        cout << cyan << "En que avenida desea posicionar el robot?: " << normal;
        cin >> y;
        cout << "\n\n";
        n = y - 1;

        system("/usr/bin/clear");

        posicionRobot(m,n);

        cout << "\n\n";


        // comienza la solucion del laberinto
        int w,q;    
        if (laberinto[ m ][ n ] == '#')
            {
                laberinto [ m ][ n ] = '0';
                a = m;
                b = n;
                q = m;
                w = n;

                camino [a][b] = { '#' };  
                despliegaArreglo (camino);
                cout << "\n ";
                delay();  

                if (laberinto [m+1][n] == '2' || laberinto [m-1][n] == '2' || laberinto [m][n+1] == '2' || laberinto [m][n-1] == '2')
                    {
                        salida = 2;
                    }

                while (salida != 2)
                {

                    if (orientacion == 1)
                    {
                        // k es frente y l es derecha
                        k = m;
                        l = n;
                        k--;
                        l++;
                        if ( laberinto [m][l] == '0' && orientacion == 1 )
                        {
                            orientacion = 2;
                            n = n + 1;

                            if (camino [m][n] == '0' )
                            {
                                pasada = 0;
                            }
                            if (camino [m][n] == '$')
                            {
                                pasada = 1;
                            }
                            if (camino [m][n] == '&' )
                            {
                                pasada = 2;
                            }


                            camino [m][n] = {'>'};
                            despliegaArreglo (camino);
                            cout << "\n ";
                            delay();
                            
                            if (pasada == 2)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 1)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 0)
                            {
                                camino [m][n] = { '$' };
                            }
                            despliegaArreglo (camino);
                            cout << "\n \n";
                            system("/usr/bin/clear");
                        }
                        if ( ( laberinto [k][n] == '0' && laberinto [m][l] == '1' ) && orientacion == 1 )
                        {
                            m = m - 1;

                            if (camino [m][n] == '0' )
                            {
                                pasada = 0;
                            }
                            if (camino [m][n] == '$')
                            {
                                pasada = 1;
                            }
                            if (camino [m][n] == '&' )
                            {
                                pasada = 2;
                            }

                            camino [m][n] = {'^'};
                            despliegaArreglo (camino);
                            cout << "\n ";
                            delay();

                            if (pasada == 2)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 1)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 0)
                            {
                                camino [m][n] = { '$' };
                            }
                            despliegaArreglo (camino);
                            cout << "\n \n";
                            system("/usr/bin/clear");
                        }
                        if ( ( laberinto [k][n] == '1' && laberinto [m][l] == '1' ) && orientacion == 1 )
                        {
                            orientacion = 4;

                            if (camino [m][n] == '0' )
                            {
                                pasada = 0;
                            }
                            if (camino [m][n] == '$')
                            {
                                pasada = 1;
                            }
                            if (camino [m][n] == '&' )
                            {
                                pasada = 2;
                            }

                            camino [m][n] = {'<'};
                            despliegaArreglo (camino);
                            cout << "\n ";
                            delay();

                            if (pasada == 2)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 1)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 0)
                            {
                                camino [m][n] = { '$' };
                            }
                            despliegaArreglo (camino);
                            cout << "\n \n";
                            system("/usr/bin/clear");
                        }

                    }


                    if (orientacion == 2)
                    {
                        // k es derecha y l es frente
                        k = m;
                        l = n;
                        k++;
                        l++;
                        if ( laberinto [k][n] == '0' && orientacion == 2 )
                        {
                            orientacion = 3;
                            m = m + 1;

                            if (camino [m][n] == '0' )
                            {
                                pasada = 0;
                            }
                            if (camino [m][n] == '$')
                            {
                                pasada = 1;
                            }
                            if (camino [m][n] == '&' )
                            {
                                pasada = 2;
                            }

                            camino [m][n] = {'v'};
                            despliegaArreglo (camino);
                            cout << "\n ";
                            delay();

                            if (pasada == 2)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 1)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 0)
                            {
                                camino [m][n] = { '$' };
                            }
                            despliegaArreglo (camino);
                            cout << "\n \n";
                            system("/usr/bin/clear");
                         }
                        if ( ( laberinto [m][l] == '0' && laberinto [k][n] == '1' ) && orientacion == 2 )
                        {
                            n = n + 1;

                            if (camino [m][n] == '0' )
                            {
                                pasada = 0;
                            }
                            if (camino [m][n] == '$')
                            {
                                pasada = 1;
                            }
                            if (camino [m][n] == '&' )
                            {
                                pasada = 2;
                            }

                            camino [m][n] = {'>'};
                            despliegaArreglo (camino);
                            cout << "\n ";
                            delay();

                            if (pasada == 2)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 1)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 0)
                            {
                                camino [m][n] = { '$' };
                            }
                            despliegaArreglo (camino);
                            cout << "\n \n";
                            system("/usr/bin/clear");
                        }
                        if ( ( laberinto [m][l] == '1' && laberinto [k][n] == '1' ) && orientacion == 2 )
                        {
                            orientacion = 1;

                            if (camino [m][n] == '0' )
                            {
                                pasada = 0;
                            }
                            if (camino [m][n] == '$')
                            {
                                pasada = 1;
                            }
                            if (camino [m][n] == '&' )
                            {
                                pasada = 2;
                            }

                            camino [m][n] = {'^'};
                            despliegaArreglo (camino);
                            cout << "\n ";
                            delay();

                            if (pasada == 2)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 1)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 0)
                            {
                                camino [m][n] = { '$' };
                            }
                            despliegaArreglo (camino);
                            cout << "\n \n";
                            system("/usr/bin/clear");
                        }

                    }

                    if (orientacion == 3)
                    {
                        // k es frente y l es derecha
                        k = m;
                        l = n;
                        k++;
                        l--;
                        if ( laberinto [m][l] == '0' && orientacion == 3 )
                        {
                            orientacion = 4;
                            n = n - 1;

                            if (camino [m][n] == '0' )
                            {
                                pasada = 0;
                            }
                            if (camino [m][n] == '$')
                            {
                                pasada = 1;
                            }
                            if (camino [m][n] == '&' )
                            {
                                pasada = 2;
                            }

                            camino [m][n] = {'<'};
                            despliegaArreglo (camino);
                            cout << "\n ";
                            delay();

                            if (pasada == 2)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 1)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 0)
                            {
                                camino [m][n] = { '$' };
                            }
                            despliegaArreglo (camino);
                            cout << "\n \n";
                            system("/usr/bin/clear");
                        }
                        if ( ( laberinto [k][n] == '0' && laberinto [m][l] == '1' ) && orientacion == 3 )
                        {
                            m = m + 1;

                            if (camino [m][n] == '0' )
                            {
                                pasada = 0;
                            }
                            if (camino [m][n] == '$')
                            {
                                pasada = 1;
                            }
                            if (camino [m][n] == '&' )
                            {
                                pasada = 2;
                            }

                            camino [m][n] = {'v'};
                            despliegaArreglo (camino);
                            cout << "\n ";
                            delay();

                            if (pasada == 2)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 1)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 0)
                            {
                                camino [m][n] = { '$' };
                            }
                            despliegaArreglo (camino);
                            cout << "\n \n";
                            system("/usr/bin/clear");
                        }
                        if ( ( laberinto [k][n] == '1' && laberinto [m][l] == '1' ) && orientacion == 3 )
                        {
                            orientacion = 2;

                            if (camino [m][n] == '0' )
                            {
                                pasada = 0;
                            }
                            if (camino [m][n] == '$')
                            {
                                pasada = 1;
                            }
                            if (camino [m][n] == '&' )
                            {
                                pasada = 2;
                            }

                            camino [m][n] = {'>'};
                            despliegaArreglo (camino);
                            cout << "\n ";
                            delay();

                            if (pasada == 2)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 1)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 0)
                            {
                                camino [m][n] = { '$' };
                            }
                            despliegaArreglo (camino);
                            cout << "\n \n";
                            system("/usr/bin/clear");
                        }

                    }

                    if (orientacion == 4)
                    {
                        // k es derecha y l es frente
                        k = m;
                        l = n;
                        k--;
                        l--;
                        if ( laberinto [k][n] == '0' && orientacion == 4  )
                        {
                            orientacion = 1;
                            m = m - 1;

                            if (camino [m][n] == '0' )
                            {
                                pasada = 0;
                            }
                            if (camino [m][n] == '$')
                            {
                                pasada = 1;
                            }
                            if (camino [m][n] == '&' )
                            {
                                pasada = 2;
                            }

                            camino [m][n] = {'^'};
                            despliegaArreglo (camino);
                            cout << "\n ";
                            delay();

                            if (pasada == 2)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 1)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 0)
                            {
                                camino [m][n] = { '$' };
                            }
                            despliegaArreglo (camino);
                            cout << "\n \n";
                            system("/usr/bin/clear");
                        }
                        if ( ( laberinto [m][l] == '0' && laberinto [k][n] == '1' ) && orientacion == 4 )
                        {
                            n = n - 1;

                            if (camino [m][n] == '0' )
                            {
                                pasada = 0;
                            }
                            if (camino [m][n] == '$')
                            {
                                pasada = 1;
                            }
                            if (camino [m][n] == '&' )
                            {
                                pasada = 2;
                            }

                            camino [m][n] = {'<'};
                            despliegaArreglo (camino);
                            cout << "\n ";
                            delay();

                            if (pasada == 2)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 1)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 0)
                            {
                                camino [m][n] = { '$' };
                            }
                            despliegaArreglo (camino);
                            cout << "\n \n";
                            system("/usr/bin/clear");
                        }
                        if ( ( laberinto [m][l] == '1' && laberinto [k][n] == '1' ) && orientacion == 4  )
                        {
                            orientacion = 3;

                            if (camino [m][n] == '0' )
                            {
                                pasada = 0;
                            }
                            if (camino [m][n] == '$')
                            {
                                pasada = 1;
                            }
                            if (camino [m][n] == '&' )
                            {
                                pasada = 2;
                            }

                            camino [m][n] = {'v'};
                            despliegaArreglo (camino);
                            cout << "\n ";
                            delay();

                            if (pasada == 2)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 1)
                            {
                                camino [m][n] = { '&' };
                            }
                            if (pasada == 0)
                            {
                                camino [m][n] = { '$' };
                            }
                            despliegaArreglo (camino);
                            cout << "\n \n";
                            system("/usr/bin/clear");
                        }

                    }
                    if (laberinto [m+1][n] == '2' || laberinto [m-1][n] == '2' || laberinto [m][n+1] == '2' || laberinto [m][n-1] == '2')
                    {
                        salida = 2;
                    }
                }
                cout << "\n\n ";
                system("/usr/bin/clear");
                camino [q][w] = { '#' };
                camino [m][n] = { '*' };
                despliegaArreglo (camino);
                cout << "\n ";
                cout << yellow << "El robot encontro la salida" << normal;
                cout << "\n \n";
            }
            else
            {
                return 0;
            }  


    }

void despliegaArreglo ( const char laberinto[][ COLUMNAS ] )
{
    int i;
    int j;

    system("/usr/bin/clear");
    cout << "\t\t" << "    AVENIDAS \n" << endl;
    cout << "\t\t" << "    ";
    for (j = 0; j < COLUMNAS - 1; j++)
    {
        cout << j + 1 << " ";
    }
    cout << "\n";

    for ( i = 0; i < FILAS; i++) {

        cout << "\n";
        cout << "\t";

        if (i == 0)
        {
            cout << "C";
        }
        if (i == 1)
        {
            cout << "A";
        }
        if (i == 2)
        {
            cout << "L";
        }
        if (i == 3)
        {
            cout << "L";
        }
        if (i == 4)
        {
            cout << "E";
        }
        if (i == 5)
        {
            cout << "S";
        }

        cout << "\t";
        cout << i + 1;
        if (i == 9)
        {
            cout << "  ";
        }
        else
        {
            cout << "   ";
        }

        for ( j = 0; j <= COLUMNAS - 1; j++)
            {
                if (laberinto [i][j] == '1')
                {
                    cout << blue << laberinto [i][j] << normal;
                    cout <<" ";
                }
                if (laberinto [i][j] == '0')
                {
                    cout << greenb <<laberinto [i][j] << normal;
                    cout <<" ";
                }
                if (laberinto [i][j] == '2')
                {
                    cout << black << laberinto [i][j] << normal;;
                    cout <<" ";
                }
                if (laberinto [i][j] == '^')
                {
                    cout << yellow << laberinto [i][j] << normal;;
                    cout <<" ";
                }
                if (laberinto [i][j] == '>')
                {
                    cout << yellow << laberinto [i][j] << normal;;
                    cout <<" ";
                }
                if (laberinto [i][j] == 'v')
                {
                    cout << yellow << laberinto [i][j] << normal;;
                    cout <<" ";
                }
                if (laberinto [i][j] == '<')
                {
                    cout << yellow << laberinto [i][j] << normal;;
                    cout <<" ";
                }
                if (laberinto [i][j] == '#')
                {
                    cout << yellow << laberinto [i][j] << normal;;
                    cout <<" ";
                }
                if (laberinto [i][j] == '$')
                {
                    cout << red << laberinto [i][j] << normal;;
                    cout <<" ";
                }
                if (laberinto [i][j] == '&')
                {
                    cout << white << laberinto [i][j] << normal;;
                    cout <<" ";
                }
                if (laberinto [i][j] == '*')
                {
                    cout << yellow << laberinto [i][j] << normal;;
                    cout <<" ";
                }



            }
        }
}

    void posicionRobot (int m, int n)
    {
    	cout<< "\n";
        if ( m > FILAS || n > COLUMNAS )
        {
        	cout << red << "Usted a posicionado el robot fuera del laberinto \n" << normal;
        	cout << red << "Intente otra posicion \n" << normal;
        }
        if ( m <= 9 && n <= 9)
        {
        	if (laberinto[ m ][ n ] == '0')
        	{
        		cout << green << "Usted a posicionado el robot en: "<< "(" << x << "," << y << ")" << normal;
                laberinto [m][n] = { '#' };
        	}
        	else
        	{
        	    cout << red << "Usted a posicionado el robot en un lugar no valido" << normal;
        	    cout << red << " \n(existe un muro en esa posicion)\n" << normal;
        	}
        }
    }

    void delay(void)
    {
    	register long t = 0x1FFFFFFF;
    	//register long t = 0xFFFFFFF;
    	while(t--);
    }


