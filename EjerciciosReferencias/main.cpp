//Codigo creador por Armando Yañez

#include <iostream>
#include <vector>

//Se agrega para usar los punteros inteligentes
#include <memory>


//Creacion de la estructura
struct myStruct{
    int entero;
    char caracter;
    float flotante;
    bool booleano;
};

void EjercicioExtra(){

    //Crear apartado en la memoria de 500 con malloc.
    void* espacio = malloc(500) ;

    //Crear 5 espacios de 500
    void* espacio2 = calloc(5, 500);

    //Dividir en 10 espacios de 200
    espacio2 = realloc(espacio2, 10 * 200);

    std::cout<<_msize(espacio)<<std::endl;
    std::cout<<_msize(espacio2)<<std::endl;

    free(espacio);
    free(espacio2);
}

void EjercicioExtra2(){

    int i = 5;

    //Creando el espacio de memoria donde se guardara i
    int &refi = i;

    int j = i;
    j = 25;


    int *p1 = new int(11); //Apunta al jit (manda llamar a maloc)
    int *p2 = p1;
    *p1 = 25;

    //Declración de vector
    std::vector<int> vectorElementos = {5,25};

    //Declaracion de vector con el mismo numero (numero de celdas , relleno)
    std::vector<int> vectorElementosP (4, 0);


    int *p3 = new int(2); //Apunta al jit (manda llamar a maloc)
    int *p4 = new int(1); //Apunta al jit (manda llamar a maloc)

    int *pp3 = p3;
    *p3 = 30;

    int *pp4 = p4;
    *p4 = 10;

    //Imprmir valor
    std::cout<<*p2<<std::endl;

    //Practica

    //Imprimir direccion de memoria
    std::cout<<p2<<std::endl;
    std::cout<<p1<<std::endl;

    std::cout<<*p3<<std::endl;
    std::cout<<*p4<<std::endl;

    delete pp3;
    delete pp4;

    std::cout<<&refi<<std::endl;
    std::cout<<i<<std::endl;
    std::cout<<j<<std::endl;
}

void Ejercicio1(){

    //Creamos int y espacio de memoria en malloc
    int *entero = (int*) malloc(sizeof(int)); //Aparta espacio de memoria

    //& -> La direccion de
    //* -> indireccion
    //Estos son operadores "uniarios"

    *entero = 50;
    std::cout<<*entero<<std::endl;

    free(entero);
}

void Ejercicio2y3(){

    int *arregloint = (int*) calloc(20, sizeof (int));

    for(int i = 0;i < 20;i++){
        *(arregloint + i) = i;
        std::cout<<*(arregloint+i)<<std::endl;
    }
    std::cout<<_msize(arregloint)<<std::endl;

    int *ArregloAmpleado = (int*) realloc(arregloint, (2* _msize(arregloint)));
    arregloint = ArregloAmpleado;
    std::cout<<_msize(arregloint)<<std::endl;

    //Rellenamos nuevamente
    for(int i = 20;i < 40;i++){
        *(arregloint + i) = i;
        std::cout<<*(arregloint+i)<<std::endl;
    }

    free(arregloint);
    free(ArregloAmpleado);
}

void Ejercicio4(){

    int *p1 = new int;
    *p1 = 10;
    std::cout<<*p1<<std::endl;

    delete p1;
}

void Ejercicio5(){

    int *p1Arreglo = new int[20];

    for(int i = 0;i < 20;i++){
        *(p1Arreglo + i) = i;
        std::cout<<*(p1Arreglo+i)<<std::endl;
    }
}

void Ejercicio6(){
    myStruct *structPer = new myStruct;
    structPer->entero=10;
    structPer->caracter='a';
    structPer->booleano=true;
    structPer->flotante=1.2;

    delete structPer;
}

void Ejercicio7(){
    myStruct *structPer2 = (myStruct*)malloc(sizeof(myStruct));
    structPer2->entero=5;
    structPer2->caracter='b';
    structPer2->booleano=false;
    structPer2->flotante=43.3;

    free(structPer2);
}

void Ejercicio8(){
    myStruct *arregloStruct = (myStruct*) calloc(5, sizeof (myStruct));

    //(Experimento) rellenar este arreglo

    // Puntero para recorrer la memoria
    myStruct *puntero = arregloStruct;
    for(int i = 0; i < 5; i++) {
        puntero->entero = i; // Asignar valores para el entero
        puntero->caracter = 'A' + i; // Asignar caracteres A, B, C, D, E
        puntero->flotante = 1.5f * i; // Asignar valores flotantes 0.0, 1.5, 3.0, 4.5, 6.0
        puntero->booleano = (i % 2 == 0); // Asignar valores booleanos alternados true/false

        puntero++;
    }

    // Imprimir el contenido
    puntero = arregloStruct;
    for(int i = 0; i < 5; i++) {
        std::cout << "Elemento " << i << ":\n";
        std::cout << "Entero: " << puntero->entero << std::endl;
        std::cout << "Caracter: " << puntero->caracter << std::endl;
        std::cout << "Flotante: " << puntero->flotante << std::endl;
        std::cout << "Booleano: " << puntero->booleano << std::endl;
        std::cout << std::endl;

        puntero++;
    }
    free(arregloStruct);
}

void Ejercicio9(){
    std::unique_ptr<int> ptrEntero(new int);

    *ptrEntero = 9;

    std::cout << "Valor: " << *ptrEntero << std::endl;
    //En este caso no es necesario liberarlo ya que el puntero lo hace por si solo.
}

void Ejercicio10(){
    //Se crea el primer arreglo
    int *arregloDividido = (int*)calloc(10, sizeof(int));

    //Se divide el espacio a la mitad
    int *nuevoArreglo = (int*)realloc(arregloDividido, 5 * sizeof(int));
    arregloDividido = nuevoArreglo;
    free (nuevoArreglo);
    free(arregloDividido);
}


int main() {

    Ejercicio1();
    Ejercicio2y3();
    Ejercicio4();
    Ejercicio5();
    Ejercicio6();
    Ejercicio7();
    Ejercicio8();
    Ejercicio9();
    Ejercicio10();

    return 0;
}