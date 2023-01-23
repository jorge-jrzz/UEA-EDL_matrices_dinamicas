//
//  header.c
//  Proyecto_final
//
//  Created by Jorge Angel Juarez Vazquez on 12/12/22.
//  Matricula: 2213026247
//

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

Data *crear_Uamito(int id) {
    Data *aux = (Data*)malloc(sizeof(Data));
    aux -> id = id;
    return aux;
}

Matriz *crear_Matriz(void) {
    Matriz *aux = (Matriz*)malloc(sizeof(Matriz));
    aux -> corner_top_A = NULL;
    aux -> corner_top_B = NULL;
    aux -> corner_buttom_A = NULL;
    aux -> count = 0;
    return aux;
}

Nodo *crear_Nodo(Data *data) {
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
    aux -> data = data;
    aux -> next = NULL;
    aux -> down = NULL;
    return aux;
}

int isEmpty(Matriz matriz) {    //Si tiene algo, devuelve 0
    if(matriz.count == 0) {
        return 0;
    }else {
        return 1;
    }
}

void insert_column(Matriz *matriz, Nodo *nodo) {    //Procedimiento que insertar un nodo sobre la primera columna (solo para abajo)
    if(isEmpty(*matriz)) {
        matriz -> corner_buttom_A -> down = nodo;
        matriz -> corner_buttom_A = nodo;
    }else {
        matriz -> corner_top_A = nodo;
        matriz -> corner_buttom_A = nodo;
        matriz -> corner_top_B = nodo;
    }
    matriz -> count++;
}

void insert_row(Matriz *matriz, Nodo *nodo) {   //Procedimiento que insertar un nodo sobre la primera fila (solo para el apuntador 'next')
    if(isEmpty(*matriz)) {
        matriz -> corner_top_B -> next = nodo;
        matriz -> corner_top_B = nodo;
    }else {
        matriz -> corner_top_A = nodo;
        matriz -> corner_buttom_A = nodo;
        matriz -> corner_top_B = nodo;
    }
    matriz -> count++;
}

void insert(Matriz *matriz, Nodo *nodo, int rows, int columns) {    //Procedimiento que inserta un nodo en la posicion que se indica (como matriz estatica)
    if(isEmpty(*matriz)) {
        if(rows == 0) {     // si la posicion que se manda de al fila es 0, directamente se inserta en la fila y sale del procedimiento.
            insert_row(matriz, nodo);
            return;
        }
        if(columns == 0) {  // si la posicion que se manda de al columna es 0, directamente se inserta en la columna y sale del procedimiento.
            insert_column(matriz, nodo);
            return;
        }
        
        Nodo *fil = matriz->corner_top_A;
        Nodo *col = matriz->corner_top_A;
        int count = 0;

//Se posiciona el nodo auxiliar sobre la columna donde encuentra un 'hueco'
        while (rows != count) {
            col = col -> down;
            count++;
        }
        while(col->next != NULL) {
            col = col -> next;
        }

//Se posiciona el nodo auxiliar sobre la fila donde encuentra un 'hueco'
        count = 0;
        while(columns != count) {
            fil = fil -> next;
            count++;
        }
        while(fil->down != NULL) {
            fil = fil -> down;
        }

//Se 'pega' el nodo que se manda a la matriz
        col->next = nodo;
        fil->down = nodo;
        matriz -> count++;
    
//Liberacion de memoria
        fil = NULL;
        col = NULL;
        free(fil);
        free(col);

    }else insert_row(matriz, nodo);
}

void print_Matriz(Matriz matriz) {  //Procedimiento para imprimir la matriz con la respectiva forma en la que se realizo.
    if(isEmpty(matriz)) {
        Nodo *aux1 = matriz.corner_top_A;
        Nodo *aux2 = matriz.corner_top_A;
        Data *data = NULL;
        int count = 1;
        printf("\n");
        while(count != matriz.count) {  //Hasta que pase por todos los nodos 
            data = aux1 -> data;
            if(aux1->next == NULL) {    //Si llega al ultimo nodo de una fila
                printf("| %d |", data -> id);
                printf("\n");
                aux2 = aux2->down;
                aux1 = aux2;
                count++;
            }else {
                printf("| %d |", data -> id);
                aux1 = aux1 -> next;
                count++;
            }
        }
        data = aux1 -> data;
        printf("| %d |", data -> id);   //El ultimo elemento de la matriz.
        printf("\n\n\n");

//Liberacion de memoria
        aux1 = NULL;
        aux2 = NULL;
        data = NULL;
        free(aux1);
        free(aux2);
        free(data);

    }else printf("\nERROR: Matriz vacia, no es posible imprimir la matriz\n");
}

void clean_matriz(Matriz *matriz) {    //Procedimiento para limpiar una Matriz (elimina todos los nodos  y deja lista a la matriz para que se vuelvan a insertar nuevos nodos).
    if(isEmpty(*matriz)) {
        Nodo *aux = NULL;
        Nodo *arriba = NULL;
        Nodo *borrar = NULL;
        int count = matriz->count;
        while(count != 0) {     //Hasta que el numero de nodos en la matriz sea 0.
            if(matriz->corner_top_A == matriz->corner_buttom_A) {   
                borrar = matriz->corner_top_A;
                matriz->corner_top_A = matriz->corner_top_A->next;
                aux = matriz->corner_top_A;
                if(count == 1) {    //Aqui termina el procedimiento (cuanto solo queda un Nodo en la Matriz).
                    matriz -> corner_top_A = NULL;
                    matriz -> corner_buttom_A = NULL;
                    matriz -> corner_top_B = NULL;
                    matriz -> count = 0;
                    free(borrar);
                    aux = NULL;
                    arriba = NULL;
                    borrar = NULL;
                    free(aux);
                    free(arriba);
                    free(borrar);
                    return;
                }
                while(aux->down != NULL) {
                    aux = aux->down;
                }
                matriz->corner_buttom_A = aux;
            }else {
//El procedimiento va borrando elemento a elemento pero por columnas, empezando desde la primera. 
                arriba = matriz->corner_top_A;
                borrar = matriz->corner_buttom_A;
                while(arriba->down != borrar) {
                    arriba = arriba->down;
                }
                matriz->corner_buttom_A = arriba;
                arriba->down = NULL;
                borrar->next = NULL;
            }
            free(borrar);
            count--;
        }
    }
//Mensajes del estatus del procedimiento se hacen cuando se manda a llamar el procedimiento.
}

Matriz *multiplicar(Matriz *matrizA, Matriz *matrizB) {   //Funcion que regresa una Matriz resultante de la multiplicacion de las matrices A y B.
    Matriz *resultado = NULL;
    if((isEmpty(*matrizA)) && (isEmpty(*matrizB))) {    //Si las 2 matrices tienen algo.

        Nodo *aux = matrizA->corner_top_A;
        int columnsA=1, rowsA=1, columnsB=1, rowsB=1;

        while (aux != matrizA->corner_top_B) { //Obtener el numero de columnas que hay en la matriz A.
            aux = aux->next;
            columnsA++;
        }
        while (aux->down != NULL) {    //Obtener el numero de filas que hay en la matriz A.
            aux = aux->down;
            rowsA++;
        }

        aux = matrizB->corner_top_A;
        while (aux != matrizB->corner_top_B) { //Obtener el numero de columnas que hay en la matriz B.
            aux = aux->next;
            columnsB++;
        }
        while (aux->down != NULL) {    //Obtener el numero de filas que hay en la matriz B.
            aux = aux->down;
            rowsB++;
        }
        

        resultado = crear_Matriz();
        int fila, columna, valor = 0;
//Se crea una Matriz (resultado de la multiplicacion) con el tamaño esperado, la cual tiene puros 0s como IDs
        for (fila = 0; fila < rowsA; fila++) {
            for (columna = 0; columna < columnsB; columna++) {
                insert(resultado, crear_Nodo(crear_Uamito(valor)), fila, columna);
            }
        }
        
        Nodo *headA = matrizA->corner_top_A;
        Nodo *headB = matrizB->corner_top_A;
        Nodo *headR = resultado->corner_top_A;
        Nodo *auxA = headA;
        Nodo *auxB = headB;
        Nodo *auxR = headR;
        Data *dataA = auxA->data;
        Data *dataB = auxB->data;
        int count, res1 = 0;

/*
Se relaza la multipliaccion de matrices como si se realizara con matrices estaticas; se decidio el uso de la estructura for por la facilidad del manejo de los contadores.
Ejemplo de multiplicacion de matrices estaticas: 
   for (int i = 0; i < N; i++) {
     for (int j = 0; j < N; j++) {
       for (int k = 0; k < N; k++) {
         C[i][j] += A[i][k] * B[k][j];
       }
     }
   }
*/
        for(int i=0; i<=(rowsA-1) ; i++) {
            for(int j=0; j<=(columnsB-1); j++, res1=0) {
                res1 += dataA->id * dataB->id;
                for (count = 1; count<=(rowsB-1); count++) {
                    auxA = auxA->next;
                    auxB = auxB->down;
                    dataA = auxA->data;
                    dataB = auxB->data;
                    res1 += dataA->id * dataB->id;
                }
                auxR->data->id = res1;
                auxR = auxR->next;
                headB = headB->next;
                auxB = headB;
                auxA = headA;
                if(auxB != NULL) {
                    dataA = auxA->data;
                    dataB = auxB->data;
                }
            }
            headA = headA->down;
            headB = matrizB->corner_top_A;
            auxA = headA;
            auxB = headB;
            if(auxA != NULL) {
                dataA = auxA->data;
                dataB = auxB->data;
            }
            headR = headR->down;
            auxR = headR;
        }

//Liberación de memoria.
        headA = NULL;
        headB = NULL;
        headR = NULL;
        auxA = NULL;
        auxB = NULL;
        auxR = NULL;
        dataA =NULL;
        dataB =NULL;
        aux = NULL;
        free(aux);
        free(headA);
        free(headB);
        free(headR);
        free(auxA);
        free(auxB);
        free(auxR);
        free(dataA);
        free(dataB);

    }else {
        printf("\nERROR: Alguna de las matrices esta vacia\n");
        free(resultado);
    }
    return resultado;
}

Matriz *suma_diagonal(Matriz *matrizA) {    //Función para sumar las diagonales de la Matriz A (empezando desde el ultimo Nodo de la primera fila).
    Matriz *sum_diag = NULL;
    if(isEmpty(*matrizA)) {
        
        sum_diag = crear_Matriz();  //Se crea una matriz, la cual contendar las sumas en forma de lista.
        
        Nodo *tope_top = matrizA->corner_top_B;
        Nodo *tope_buttom = matrizA->corner_top_B;
        Nodo *aux = matrizA->corner_top_A;
        Nodo *aux2 = matrizA->corner_top_A;
        Nodo *aux3 = matrizA->corner_top_A;
        
        int rowsA = 1, columnsA = 1;
        while (aux3 != matrizA->corner_top_B) { //Obtener el numero de columnas que hay en la matriz
            aux3 = aux3->next;
            columnsA++;
        }
        while (aux3->down != NULL) {    //Obtener el numero de filas que hay en la matriz
            aux3 = aux3->down;
            rowsA++;
        }
        
        int suma = 0, columna = 0, completas = 0, diagonales = (rowsA + columnsA) - 1; //diagonales representa en numero de sumas en diagonal maximo que pueden existir en una matriz
        bool bajando = false;   //Bandera
        
        suma += tope_top->data->id;
        insert(sum_diag, crear_Nodo(crear_Uamito(suma)), 0, columna); //Se van insertando las sumas en la lista (la fila siempre sera 0 para que solo se insernen en la misma fila).
        suma = 0;
        columna++;
        completas++;
        
        if(columnsA == 1) {
            while(aux != matrizA->corner_buttom_A) {
                aux = aux->down;
                suma = aux->data->id;
                insert(sum_diag, crear_Nodo(crear_Uamito(suma)), 0, columna);
                suma = 0;
                columna++;
            }
        }else {
            while(aux2->next != tope_top) { //Posisiona a aux2 en el que sera el nuevo tope
                aux2 = aux2->next;
            }
            
            while(completas != diagonales) {    //Hasta que se completen todas las sumas
                tope_top = aux2;
                
                //Posisiona al tope de abajo en el lugar correspondiente (a donde termina la diagonal)
                if(tope_buttom->down == NULL)  {
                    aux3 = matrizA->corner_buttom_A;
                    if(completas == (diagonales - 1)) tope_buttom = aux3;
                    else {
                        while (aux3->next != tope_buttom) {
                            aux3 = aux3->next;
                        }
                        tope_buttom = aux3;
                    }
                    
                }else tope_buttom = tope_buttom->down;
                
                //Posisiona al tope de arriva en el lugar correspondiente (donde empieza la daigonal)
                if(bajando == false) {
                    aux2 = matrizA->corner_top_A;
                    if(tope_top == aux2){
                        aux = aux2;
                        bajando = true; //Cuando el tope de arriba llega al primer elemento de la matriz, se tiene que cambiar la forma de mover los apundatores (la bandera indicara el modo de mover los apuntadores)
                    }
                    else if(aux2->next == tope_top) aux = aux2->next;
                    else while(aux2->next != tope_top) {
                        aux2 = aux2->next;
                        if(aux2->next == tope_top) aux = aux2->next;
                    }
                }else {
                    if(aux2->down != NULL) {
                        aux2 = aux2->down;
                        aux = aux2;
                    }else aux = aux2;
                }
                
                suma = aux->data->id;  //Asigna el valor de la suma al numero del primer nodo de la diagonal.
                while (aux != tope_buttom) {
                    if(aux->down != NULL) {
                        aux = aux->down;
                        aux = aux->next;
                        
                    }else break;  //Cuando llega otra vez a la diagonal de un solo nodo.
                    
                    suma += aux->data->id;  //Realiza la suma.
                }
                insert(sum_diag, crear_Nodo(crear_Uamito(suma)), 0, columna);   //Inserta las sumas a la lista
                suma = 0;
                columna++;
                completas++;
            }
        }
        printf("\nLa suma de la diagonales de la Matriz A se ha realizado con exito.\n");
        
//Liberacion de memoria
        tope_top = NULL;
        tope_buttom = NULL;
        aux = NULL;
        aux2 = NULL;
        aux3 = NULL;
        free(tope_top);
        free(tope_buttom);
        free(aux);
        free(aux2);
        free(aux3);

    }else printf("\nLa matriz esta vacia mi loko\n");
    
    return sum_diag;    //Regresa la lista con las sumas en diagonal.
}

void copy_paste(Matriz *matriz_C, Matriz *matriz_V) {
    if(isEmpty(*matriz_C)) {
        Nodo *aux_C = matriz_C->corner_top_A;
        Nodo *aux_C2 = NULL;
        Data *data_C = NULL;
        Nodo *aux_V = NULL;
        Nodo *aux_V2 = NULL;
        Data *data_V = NULL;
        
        int rows_C = 1, columns_C = 1;
        while (aux_C != matriz_C->corner_top_B) { //Obtener el numero de columnas que hay en la matriz.
            aux_C = aux_C->next;
            columns_C++;
        }
        while (aux_C->down != NULL) {    //Obtener el numero de filas que hay en la matriz.
            aux_C = aux_C->down;
            rows_C++;
        }
        
//Se asegura que la matriz destino este vacia para cargar otra vez el numero de nodos correctos.
        clean_matriz(matriz_V);
        
        int fila, columna, valor = 0;
//Se insertan el mismo numero y en la misma dispocicion los nodos de la Matriz que se quiere copiar a la matriz que se quire pegar, la cual tiene puros 0s como IDs.
        for (fila = 0; fila < rows_C; fila++) {
            for (columna = 0; columna < columns_C; columna++) {
                insert(matriz_V, crear_Nodo(crear_Uamito(valor)), fila, columna);
            }
        }
        
        int id, count = 0, total = matriz_C->count;
        aux_C = matriz_C->corner_top_A;
        aux_C2 = aux_C;
        aux_V = matriz_V->corner_top_A;
        aux_V2 = aux_V;
        
        while (count != total) {    //Hasta que haya visitados todo slos nodos de la Matriz.
            while(aux_C != NULL) {
                data_C = aux_C->data;
                data_V = aux_V->data;
                id = data_C->id;    //Obtiene el valor del nodo de la Matriz que se quiere copiar.
                data_V->id = id;    //Ese valor lo pone en el nodo de la misma posicion de la Matriz donde se estan copiando los datos.
                aux_C = aux_C->next;
                aux_V = aux_V->next;
                count++;
            }

//si es que hay mas filas, baja a la siguiente fila para seguir con el copiado.
            if(aux_C2->down != NULL) {
                aux_C2 = aux_C2->down;
                aux_C = aux_C2;
                
                aux_V2 = aux_V2->down;
                aux_V = aux_V2;
            }
        }
        
//Liberación de memoria.
        aux_C = NULL;
        aux_C2 = NULL;
        data_C = NULL;
        aux_V = NULL;
        aux_V2 = NULL;
        data_V = NULL;
        free(aux_C);
        free(aux_C2);
        free(data_C);
        free(aux_V);
        free(aux_V2);
        free(data_V);
        
    }else printf("\nERROR: La Matriz que se quiere duplicar esta vacia. \n");
}

Matriz *ordena(Matriz *matrizB) {   //Función para ordenar una Matriz (cada fila la ordena, sin tomar en cuanta a las otras filas de la Matriz).
    if(isEmpty(*matrizB)) {
        Matriz *temporal = crear_Matriz();
        Nodo *aux = matrizB->corner_top_A;
        Nodo *aux2 = matrizB->corner_top_A;
        Nodo *aux3 = matrizB->corner_top_A;
        Nodo *aux4 = NULL;
        Nodo *aux5 = matrizB->corner_top_A;
        Data *data = NULL;
        
        int count_R = 0, count_C = 0, rowsB = 1, columnsB = 1;
        while (aux3 != matrizB->corner_top_B) { //Obtener el numero de columnas que hay en la matriz
            aux3 = aux3->next;
            columnsB++;
        }
        while (aux3->down != NULL) {    //Obtener el numero de filas que hay en la matriz
            aux3 = aux3->down;
            rowsB++;
        }
        
        int contador = 0, small = 20, total = rowsB * columnsB;
        aux3 = matrizB->corner_top_A;
        
        while (contador != total) { //Hasta que se hayan revisados todos los nodos.
            while(count_R != rowsB) {   //Para cambiar de columna para insertar en la matriz temporal.
                while (aux != NULL) {   //Encuentra el numero mas pequeño de las filas.
                    data = aux->data;
                    if(small > data->id) {  //⇧
                        small = data->id;
                    }
                    aux = aux->next;
                }
                insert(temporal, crear_Nodo(crear_Uamito(small)), count_R, count_C);  //Va insertando los numeros mas pequeños de cada fila en una matriz temporal.
                
                aux4 = aux5;
                while(aux4 != NULL) {   //Cambia el valor pequño de la fila por 100, para que no vuelva a ser considerado para la busqueda del elemento mas pequeño.
                    data = aux4->data;
                    if(small == data->id) {
                        aux4->data->id = 100;   //⇧
                        break;
                    }
                    aux4 = aux4->next;
                }
                aux5 = aux5->down;
                
                small = 21;
                aux2 = aux2->down;
                aux = aux2;
                count_R++;
                contador++;
            }
            count_R = 0;
            count_C++;
            aux2 = aux3;
            aux = aux2;
            aux5 = aux3;
        }

/*  Una vez ordenada la matriz que se manda (B), se borra la matriz temporal no sin antes asignar la matriz ordenada a la matriz que se manda (B) porque es la que se va a regresar en la funcion; para
 esto se creo el procedimiento "void copy_paste(Matriz *matriz_C, Matriz *matriz_V)" para no perder nada de la Matriz ordenada ni la referencia de la Matriz que se manda (B). */
        copy_paste(temporal, matrizB);
        printf("\nLa Matriz se ordeno correctamente\n");
        
//Liberación de memoria.
        temporal = NULL;
        aux = NULL;
        aux2 = NULL;
        aux3 = NULL;
        aux4 = NULL;
        aux5 = NULL;
        data = NULL;
        free(temporal);
        free(aux);
        free(aux2);
        free(aux3);
        free(aux4);
        free(aux5);
        free(data);
        
    }else printf("\nLa matriz esta vacia \n");
    
    return matrizB;
}

void search(Matriz *matrizB, int numero) {    //Procedimiento para buscar un elemento en al matriz (mediante el algoritmo de busqueda binaria)
    int veces = 0;
    if(isEmpty(*matrizB)) {
        Nodo *aux = matrizB->corner_top_A;
        Nodo *mitad = aux;
        Data *data = NULL;
        
        int rowsB = 1, columnsB = 1;
        while (aux != matrizB->corner_top_B) { //Obtener el numero de columnas qu hay en la matriz
            aux = aux->next;
            columnsB++;
        }
        while (aux->down != NULL) {    //Obtener el numero de filas qu hay en la matriz
            aux = aux->down;
            rowsB++;
        }
        
//SE ORDENA EN LA FUNCION DONDE SE QUERE HACER LA BUSQUEDA PARA PODER IMPPRIMIR LA MATRIZ ORDENADA
//        matrizB = ordena(matrizB);  //Ordena de manera asendente las filas de la matriz B
        
        int high = columnsB;
        int low = 0, mid = 0, count_R = 0, count, coo[2];
        
        aux = matrizB->corner_top_A;
        
/*
Se realiza la busqueda en cada fila, cuando se termina la fila se salta a la fila de abajo, y asi hasta que se recorren todos los Nodos.
Entonces las filas son tratadas como arreglos; y se realiza la busqueda binaria como si se tratasen de arreglos estaticos.
Ejemplo de busqueda binaria en arreglo estatico:
while (low <= high) {
    int mid = (low + high) / 2;
    if (array[mid] == key) {
        return mid;
    } else if (array[mid] < key) {
        low = mid + 1;
    } else {
        high = mid - 1;
    }
}
*/
        while (count_R != rowsB) {
            while (low <= high) {
                mid = (high + low) / 2;
                mitad = aux;
                count = 0;
                while(mid != count) {   //Se posiciona en el nodo de en medio
                    mitad = mitad->next;
                    count++;
                }
                if(mitad != NULL) data = mitad->data;
                if(data->id == numero) {    //Primera verificacion
                    veces++;
                    coo[0] = count_R;
                    coo[1] = count;
                    break;
                }else if(data->id > numero) {   //Segunda verificacion
                    high = mid - 1;
                }else if(data->id < numero) {   //Tercera verificacion
                    low = mid + 1;
                }
            }
            count_R++;
            aux = aux->down;
            high = columnsB ;
            low = 0;
        }
        
        if(veces == 0) {
            printf("\nEl ID %d NO se encuentra en la Matriz\n", numero);
        }else {
            printf("\nEl ID %d se encontró %d vez(ces) en la Matriz\n", numero, veces);
            printf("\nLa última pocición de un Nodo que contiene el ID %d es: [%d , %d] \n", numero, coo[0],  coo[1]);
        }
        
//Liberacion de memoria
        aux = NULL;
        mitad = NULL;
        data = NULL;
        free(aux);
        free(mitad);
        free(data);
        
    }else printf("\nLa matriz B esta vacia \n");
}

void id_less_greater(Matriz matriz, char cual) {  //Procedimiento para encontar el numero más pequeño y mas grande de una matrices
    Nodo *aux = NULL;
    Nodo *first = NULL;
    Nodo *aux2 = NULL;
    Data *data = NULL;
    int small, great, count_R, count_C, coo[2];
    
    if(isEmpty(matriz)) {  //Primero se realizara la busqueda en la Matriz A
        aux = matriz.corner_top_A;
        first = matriz.corner_top_A;
        aux2 = matriz.corner_top_A;
        
        int rows = 1, columns = 1;
        while (aux2 != matriz.corner_top_B) { //Obtener el numero de columnas que hay en la matriz
            aux2 = aux2->next;
            columns++;
        }
        while (aux2->down != NULL) {    //Obtener el numero de filas que hay en la matriz
            aux2 = aux2->down;
            rows++;
        }
        
        small = 20;
        great = 0;
        count_R = 0;
        count_C = 0;
        
//Encuentra en número mas pequño de la Matriz.
        aux2 = matriz.corner_top_A;
        while(count_R != rows) {   //Para cambiar de columna donde se buscara el numero
            while (aux != NULL) {   //Encuentra el numero mas pequeño de las filas
                data = aux->data;
                if(small >= data->id) {  //⇧
                    small = data->id;
                    coo[0] = count_R;
                    coo[1] = count_C;
                }
                aux = aux->next;
                count_C++;
            }
            aux2 = aux2->down;
            aux = aux2;
            count_R++;
            count_C = 0;
        }
        printf("\nEl número más pequeño de la Matriz %c es: %d. Y se encuntra en la posición [%d , %d]\n", cual, small, coo[0], coo[1]);
        
//Encuentra en número mas grande de la Matriz.
        count_R = 0;
        aux2 = matriz.corner_top_A;
        aux = aux2;
        while(count_R != rows) {   //Para cambiar de columna donde se buscara el numero
            while (aux != NULL) {   //Encuentra el numero mas grande de las filas
                data = aux->data;
                if(great <= data->id) {  //⇧
                    great = data->id;
                    coo[0] = count_R;
                    coo[1] = count_C;
                }
                aux = aux->next;
                count_C++;
            }
            aux2 = aux2->down;
            aux = aux2;
            count_R++;
            count_C = 0;
        }
        printf("\nEl número más grande de la Matriz %c es: %d. Y se encuntra en la posición [%d , %d]\n", cual, great, coo[0], coo[1]);
        printf("\n----------------------------------------------------------------------------------\n");

//Liberacion de mmemoria
        aux = NULL;
        first = NULL;
        aux2 = NULL;
        data = NULL;
        free(aux);
        free(first);
        free(aux2);
        free(data);
                
    }else printf("\nLa matriz %c esta vacia \n", cual);
}
