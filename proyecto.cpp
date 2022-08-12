/*
PROYECTO FINAL
Programa: Calculadora Romana
Autores: Santiago Guarguati y David Santiago lopez Lazaro
*/

#include <iostream>
#include <locale.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iterator>
#include <cmath>
#define MAX 10

using std::cout; 
using std::endl;
using std::cin;
using std::string; 
using std::reverse;


//prototipos 
void saludo(void); 

void menuPrincipal();
void menuMatrices(int matriz1[100][100], int matriz2[100][100], int Tamano);
void menuNumeros(int num1, int num2);

int romanoAEntero(string rstr);
void enteroARomano(int numero);

//Funciones enteros
int sumaEnteros(int num1, int num2);
int restaEnteros(int num1, int num2);
int multiplicacionEnteros(int num1, int num2);
int divisionEnteros(int num1, int num2);

void sumaMatrices(int matriz1[100][100], int matriz2[100][100], int tamano); //cree una void donde le entran dos matrices y un tamaño lo importante es no declarar el primer tamaño de las matrices 
void restaMatrices(int matriz1[100][100], int matriz2[100][100], int tamano);
void multiplicacionMatrices(int matriz1[100][100], int matriz2[100][100], int tamano);
int determinante(int matriz[][MAX], int orden);	

int cofactor(int matriz[][MAX], int orden, int fila, int columna);																	

using namespace std;

//main
int main(){
	system("cls");	//Limpia la consola
	setlocale(LC_ALL,""); 	//caracteres especiales
	saludo(); 		//llama la funcion saludo saludo
	menuPrincipal(); 	//llama a la funcion menu
	return 0;
}

//Saludo
void saludo(void){
	system("color f0");
	printf("\t\t UNIVERSIDAD DISTRITAL FRANCISCO JOSÉ DE CALDAS \n\n");
    cout<<"PROYECTO CALCULADORA ROMANA \n";
    cout<<"Santiago Guarguati y David Santiago lópez Lazaro\n\n";
    printf("\t\t     *      *    ***    \n");
    printf("\t\t     *      *    **    \n");
    printf("\t\t     *      *    ****   \n");
    printf("\t\t     *      *    *       **   \n");
	printf("\t\t     *      *    *        **  \n");
    printf("\t\t     *      *    *         **  \n");
    printf("\t\t     *      *    *         **  \n");
	printf("\t\t     *      *    *         *  \n");
    printf("\t\t     *      *    *        *   \n");
    printf("\t\t     *      *    *      *\n");
    printf("\t\t     ****    ***  \n");
    printf("\t\t     ****    **    \n");
    printf("\t\t     ****    ***   \n\n");    
}

//Menú
void menuPrincipal(){
	int opcion;
	cout<<"¿Qué desea operar? \n";
	cout<<"1.Matrices \n";
	cout<<"2.Números naturales \n";
	cout<<"3.Salir \n";
	cout<<"Digite el número de la opción: ";cin>>opcion;cout<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
	
	while(opcion != 3){
		if(opcion == 1){
			int tam;
			cout<<"Ha seleccionado Matrices \n";
			cout<<"Digite el tamaño de la matriz: ";cin>>tam;
			int matriz1[100][100];
			string matrizRomano1[100][100];
			int matriz2[100][100];
			string matrizRomano2[100][100];
			
			//rellenar la matriz 1
			cout<<"\t\t Primera Matriz\n";
			for(int i=0; i<tam; i++){
				for(int j=0; j<tam; j++){
					cout<<"Digite el número romano de la posición "<< i << ", "<< j<<" para la primera matriz: " ;
					cin>>matrizRomano1[i][j];
					if(matrizRomano1[i][j].find("IIII")<100 || matrizRomano1[i][j].find("VV")<100 || matrizRomano1[i][j].find("XXXXX")<100 || matrizRomano1[i][j].find("LL")<100 || matrizRomano1[i][j].find("CCCCC")<100 || matrizRomano1[i][j].find("DD")<100){
						cout<< "Este número no es correcto, ";
						cout<< "el número contiene IIII o VV o XXXXX o LL o CCCCC o DD por lo tanto debe escribirlo bien";
						exit(0);
					}
					matriz1[i][j]=romanoAEntero(matrizRomano1[i][j]);
				}
			}
			
			//mostrar la matriz 1 de enteros
			cout << "\n\tMatriz 1 de enteros \n";
			for(int i=0;i<tam;i++){
				for(int j=0;j<tam;j++)
					cout<<matriz1[i][j]<<"   	";
					cout<<endl;
			}
			//mostrar la matriz 1 de romanos
			cout << "\n\tMatriz 1 de romanos \n";
			for(int i=0;i<tam;i++){
				for(int j=0;j<tam;j++)
					cout<<matrizRomano1[i][j]<<"  	 ";
					cout<<endl;
			}
			//rellenar la matriz 2 
			cout<<endl;
			cout<<"\t\t Segunda Matriz\n";
			for(int i=0;i<tam;i++){
				for(int j=0;j<tam;j++){
					cout<<"Digite el número romano de la posición "<< i << ", "<< j<<" para la segunda matriz: " ;
					cin>>matrizRomano2[i][j];
					if(matrizRomano2[i][j].find("IIII")<100 || matrizRomano2[i][j].find("VV")<100 || matrizRomano2[i][j].find("XXXXX")<100 || matrizRomano2[i][j].find("LL")<100 || matrizRomano2[i][j].find("CCCCC")<100 || matrizRomano2[i][j].find("DD")<100){
						cout<< "Ese número no es correcto, ";
						cout<< "el número contiene IIII o VV o XXXXX o LL o CCCCC o DD por lo tanto debe escribirlo bien";
						exit(0);//TOCA HACER QUE VUELVA A ESCRIBIR EL NUMERO
					}
					matriz2[i][j]=romanoAEntero(matrizRomano2[i][j]);
				}
			}
			//mostrar la matriz 2
			cout << "\n\tMatriz 2 de enteros \n";
			for(int i=0;i<tam;i++){
				for(int j=0;j<tam;j++)
					cout<<matriz2[i][j]<<"  	 ";
					cout<<endl;
			}
			
			//mostrar la matriz 2 de romanos
			cout << "\n\tMatriz 2 de romanos \n";
			for(int i=0;i<tam;i++){
				for(int j=0;j<tam;j++)
					cout<<matrizRomano2[i][j]<<"  	 ";
					cout<<endl;
			}
			menuMatrices(matriz1 ,matriz2 ,tam); //llama a la funcion menuMatrices
		}
		
		if(opcion == 2){			
			cout<<"Ha seleccionado Numeros naturales \n";
			string NumeroRomano1; //declaracion de strings
			string NumeroRomano2; //declaracion de strings
			cout<<"\nIngrese el primer número \n";
			cin >> NumeroRomano1;
			if(NumeroRomano1.find("IIII")<100||NumeroRomano1.find("VV")<100||NumeroRomano1.find("XXXXX")<100||NumeroRomano1.find("LL")<100||NumeroRomano1.find("CCCCC")<100||NumeroRomano1.find("DD")<100){
				cout<< "Este número no es correcto, ";
				cout<< "el número contiene IIII o VV o XXXXX o LL o CCCCC o DD por lo tanto debe escribirlo bien";
				exit(0);
			}  
			cout<<"Ingrese el segundo número \n";
			cin >> NumeroRomano2;
			if(NumeroRomano2.find("IIII")<100||NumeroRomano2.find("VV")<100||NumeroRomano2.find("XXXXX")<100||NumeroRomano2.find("LL")<100||NumeroRomano2.find("CCCCC")<100||NumeroRomano2.find("DD")<100){
				cout<< "Este número no es correcto, ";
				cout<< "el número contiene IIII o VV o XXXXX o LL o CCCCC o DD por lo tanto debe escribirlo bien";
				exit(0);
			}  
			//Numero entero igual a la funcion deRomanoAEntero		
	  		int NumeroEntero1 = romanoAEntero(NumeroRomano1);
	  		int NumeroEntero2 = romanoAEntero(NumeroRomano2);
	  		
			cout << "El primer número ingresado fue: " << NumeroEntero1 << " o " << NumeroRomano1 << "\n";
			cout << "El segundo número ingresado fue: " << NumeroEntero2 << " o " << NumeroRomano2 << "\n";	
			cout<<endl;
			menuNumeros(NumeroEntero1, NumeroEntero2);
		}
		if(opcion>3 || opcion<1){	 
			cout<<"\nDigite una opción válida \n";
		}
		cout << "\nDesea continuar haciendo operaciones?\n";
		cout << "1.si\n";
		cout << "2.no\n";
		int continuar;
		cin >> continuar;
		if(continuar == 1){
			system("cls");
			saludo();
			menuPrincipal();
		}
		if(continuar == 2){
			printf("\nGracias por usar nuestro servicio.\n");
			system("PAUSE");
			exit(0);
		}
	}	
}

//menu matrices
void menuMatrices(int matriz1[100][100] , int matriz2[100][100] , int Tamano){
	int opcion;
	cout<<"\n¿Qué operación desea realizar? \n";
	cout<<"1.Suma \n";
	cout<<"2.Resta \n";
	cout<<"3.Multiplicación\n";
	cout<<"4.División \n";
	cout<<"5.Determinante \n";
	cout<<"Digite el número de la opción: ";cin>>opcion;cout<<endl;
	
	switch(opcion){
		case 1:
			cout<<"Ha seleccionado Suma \n";
			sumaMatrices(matriz1 ,matriz2 ,Tamano);
			break;
		case 2:
			cout<<"Ha seleccionado Resta \n";
			restaMatrices(matriz1 ,matriz2 ,Tamano);
			break;
		case 3:
			cout<<"Ha seleccionado Multiplicación \n";
			multiplicacionMatrices(matriz1 ,matriz2 ,Tamano);
			break;
		case 4:
			cout<<"Ha seleccionado división \n";
			cout << "No se puede realizar la división ya que se debe hallar la inversa de la segunda matriz, lo que da 0 \n";
			break;
		case 5:
			cout<<"Ha seleccionado determinante \n";
			int Matriz1d[MAX][MAX];
			int Matriz2d[MAX][MAX];
			for(int i=0;i<Tamano;i++){
				for(int j=0;j<Tamano;j++){
					Matriz1d[i][j] = matriz1[i][j];
				}				
			}	
			for(int i=0;i<Tamano;i++){
				for(int j=0;j<Tamano;j++){
					Matriz2d[i][j] = matriz2[i][j];
				}				
			}	
			cout << "El determinante de la primera matríz es (Enteros): ";
			cout << determinante(Matriz1d, Tamano) ;
			cout << "\n";
			
			cout << "El determinante de la primera matríz es (Romanos): ";
			enteroARomano(determinante(Matriz1d, Tamano));
			cout << "\n";		
			
			cout << "El determinante de la segunda matríz es (Enteros): ";
			cout << determinante(Matriz2d, Tamano) ;
			cout << "\n";
			
			cout << "El determinante de la primera matríz es (Romanos): ";
			enteroARomano(determinante(Matriz2d, Tamano));
			cout << "\n";
			break;
		default: cout<<"Digite una opción válida \n";
	}
}

//menu numeros
void menuNumeros(int num1, int num2){
	int opcion;
	cout<<"¿Qué operacion desea realizar? \n";
	cout<<"1.Suma \n";
	cout<<"2.Resta \n";
	cout<<"3.Multiplicación \n";
	cout<<"4.División \n";
	cout<<"Digite el número de la opción: ";cin>>opcion;cout<<endl;
	
	switch(opcion){
		case 1:
			cout<<"Ha seleccionado Suma\n";
			cout<< num1 << " + " << num2 << " = " << sumaEnteros(num1, num2) << "\n";
			enteroARomano(num1); //muestra el n?mero 1 en romano
			cout << " + ";
			enteroARomano(num2); //muestra el n?mero 2 en romano
			cout << " = ";
			enteroARomano(sumaEnteros(num1, num2)); //muestra la suma en números romanos
			cout << "\n";
			break;
		case 2:
			cout<<"Ha seleccionado Resta \n";
			if(restaEnteros(num1,num2) >= 0){
				cout<< num1 << " - "<< num2 << " = " << restaEnteros(num1, num2) << "\n";
				enteroARomano(num1); //muestra el n?mero 1 en romano
				cout<< " - ";
				enteroARomano(num2); //muestra el n?mero 2 en romano
				cout<< " = ";
				enteroARomano(restaEnteros(num1, num2)); //muestra la resta en números romanos
				cout<<"\n";
			}else{
				cout<<"La resta da negativa y no puede ser expresada en números romanos \n";
				cout<<"La resta en enteros es: " << num1 << " - " << num2 << " = " << restaEnteros(num1, num2) << "\n";			
			}
			break;
		case 3:
			cout<<"Ha seleccionado multiplicación \n";
			cout<< num1 << " * " << num2 << " = " << multiplicacionEnteros(num1, num2) << "\n";
			enteroARomano(num1); //muestra el número 1 en romano
			cout << " * ";
			enteroARomano(num2); //muestra el número 2 en romano
			cout << " = ";
			enteroARomano(multiplicacionEnteros(num1, num2)); //muestra la multiplicacion en números romanos
			cout << "\n";
			break;
		case 4:
			cout<<"Ha seleccionado división \n";
			if(num2 != 0){
				cout<< num1 << " / "<< num2 << " = " << divisionEnteros(num1, num2) << "\n";
				enteroARomano(num1); //muestra el número 1 en romano
				cout<< " / ";
				enteroARomano(num2); //muestra el número 2 en romano
				cout<< " = ";
				enteroARomano(divisionEnteros(num1, num2)); //muestra la division en números romanos
				cout<<"\n";
			}else{
				cout<<"La división no se puede hacer ya que no existe división por 0 \n";		
			}
			break;
		default: cout<<"Digite una opción válida \n";
		menuNumeros(num1, num2); //lo lleva al menu de numeros enteros otra vez
	}
}

// Operaciones de enteros
int sumaEnteros(int num1, int num2){
	return num1 + num2;
}
int restaEnteros(int num1, int num2){
	return num1 - num2;
}
int multiplicacionEnteros(int num1, int num2){
	return num1 * num2;
}
int divisionEnteros(int num1, int num2){
	return num1 / num2;
}
//Suma de matrices
void sumaMatrices(int matriz1[100][100], int matriz2[100][100], int tamano){
	
	int matrizSumada[tamano][tamano];
	
	//sumar las matrices
	for(int i=0;i<tamano;i++){
		for(int j=0;j<tamano;j++)
			matrizSumada[i][j] = matriz1[i][j] + matriz2[i][j];
	}
	//mostrar la matriz sumada en enteros
	cout << "\nLa suma de matrices (enteros) da: \n";
	for(int i=0;i<tamano;i++){
		for(int j=0;j<tamano;j++)
			cout<<matrizSumada[i][j]<<"  	 ";
			cout<<endl;
	}
	//mostrar la matriz sumada en romanos
	cout << "\nLa suma de matrices (romanos) da: \n";
	for(int i=0; i<tamano; i++){
		for(int j=0; j<tamano; j++){
			enteroARomano(matrizSumada[i][j]);
			cout<<"  	 ";
		}
		cout<<endl;
	}
}

//Resta de matrices
void restaMatrices(int matriz1[100][100], int matriz2[100][100], int tamano){
	
	int matrizRestada[tamano][tamano];
	
	//Resta las matrices
	for(int i=0;i<tamano;i++){
		for(int j=0;j<tamano;j++)
			matrizRestada[i][j] = matriz1[i][j] - matriz2[i][j];
	}
	//mostrar la matriz restada en enteros
	cout << "\nLa resta de matrices (enteros) da: \n";
	for(int i=0;i<tamano;i++){
		for(int j=0;j<tamano;j++)
			cout<<matrizRestada[i][j]<<"  	 ";
			cout<<endl;
	}
	
	//mostrar la matriz restada en romanos
	cout << "\nLa resta de matrices (romanos) da: \n";
	for(int i=0;i<tamano;i++){
		for(int j=0;j<tamano;j++){
			if (matrizRestada[i][j]<0){
				cout<<"La resta da negativa y no puede ser expresada en números romanos";
				i=tamano;
				j=tamano;
			}else{
				enteroARomano(matrizRestada[i][j]);
				cout<<"  	 ";
			}
		}
		cout<<endl;
	}
}

//Multiplicación de matrices
void multiplicacionMatrices(int matriz1[100][100], int matriz2[100][100], int tamano) {

    int matrizMultiplicada[100][100];

    for (int row = 0; row < tamano; row++) {
        for (int col = 0; col < tamano; col++) {
            // Multiply the row of A by the column of B to get the row, column of product.
            for (int inner = 0; inner < tamano; inner++) {
                matrizMultiplicada[row][col] += matriz1[row][inner] * matriz2[inner][col]; //multiplicación de las 2
            }
        }
    }
    
    //mostrar la matriz multiplicada 
	cout << "La multiplicación de matrices da (enteros): \n";
	for(int i=0;i<tamano;i++){
		for(int j=0;j<tamano;j++)
			cout<<matrizMultiplicada[i][j]<<"  ";
			cout<<endl;
	}
	//mostrar la matriz multiplicada en romanos
	cout << "La multiplicación de matrices da (romanos): \n";
	for(int i=0;i<tamano;i++){
		for(int j=0;j<tamano;j++){
			enteroARomano(matrizMultiplicada[i][j]);
			cout<<"  ";
		}
		cout<<endl;
	}
}

//Determinante de las matrices
int determinante(int matriz[][MAX], int orden){
   int det = 0.0;
   
   if (orden == 1) {
   		det = matriz[0][0];
   } else {
   for (int j = 0; j < orden; j++) {
   		det = det + matriz[0][j] * cofactor(matriz, orden, 0, j);
	}
   }
   return det;
}

//cofactor usado en la funcion determinante
int cofactor(int matriz[][MAX], int orden, int fila, int columna)
{
   int submatriz[MAX][MAX];
   int n = orden - 1;
   
   int x = 0;
   int y = 0;
   for (int i = 0; i < orden; i++) {
      for (int j = 0; j < orden; j++) {
         if (i != fila && j != columna) {
            submatriz[x][y] = matriz[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }
   
   return pow(-1.0, fila + columna) * determinante(submatriz, n);
}

//traduce numeros romanos a enteros
int romanoAEntero(string rstr) {
        int n = int(rstr.length());
        if (0 == n) {
            return 0;
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            switch (rstr[i]) {
                case 'I':
                    result += 1;
                    break;
                case 'V':
                    result += 5;
                    break;
                case 'X':
                    result += 10;
                    break;
                case 'L':
                    result += 50;
                    break;
                case 'C':
                    result += 100;
                    break;
                case 'D':
                    result += 500;
                    break;
                case 'M':
                    result += 1000;
                    break;
            }
        }

        for (int i = 1; i < n; i++) {
            if ((rstr[i] == 'V' || rstr[i] == 'X') && rstr[i - 1] == 'I') {
                result -= 1 + 1;
            }

            if ((rstr[i] == 'L' || rstr[i] == 'C') && rstr[i - 1] == 'X') {
                result -= 10 + 10;
            }

            if ((rstr[i] == 'D' || rstr[i] == 'M') && rstr[i - 1] == 'C') {
                result -= 100 + 100;
            }
        }
        return result;
    }
    
//traduce numeros enteros a romanos    
void enteroARomano(int numero){
	int unidades, decenas, centenas, millares;
	
	unidades = numero % 10; numero /= 10;
 	decenas = numero % 10; numero /= 10;
 	centenas = numero % 10; numero /= 10;
 	millares = numero % 10; numero /= 10;

 	switch (millares)
 	{
  		case 1: cout<<"M"; break;
  		case 2: cout<<"MM"; break;
  		case 3: cout<<"MMM"; break;
 	}
 
 	switch (centenas)
 	{
 		case 1: cout<<"C"; break;
 	 	case 2: cout<<"CC"; break;
  		case 3: cout<<"CCC"; break;
 	 	case 4: cout<<"CD"; break;
 	 	case 5: cout<<"D"; break;
 	 	case 6: cout<<"DC"; break;
  		case 7: cout<<"DCC"; break;
  		case 8: cout<<"DCCC"; break;
  		case 9: cout<<"CM"; break; 
 	}
 
	switch (decenas)
 	{
  		case 1: cout<<"X"; break;
  		case 2: cout<<"XX"; break;
  		case 3: cout<<"XXX"; break;
  		case 4: cout<<"XL"; break;
  		case 5: cout<<"L"; break;
  		case 6: cout<<"LX"; break;
  		case 7: cout<<"LXX"; break;
  		case 8: cout<<"LXXX"; break;
  		case 9: cout<<"XC"; break; 
 	}
 
 	switch (unidades)
 	{
  		case 1: cout<<"I"; break;
  		case 2: cout<<"II"; break;
  		case 3: cout<<"III"; break;
  		case 4: cout<<"IV"; break;
  		case 5: cout<<"V"; break;
  		case 6: cout<<"VI"; break;
  		case 7: cout<<"VII"; break;
  		case 8: cout<<"VIII"; break;
  		case 9: cout<<"IX"; break;
 	}
}
