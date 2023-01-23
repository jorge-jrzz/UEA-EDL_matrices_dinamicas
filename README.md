# OPERACIONES CON MATRICES DINAMICAS

> Las matrices son un conjunto bidimensional de números o símbolos distribuidos de forma rectangular, en líneas verticales y horizontales, de manera que sus elementos se organizan en filas y columnas. Sirven para describir sistemas de ecuaciones lineales o diferenciales, así como para representar una aplicación lineal. 

### Este prorama consiste en crear y utilizar en diferentes operaciones 2 matrices principales como una estructura de datos lineal, por lo que los nodos que continen los números, se crean y se liberan en tiempo de ejecución. 

* _Una limitante de estas matrices es que solo pueden almacenar numeros en un rango de 0 a 20, si se quiere cambiar esto, es una condición dentro del llenado de la matriz_

## Demo 
* Se muestra un listado con las opciones disponibles para manipular las dos matrices disponobles: 
[![Captura-de-pantalla-2023-01-22-a-la-s-8-15-59-p-m.png](https://i.postimg.cc/Y2RdsxHZ/Captura-de-pantalla-2023-01-22-a-la-s-8-15-59-p-m.png)](https://postimg.cc/HjJ0JXj9)

0. La opción 0 primero pregunrtapor la matriz que se desea actualizar, despues se solicitan las dimensiones de la matriz que selecionaste, siguiendo con el llenado de la matriz y finalmente muestra la impresion de la matriz que se acaba de llenar. 
[![Captura-de-pantalla-2023-01-22-a-la-s-8-42-07-p-m.png](https://i.postimg.cc/2SkGFbMm/Captura-de-pantalla-2023-01-22-a-la-s-8-42-07-p-m.png)](https://postimg.cc/PP71dxdF)
[![Captura-de-pantalla-2023-01-22-a-la-s-8-43-24-p-m.png](https://i.postimg.cc/L8xTy4FP/Captura-de-pantalla-2023-01-22-a-la-s-8-43-24-p-m.png)](https://postimg.cc/68GnqX36)
[![Captura-de-pantalla-2023-01-22-a-la-s-8-43-29-p-m.png](https://i.postimg.cc/KzMDvnk7/Captura-de-pantalla-2023-01-22-a-la-s-8-43-29-p-m.png)](https://postimg.cc/tZ9xBnz7)

1. La opción 1 muestra las dos matrices principales, en caso de qu ealguna de las dos esten vacias, se muestra un error para indicarle al usuario de que esta vacia.   

2. La opción 2 realiza la multiplicacion de las dos matrices y lo muestra en pantalla junto con las dos matrices principales. 
[![Captura-de-pantalla-2023-01-22-a-la-s-8-48-04-p-m.png](https://i.postimg.cc/QdYQQ6ck/Captura-de-pantalla-2023-01-22-a-la-s-8-48-04-p-m.png)](https://postimg.cc/jDNnK4gL)

3. La opción 3 realiza todas las diagonales de la matriz A y las muestra en pantalla en forma de lista. 
[![Captura-de-pantalla-2023-01-22-a-la-s-8-49-33-p-m.png](https://i.postimg.cc/wvYYBQ4g/Captura-de-pantalla-2023-01-22-a-la-s-8-49-33-p-m.png)](https://postimg.cc/LqDbCLMb)

4. La opción 4 realiza la busqueda de un numero dentro de la matriz B, para rrealizar este tipo de busqueda primero se tiene que ordenar la matriz, el ordenamiento se realizo por filas; Primero se pide el numero que se desea buscar, despues se abvierte al usuario que la matriz sera modificada porque se tiene que ordenar y finalmente se muestran los resultados de la busqueda.
[![Captura-de-pantalla-2023-01-22-a-la-s-8-49-44-p-m.png](https://i.postimg.cc/hvSFLPqY/Captura-de-pantalla-2023-01-22-a-la-s-8-49-44-p-m.png)](https://postimg.cc/6211wKqV)

[![Captura-de-pantalla-2023-01-22-a-la-s-8-50-04-p-m.png](https://i.postimg.cc/hvMkpWDt/Captura-de-pantalla-2023-01-22-a-la-s-8-50-04-p-m.png)](https://postimg.cc/5QYK2rQh)

5. La opción 5 muestra en ppantalla el número mas pequeño y mas grande de las 2 matrices con sus respectivas "coordenadas" de las matrices.
[![Captura-de-pantalla-2023-01-22-a-la-s-8-50-21-p-m.png](https://i.postimg.cc/660x9Rrx/Captura-de-pantalla-2023-01-22-a-la-s-8-50-21-p-m.png)](https://postimg.cc/hhf5sXZ2)

6. La opción 6 primero muestra una advertencia, y pide una confirmación sobre la operacion que esta apunto de realizar, en dado caso que el se confirma el borrado de las matrices se muestran mensajes de la operacioin y se muestra una confirmación de la misma; cabe aclarar que esta operación deja disponibles a las matrices para que se llenen nuevamente en las demas opciones del programa. 
[![Captura-de-pantalla-2023-01-22-a-la-s-8-50-53-p-m.png](https://i.postimg.cc/ZK5t0RHB/Captura-de-pantalla-2023-01-22-a-la-s-8-50-53-p-m.png)](https://postimg.cc/py416PgR)

## Code 
El programa se realizo mediante la funcion ***menu()***, en la cual se mandas a llamar a las demas funciones donde se implementaron todo slos casos que se muestran en el menu principal del programa; ademas se creo una bibliioteca que contiene todas las funciones y procedimientos para manipular las matrices dinamicas.
[![code.png](https://i.postimg.cc/hv5f6YMK/code.png)](https://postimg.cc/GTvLsqZf)

## Help 
Una forma de compilar este programa es correr el siguiente comando en la terminal (Se tiene que estar en el directorio donde se encuentran los archivos):

```
gcc *.c -o nombre -I .h
```


## Project status

Este programa se realizo para el proyecto final de la UEA Estructuras de Datos Lineales y no existen intenciones de actualizar el codigo en un futuro.

## Authors

- [@jorge_jrzz](https://github.com/jorge-jrzz)