//
//  header.h
//  Proyecto_final
//
//  Created by Jorge Angel Juarez Vazquez on 12/12/22.
//  Matricula: 2213026247
//

typedef struct data {
    int id;
}Data;

typedef struct nodo{
    Data *data;
    struct nodo *next;
    struct nodo *down;
}Nodo;

typedef struct matriz{
    Nodo *corner_top_A;         //Esquina superior izquerda
    Nodo *corner_top_B;         //Esquina superior derecha
    Nodo *corner_buttom_A;      //Esquina inferior izquerda
    int count;
}Matriz;

Data *crear_Uamito(int id);
Matriz *crear_Matriz(void);
Nodo *crear_Nodo(Data *data);
int isEmpty(Matriz matriz);
void insert_column(Matriz *matriz, Nodo *nodo);
void insert_row(Matriz *matriz, Nodo *nodo);
void insert(Matriz *matriz, Nodo *nodo, int rows, int columns);
void print_Matriz(Matriz matriz);
void clean_matriz(Matriz *matriz);
Matriz *multiplicar(Matriz *matrizA, Matriz *matrizB);
Matriz *suma_diagonal(Matriz *matrizA);
void copy_paste(Matriz *matriz_C, Matriz *matriz_V);
Matriz *ordena(Matriz *matrizB);
void search(Matriz *matrizB, int numero);
void id_less_greater(Matriz matriz, char cual);
