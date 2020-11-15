# Práctica de estrategias de búsqueda

## Objetivo

El objetivo del desarrollo de la actividad práctica es la utilización de estrategias de búsqueda como propuesta de resolución en la determinación de la planificación de trayectorias para coches autónomos. 

## Descripción del problema

El entorno del coche autónomo se puede suponer rectangular de dimensiones M x N y constituido por celdas libres y ocupadas, donde el coche puede efectuar acciones de movimiento, una cada vez, desde la casilla actual a una de las 4-vecinas (Norte, Sur, Este u Oeste) que no se encuentre ocupada. Las casillas ocupadas corresponden a obstáculos. Las casillas libres corresponden con celdas libres de obstáculos.

## Ejecución del programa

Para empezar nos tenemos que dirigir a build/:
    
    $ cd build/

Luego ahí ejecutaremos el make file:
    
    $ make all

Esto creará un ejecutable en el directorio bin/, vamos a allí:
    
    $ cd ../bin/

Ahí tendremos nuestro ejecutable. Para ejecutarlo haremos:
    
    $ ./pr_1_estrategias_busqueda

Si queremos borrar el ejecutable, tendremos que dirigirnos a build/ y hacer:

    $ make clean

## Como usarlo

En la generación random:
1. Se pedirá que introduzca un valor del 0 al 0.99 que indicará la densidad de obstaculos
2. Luego se pedirá el numero de filas M y el numero de columnas N
3. Ahora se pedirá si el recorrido tiene bordes
4. Ahora pedirá si quieres elegir donde está la entrada y el final, si responde que si se elije random y se pasa al 5
    4.1 Nos pedirá las coordenadas de la entrada
    4.2 Nos pedirá las coordenadas de la salida
En la generacion manual:
1. Se pedirán las dimensiones del laberinto M x N
2. Ahora nos pedirá si queremos añadir bordes al circuito
3. En el siguiente paso tendremos que elegir un inicio y un final
4. En este paso elegiremos el numero de obstaculos y donde colocarlos
En la generación por fichero:
1. Se especificará el nombre del fichero (Carpeta donde guardas los propios mapas "../resources/mapa.txt") Ir al 5
IMPORTANTE: la sintaxis utilizada en los ficheros es diferente a la que se muestra en la consola

Parte de la Heuristica:
5. Saldrán las funciones Heuristicas, tendremos que elegir una del 1 al 3
    5.1 Euclidea o usual
    5.2 Taxi o manhattan
    5.3 Maxima



## Datos importantes

En el directorio resources, se encuentra por defecto algunos mapas topologicos de laberitos, se recomienda mirar para ver la sintanxis:
    
    + -> Pared
    > -> Comienzo
    X -> Final

Al Final de cada ejecución aunque el final y el principio esten desconectados (No hay camino), se mostrára unas líneas que nos indicarán:
- Tiempo de ejecución (Si el laberinto es muy grande las unidades varían)
- Nodo expandidos
- Longitud del camino minimo 

Si se pone o llega a coincidir la meta con el final se mostrará un laberinto con una sola X en el que los nodos expandidos serán igual a 0, igual que la longitud.
## Visualización del laberinto

Si el resultado del recorrido es una matriz muy grande se guardará en (resources/resultados.txt) < 400
    
    · -> Hueco libre
    █ -> obstaculo
    * -> Visitado
    X -> Final
    > -> Comienzo
    # -> Ruta
    ? -> desconocido

## Observaciones

El programa soporta una matrix grande, pero para tener la solución en menos de 20 segundos se recomienda usar una dimiensión inferior a 5000 x 5000 o esa misma.
