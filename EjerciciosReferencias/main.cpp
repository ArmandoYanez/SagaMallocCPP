//Codigo creador por Armando Yañez

#include <iostream>
#include <vector>

struct myStruct{
    int entero;
    char caracter;
    float flotante;
    bool booleano;
};

int main() {

    /*
   //Ejercicio 1
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


   //Ejercicio 2
   //Creamos int y espacio de memoria en malloc
   int *entero = (int*) malloc(sizeof(int)); //Aparta espacio de memoria

   //& -> La direccion de
   //* -> indireccion
   //Estos son operadores "uniarios"

   *entero = 50;
   std::cout<<*entero<<std::endl;


   //Ejercicio 3
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
*/

   //Ejercicio 4
   int *p1 = new int;
   *p1 = 10;
   std::cout<<*p1<<std::endl;

   delete p1;

   //Ejercicio 5
   int *p1Arreglo = new int[20];

    for(int i = 0;i < 20;i++){
        *(p1Arreglo + i) = i;
        std::cout<<*(p1Arreglo+i)<<std::endl;
    }

    //Ejercicio 6
    myStruct *structPer = new myStruct;
    structPer->entero=10;
    structPer->caracter='a';
    structPer->booleano=true;
    structPer->flotante=1.2;

    myStruct *structPer2 = (myStruct*)malloc(sizeof(myStruct));
    structPer2->entero=5;
    structPer2->caracter='b';
    structPer2->booleano=false;
    structPer2->flotante=43.3;

    free(structPer2);
    delete structPer;
    /*
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
    */

    return 0;
}
