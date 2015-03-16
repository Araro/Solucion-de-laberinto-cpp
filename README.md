# Solucion-de-laberinto-cpp
Se muestra como se implemento el algoritmo de la mano derecha para la solucion de un laberinto en cpp

El algoritmo se implemento en Ubuntu 14.10 y utiliza la libreria concolor.h configurada para funcionar en linux.

La libreria concolor se puede configurar para funcionar en linux o en windows, 
solo siga las indicaciones mostradas en el archivo concolor.h, cabe destacar que sin esta libreria la compilación del 
archivo laberinto.cpp causara conflictos, asi que existen dos soluciones:

1.- Configurar adecuadamente la libreria concolor.h para el sistema operativo que se esta utilizando.

2.- En todas las instrucciones cout del archivo laberinto.cpp eliminar la parte donde se le asigna el color a la consola.
Ejemplo:
Originalmente esta de esta manera:
cout << cyan << "El laberinto es el siguiente: \n\n" << normal;

Sin la libreria de concolor.h quedaria de la siguiente manera:
cout << "El laberinto es el siguiente: \n\n";

Ademas el archivo laberinto.cpp ejecuta el borrado de consola nativo en linux de la siguiente manera:
system("/usr/bin/clear");

Si usted utiliza windows es necesario configurar el borrado de la consola de froma adecuada segun el sistema operativo donde se ejecute 
el programa.

Cabe destacar que este programa utiliza el algoritmo de la mano derecha para la solucion del laberinto, de tal manera que si usted coloca el robot al lado de una isla, este se quedara dando vueltas alrededor de la isla sin encontrar la salida. 
