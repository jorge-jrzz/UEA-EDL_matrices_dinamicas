//
//  main.c
//  Proyecto_final
//
//  Created by Jorge Angel Juarez Vazquez on 12/12/22.
//  Matricula: 2213026247
//

#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef _WIN32
  #include <windows.h>
#endif
  #include <unistd.h>

void welcome(void);
void menu(Matriz *matrizA, Matriz *matrizB);
void caso0(Matriz *matrizA, Matriz *matrizB);
void caso1(Matriz *matrizA, Matriz *matrizB);
void caso2(Matriz *matrizA, Matriz *matrizB);
void caso3(Matriz *matrizA);
void caso4(Matriz *matrizB);
void caso5(Matriz *matrizA, Matriz *matrizB);
void caso6(Matriz *matrizA, Matriz *matrizB);
void llenar_matriz(Matriz *matriz, int rows, int columns, char who);
void clean_screen(void);
void key_confir(void);

int main(int argc, const char * argv[]) {
    
    Matriz *matrizA = crear_Matriz();
    Matriz *matrizB = crear_Matriz();
    
    welcome();
    menu(matrizA, matrizB);
    
    free(matrizA);
    free(matrizB);    
           
    return 0;
}

void welcome(void) {
    char nombre[30];
    clean_screen();
    printf("\n\tEstructura de Datos Lineales 22-O");
    printf("\n\tPROYECTO FINAL ");
    printf("\n\nIngrese su nombre:  ");
    fgets(nombre, 30, stdin);
    printf("\nHola %sA continuacion se mostraran opciones para manipular matrices dinamicas que contienen informacion de Uamitos\n\n ", nombre);
    key_confir();
}

void menu(Matriz *matrizA, Matriz *matrizB) {
    int opcion;
    do {
        clean_screen();
        printf("\nIndique ingresando el numero de la opcion que desea realizar y luego presione ENTER (NO ingrese letras o caracteres especiales)\n\n");
        printf("\t 0- Definir o acualizar matrices.\n\t 1- Visualizar matrices. \n\t 2- Producto de 2 matrices [A(MxN) X B(NxR) = AB(MxR)].\n\t 3- Suma de las diagonales de la matriz A.\n\t 4- Búsqueda binaria de un número en la Matriz B.\n\t 5- Elemento más pequeño y grande de la Matrix A y de la Matriz B.\n\t 6- Limpiar matrices. \n\t 7- SALIR.\n");
        printf("\nOpcion:   ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 0:
                clean_screen();
                caso0(matrizA, matrizB);
                key_confir();
                break;
            case 1:
                clean_screen();
                caso1(matrizA, matrizB);
                key_confir();
                break;
            case 2:
                clean_screen();
                caso2(matrizA, matrizB);
                key_confir();
                break;
            case 3:
                clean_screen();
                caso3(matrizA);
                key_confir();
                break;
            case 4:
                clean_screen();
                caso4(matrizB);
                key_confir();
                break;
            case 5:
                clean_screen();
                caso5(matrizA, matrizB);
                key_confir();
                break;
            case 6:
                clean_screen();
                caso6(matrizA, matrizB);
                key_confir();
                break;
            default:
                break;
        }
    }while (opcion != 7);
    printf("\n\n\t VUELVA PRONTO\n\n");
}

void caso0(Matriz *matrizA, Matriz *matrizB) {
    int opcion, rowsA, columnsA, rowsB, columnsB;
    printf("\nDEFINIR O ACTUALIZAR MATRICES\n");
    printf("\nIndique ingresando el número de la opcion de la Matriz que desea definir y luego presione ENTER (NO ingrese letras o caracteres especiales)\n\n");
    printf("\t 1- Matriz A. \n\t 2- Matriz B.\n");
    printf("\nOpcion:   ");
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
            printf("\n*** MATRIZ A ***\n");
            printf("\nNumero de filas:  ");
            scanf("%d", &rowsA);
            printf("\nNumero de columnas:  ");
            scanf("%d", &columnsA);
            llenar_matriz(matrizA, rowsA, columnsA, 'A');
            clean_screen();
            printf("\nMatriz A actualizada con exito.\n");
            print_Matriz(*matrizA);
            break;
        case 2:
            printf("\n\n*** MATRIZ B ***\n");
            printf("\nNumero de filas:  ");
            scanf("%d", &rowsB);
            printf("\nNumero de columnas:  ");
            scanf("%d", &columnsB);
            llenar_matriz(matrizB, rowsB, columnsB, 'B');
            clean_screen();
            printf("\nMatriz B actualizada con exito.\n");
            print_Matriz(*matrizB);
            break;
        default:
            break;
    }
}

void caso1(Matriz *matrizA, Matriz *matrizB) {
    printf("\n VISUALIZACIÓN DE LAS MATRICES.\n");
    printf("\n --- MATRIZ A ---\n");
    print_Matriz(*matrizA);
    printf("\n --- MATRIZ B ---\n");
    print_Matriz(*matrizB);
}

void caso2(Matriz *matrizA, Matriz *matrizB) {
    int columnsA, rowsB;
    printf("\nPRODUCTO DE 2 MATRICES [A(MxN) X B(NxR) = AB(MxR)]\n");
    if (!isEmpty(*matrizA) && !isEmpty(*matrizB)) {
        int rowsA, columnsB;
        printf("\n* Las 2 matrices estan vacías, proporcione lo que se el solicita. *\n");
        printf("\n*** MATRIZ A ***\n");
        printf("\nNumero de filas:  ");
        scanf("%d", &rowsA);
        printf("\nNumero de columnas:  ");
        scanf("%d", &columnsA);
        printf("\n\n*** MATRIZ B ***\n");
        printf("\nNumero de filas:  ");
        scanf("%d", &rowsB);
        printf("\nNumero de columnas:  ");
        scanf("%d", &columnsB);
        clean_screen();
        if(columnsA == rowsB) {
            llenar_matriz(matrizA, rowsA, columnsA, 'A');
            clean_screen();
            llenar_matriz(matrizB, rowsB, columnsB, 'B');
            clean_screen();
            
            Matriz *matriz_resultado = crear_Matriz();
            matriz_resultado = multiplicar(matrizA, matrizB);
            printf("\n --- MATRIZ A ---\n");
            print_Matriz(*matrizA);
            printf("\n --- MATRIZ B ---\n");
            print_Matriz(*matrizB);
            printf("\n --- MATRIZ AB ---\n");
            print_Matriz(*matriz_resultado);
            
        }else printf("\nDimension ERROR: El producto no puede realizarse, introduce tamaños válidos.\n");
        
    }else if(!isEmpty(*matrizA) || !isEmpty(*matrizB)) printf("\n* Una de las 2 matrices esta vacía, verifique y defínela en el menú principal. *\n");
    else {
        Nodo *aux = matrizA->corner_top_A;

        while (aux != matrizA->corner_top_B) { //Obtener el numero de columnas que hay en la matriz A
            aux = aux->next;
            columnsA++;
        }
        aux = matrizB->corner_top_A;
        while (aux->down != NULL) {    //Obtener el numero de filas que hay en la matriz B
            aux = aux->down;
            rowsB++;
        }
        aux = NULL;
        free(aux);

        if(columnsA == rowsB) {
            Matriz *matriz_resultado = crear_Matriz();
            matriz_resultado = multiplicar(matrizA, matrizB);
            printf("\n --- MATRIZ A ---\n");
            print_Matriz(*matrizA);
            printf("\n --- MATRIZ B ---\n");
            print_Matriz(*matrizB);
            printf("\n --- MATRIZ AB ---\n");
            print_Matriz(*matriz_resultado);
            
        }else printf("\nDimension ERROR: El producto no puede realizarse, introduce tamaños válidos.\n");
    }
}

void caso3(Matriz *matrizA) {
    char dec[2];
    printf("\nSUMA DE LAS DIAGONALES DE LA MATRIZ A \n");
    if (!isEmpty(*matrizA)) {
        printf("\nLa Matriz A esta vacia, ¿Desea definir la matriz A?    [Y = yes | N = no]\t");
        scanf("%s", dec);
        if(strcmp(dec, "Y")==0 || strcmp(dec, "y")==0) {
            clean_matriz(matrizA);
            int rowsA, columnsA;
            printf("\n*** MATRIZ A ***\n");
            printf("\nNumero de filas:  ");
            scanf("%d", &rowsA);
            printf("\nNumero de columnas:  ");
            scanf("%d", &columnsA);
            clean_screen();
            llenar_matriz(matrizA, rowsA, columnsA, 'A');
            clean_screen();
        }
    }
    if (isEmpty(*matrizA)) {
        Matriz *suma_diagonales = crear_Matriz();
        printf("\n---Matriz A---\n");
        print_Matriz(*matrizA);
        printf("\n---Lista con las sumas de las diagonales de la matriz A---\n");
        suma_diagonales = suma_diagonal(matrizA);
        print_Matriz(*suma_diagonales);

    }else printf("\nERROR: La matriz esta vacia.\n");
}

void caso4(Matriz *matrizB) {
    int numero = 0;
    printf("\t\nBUSQUEDA BINARIA DE UN ELEMENTO EN LA MATRIZ B\n\n");
    printf("\nProporcione el id que desea buscar en la matriz:\t");
    scanf("%d", &numero);
    if(!isEmpty(*matrizB)) {
        char dec[2];
        printf("\nLa matriz B esta vacia, ¿Desea inicializarla?    [Y = yes | N = no]\t");
        scanf("%s", dec);
        if(strcmp(dec, "Y")==0 || strcmp(dec, "y")==0){
            int rowsB, columnsB;
            printf("\n*** MATRIZ B ***\n");
            printf("\nNumero de filas:  ");
            scanf("%d", &rowsB);
            printf("\nNumero de columnas:  ");
            scanf("%d", &columnsB);
            clean_screen();
            llenar_matriz(matrizB, rowsB, columnsB, 'B');
        }
    } 
    if(isEmpty(*matrizB)) {
        clean_screen();
        printf("\n --- MATRIZ B ---\n");
        print_Matriz(*matrizB);
        printf("\nPara poder realizar la busqueda binaria del número %d, es necesario ordenar la matriz primero.\n", numero);
        key_confir();
        matrizB = ordena(matrizB);
        printf("\n - MATRIZ B ORDENADA -\n");
        print_Matriz(*matrizB);
        search(matrizB, numero);

    }else printf("\nERROR: La Matriz B esta vacia\n");
}

void caso5(Matriz *matrizA, Matriz *matrizB) {
    printf("\n\t ELEMENTO MÁS PEQUEÑO Y GRANDE DE LA MATRIX A Y DE LA MATRIZ B \n\n");
    if(!isEmpty(*matrizA)) {
        char dec[2];
        printf("\nLa matriz A esta vacia, ¿Desea inicializarla?    [Y = yes | N = no]\t");
        scanf("%s", dec);
        if(strcmp(dec, "Y")==0 || strcmp(dec, "y")==0){
            int rowsA, columnsA;
            printf("\n*** MATRIZ A ***\n");
            printf("\nNumero de filas:  ");
            scanf("%d", &rowsA);
            printf("\nNumero de columnas:  ");
            scanf("%d", &columnsA);
            clean_screen();
            llenar_matriz(matrizA, rowsA, columnsA, 'A');
        }
        clean_screen();
    }

    if(!isEmpty(*matrizB)) {
        char dec[2];
        printf("\nLa matriz B esta vacia, ¿Desea inicializarla?    [Y = yes | N = no] \t");
        scanf("%s", dec);
        if(strcmp(dec, "Y")==0 || strcmp(dec, "y")==0) {
            int rowsB, columnsB;
            printf("\n*** MATRIZ B ***\n");
            printf("\nNumero de filas:  ");
            scanf("%d", &rowsB);
            printf("\nNumero de columnas:  ");
            scanf("%d", &columnsB);
            clean_screen();
            llenar_matriz(matrizB, rowsB, columnsB, 'B');
        }
        clean_screen();
    }
    
    if(isEmpty(*matrizA) || isEmpty(*matrizB)) {
        printf("\n --- MATRIZ A ---\n");
        print_Matriz(*matrizA);
        id_less_greater(*matrizA, 'A');
        printf("\n --- MATRIZ B ---\n");
        print_Matriz(*matrizB);
        id_less_greater(*matrizB, 'B');

    }else printf("\nERROR: La dos Matrices estan vacias\n");
}

void caso6(Matriz *matrizA, Matriz *matrizB) {
    printf("\nLIMPIEZA DE MATRICES\n\n");
    if(isEmpty(*matrizA) || isEmpty(*matrizB)) {
        char dec[2];
        printf("\n¿Esta seguro de que quire limpiar 2 matrices?    [Y = yes | N = no]\t");
        scanf("%s", dec);
        if(strcmp(dec, "Y")==0 || strcmp(dec, "y")==0) {
            if(isEmpty(*matrizA)) {
                clean_matriz(matrizA);
                printf("\nMatriz A limpiada con exito.\n");
            }else printf("\nLa Matriz A ya esta vacia\n");
            if(isEmpty(*matrizB)) {
                clean_matriz(matrizB);
                printf("\nMatriz B limpiada con exito.\n");
            }else printf("\nLa Matriz B ya esta vacia\n");

            printf("\n\nCOMPROBACIÓN:\n");
            printf("\n --- MATRIZ A ---\n");
            print_Matriz(*matrizA);
            printf("\n --- MATRIZ B ---\n");
            print_Matriz(*matrizB);

        }else if (strcmp(dec, "N")==0 || strcmp(dec, "n")==0) printf("\nOperación cancelada.\n");

    }else printf("\nLa dos Matrices ya estan vacias\n");
}

void llenar_matriz(Matriz *matriz, int rows, int columns, char who) {
    int fila, columna, valor;
    clean_matriz(matriz);
    clean_screen();
    printf("\nIntroduce los valores en un rango de 0 a 20 para la MATRIZ %c. | tamaño: %d x %d \n", who, rows, columns);
    for (fila = 0; fila < rows; fila++) {
        for (columna = 0; columna < columns; columna++) {
            do {
                printf("\nValor [%d, %d]: ", fila, columna);
                scanf("%d", &valor);
                if(valor < 0 || valor > 20) {
                    printf("\nERROR: Rango invalido, vuleve a introducir el valor:\n");
                }else {
                    printf("\nElemento insertado con exito a la matriz.\n");
                }
            }while(!(valor >= 0 && valor <= 20));
            insert(matriz, crear_Nodo(crear_Uamito(valor)), fila, columna);
        }
    }
}


void clean_screen(void) {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}
void key_confir(void) {
  #ifdef _WIN32
    printf("\n");
    system("pause");
  #else
    printf("\n");
    system("read -n 1 -s -p \"Presiona cualquier tecla para continuar . . .\"");
  #endif
}

