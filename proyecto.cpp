/*
PROYECTO FINAL
Programa: Calculadora Romana
Autores: Santiago Guarguati y David Santiago lópez
*/
#include <iostream>
#include <locale.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <iterator>
#include <cmath>
#define MAX 10

using std::cout; using std::endl;
using std::cin;
using std::string; using std::reverse;

		

//prototipos 
void saludo(void); 
void menu();

void menuMatrices(int Matriz1[100][100], int Matriz2[100][100], int Tamano);

void menuNumeros(int Num1, int Num2);
int deRomanoAEntero(string rstr);
void deEnteroARomano(int Numero);
int sumaEnteros(int Num1, int Num2);
int restaEnteros(int Num1, int Num2);
int multiplicacionEnteros(int Num1, int Num2);
int divisionEnteros(int Num1, int Num2);

void sumaMatrices(int Matriz1[100][100], int Matriz2[100][100], int Tamano); //cree una void donde le entran dos matrices y un tamaño lo importante es no declarar el primer tamaño de las matrices 
void restaMatrices(int Matriz1[100][100], int Matriz2[100][100], int Tamano);
void multiplicacionMatrices(int Matriz1[100][100], int Matriz2[100][100], int Tamano);
int determinante(int matriz[][MAX], int orden);	

int cofactor(int matriz[][MAX], int orden, int fila, int columna);																	


using namespace std;

//main
int main(){
	//declaración variables
	setlocale(LC_ALL,""); //carácteres especiales
	saludo(); //llama la funcion saludo saludo
	menu(); //llama a la funcion menu
	
	
	return 0;
}

//Saludo
void saludo(void){
	system("color f0");
	printf("\t\t UNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS \n\n");
    cout<<"PROYECTO CALCULADORA ROMANA \n";
    cout<<"Santiago Guarguati y David santiago lópez \n\n";
    printf("\t\t     ******      ******    *************    \n");
    printf("\t\t     ******      ******    **************    \n");
    printf("\t\t     ******      ******    ***************     \n");
    printf("\t\t     ******      ******    ***       ******   \n");
	printf("\t\t     ******      ******    ***        ******  \n");
    printf("\t\t     ******      ******    ***         ******  \n");
    printf("\t\t     ******      ******    ***         ******  \n");
	printf("\t\t     ******      ******    ***         *****  \n");
    printf("\t\t     ******      ******    ***        *****   \n");
    printf("\t\t     ******************    ***       ******    \n");
    printf("\t\t     ******************    ***************    \n");
    printf("\t\t     ******************    **************    \n");
    printf("\t\t     ******************    *************    \n\n");    
}


//Menú
void menu(){
	int opcion;
	cout<<"¿Que desea operar? \n";
	cout<<"1.Matrices \n";
	cout<<"2.Numeros naturales \n";
	cout<<"3.Salir \n";
	cout<<"Digite el número de la opción: ";cin>>opcion;cout<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- \n";
	
	while(opcion != 3){
		if(opcion == 1){
			
			int Tam;
			cout<<"Ha seleccionado Matrices \n";
			cout<<"Digite el tamaño del matriz: ";cin>>Tam;
			int Matriz1[100][100];
			string MatrizRomano1[100][100];
			int Matriz2[100][100];
			string MatrizRomano2[100][100];
			
			//rellenar la matriz 1
			for(int i=0;i<Tam;i++){
				for(int j=0;j<Tam;j++){
					cout<<"Digite el número romano de la posición "<< i << ", "<< j<<" para la primera matriz: " ;
					cin>>MatrizRomano1[i][j];
					//Hace las excepciones de los números romanos
					if(MatrizRomano1[i][j].find("IIII")<100||MatrizRomano1[i][j].find("VV")<100||MatrizRomano1[i][j].find("XXXXX")<100||MatrizRomano1[i][j].find("LL")<100||MatrizRomano1[i][j].find("CCCCC")<100||MatrizRomano1[i][j].find("DD")<100){
						cout<< "Este número no es correcto, ";
						cout<< "el número contiene IIII o VV o XXXXX o LL o CCCCC o DD por lo tanto debe escribirlo bien";
						exit(0); //termina el programa
					}
					Matriz1[i][j]=deRomanoAEntero(MatrizRomano1[i][j]);
				}
			}
			//mostrar la matriz 1 de enteros
			cout << "Matriz 1 de enteros \n";
			for(int i=0;i<Tam;i++){
				for(int j=0;j<Tam;j++)
					cout<<Matriz1[i][j]<<"  ";
					cout<<endl;
			}
			//mostrar la matriz 1 de romanos
			cout << "Matriz 1 de romanos \n";
			for(int i=0;i<Tam;i++){
				for(int j=0;j<Tam;j++)
					cout<<MatrizRomano1[i][j]<<"  ";
					cout<<endl;
			}
			//rellenar la matriz 2 
			for(int i=0;i<Tam;i++){
				for(int j=0;j<Tam;j++){
					cout<<"Digite el número romano de la posición "<< i << ", "<< j<<"para la segunda matriz: " ;
					cin>>MatrizRomano2[i][j];
					//Hace las excepciones de los números romanos
					if(MatrizRomano2[i][j].find("IIII")<100||MatrizRomano2[i][j].find("VV")<100||MatrizRomano2[i][j].find("XXXXX")<100||MatrizRomano2[i][j].find("LL")<100||MatrizRomano2[i][j].find("CCCCC")<100||MatrizRomano2[i][j].find("DD")<100){
						cout<< "Ese numero no es correcto, ";
						cout<< "el número contiene IIII o VV o XXXXX o LL o CCCCC o DD por lo tanto debe escribirlo bien";
						exit(0);  //termina el programa
					}
					Matriz2[i][j]=deRomanoAEntero(MatrizRomano2[i][j]);
				}
			}
			//mostrar la matriz 2
			cout << "Matriz 2 de enteros \n";
			for(int i=0;i<Tam;i++){
				for(int j=0;j<Tam;j++)
					cout<<Matriz2[i][j]<<"  ";
					cout<<endl;
			}
			//mostrar la matriz 1 de romanos
			cout << "Matriz 1 de romanos \n";
			for(int i=0;i<Tam;i++){
				for(int j=0;j<Tam;j++)
					cout<<MatrizRomano2[i][j]<<"  ";
					cout<<endl;
			}
			menuMatrices(Matriz1 ,Matriz2 ,Tam); //llama a la funcion menuMatrices
		}
		
		if(opcion == 2){			
			cout<<"Ha seleccionado Numeros naturales \n";
			string NumeroRomano1; //declaracion de strings
			string NumeroRomano2; //declaracion de strings
			cout<<"Ingrese el primer numero \n";
			cin >> NumeroRomano1;
			//Hace las excepciones de los números romanos
			if(NumeroRomano1.find("IIII")<100||NumeroRomano1.find("VV")<100||NumeroRomano1.find("XXXXX")<100||NumeroRomano1.find("LL")<100||NumeroRomano1.find("CCCCC")<100||NumeroRomano1.find("DD")<100){
				cout<< "Este numero no es correcto, ";
				cout<< "el número contiene IIII o VV o XXXXX o LL o CCCCC o DD por lo tanto debe escribirlo bien";
				exit(0);  //termina el programa
			}  
			cout<<"Ingrese el segundo numero \n";
			cin >> NumeroRomano2;
			//Hace las excepciones de los números romanos
			if(NumeroRomano2.find("IIII")<100||NumeroRomano2.find("VV")<100||NumeroRomano2.find("XXXXX")<100||NumeroRomano2.find("LL")<100||NumeroRomano2.find("CCCCC")<100||NumeroRomano2.find("DD")<100){
				cout<< "Este número no es correcto, ";
				cout<< "el número contiene IIII o VV o XXXXX o LL o CCCCC o DD por lo tanto debe escribirlo bien";
				exit(0);  //termina el programa
			}  
			
			//Numero entero igual a la funcion deRomanoAEntero		
	  		int NumeroEntero1 = deRomanoAEntero(NumeroRomano1);
	  		int NumeroEntero2 = deRomanoAEntero(NumeroRomano2);
	  		
			cout << "El primer numero ingresado fue: " << NumeroEntero1 << " o " << NumeroRomano1 << "\n";
			cout << "El segundo numero ingresado fue: " << NumeroEntero2 << " o " << NumeroRomano2 << "\n";	
			menuNumeros(NumeroEntero1, NumeroEntero2); //llama a la función menú números
		}
		if(opcion>3 || opcion<1){	 
			cout<<"Digite una opción válida \n";
		}
		cout << "Desea Continuar haciendo operaciones?\n";
		cout << "1.si\n";
		cout << "2.no\n";
		int continuar;
		cin >> continuar;
		if(continuar == 1){
			system("cls");
			saludo();
			menu();
		}
		if(continuar == 2){
			exit(0);
		}
	}	
}

//menu matrices
void menuMatrices(int Matriz1[100][100] , int Matriz2[100][100] , int Tamano){
	int opcion;
	cout<<"¿Que operacion desea realizar? \n";
	cout<<"1.Suma \n";
	cout<<"2.Resta \n";
	cout<<"3.Multiplicación \n";
	cout<<"4.División \n";
	cout<<"5.Determinante \n";
	cout<<"Digite el número de la opción: ";cin>>opcion;cout<<endl;
	
	switch(opcion){
		case 1:
		cout<<"Ha seleccionado Suma \n";
		sumaMatrices(Matriz1 ,Matriz2 ,Tamano);
		break;
		case 2:
		cout<<"Ha seleccionado Resta \n";
		restaMatrices(Matriz1 ,Matriz2 ,Tamano);
		break;
		case 3:
		cout<<"Ha seleccionado Multiplicacion \n";
		multiplicacionMatrices(Matriz1 ,Matriz2 ,Tamano);
		break;
		case 4:
		cout<<"Ha seleccionado division \n";
		cout << "No se puede realizar la división ya que se debe hallar la inversa de la segunda matriz, lo que da 0 \n";
		break;
		case 5:
		cout<<"Ha seleccionado determinante \n";
		int Matriz1d[MAX][MAX];
		int Matriz2d[MAX][MAX];
		
		for(int i=0;i<Tamano;i++){
			for(int j=0;j<Tamano;j++){
				Matriz1d[i][j] = Matriz1[i][j];
			}				
		}	
		
		for(int i=0;i<Tamano;i++){
			for(int j=0;j<Tamano;j++){
				Matriz2d[i][j] = Matriz2[i][j];
			}				
		}	
		cout << "El determinante de la primera matriz es (Enteros): ";
		cout << determinante(Matriz1d, Tamano) ;
		cout << "\n";
		
		cout << "El determinante de la primera matriz es (Romanos): ";
		deEnteroARomano(determinante(Matriz1d, Tamano));
		cout << "\n";		
		
		cout << "El determinante de la segunda matriz es (Enteros): ";
		cout << determinante(Matriz2d, Tamano) ;
		cout << "\n";
		
		cout << "El determinante de la primera matriz es (Romanos): ";
		deEnteroARomano(determinante(Matriz2d, Tamano));
		cout << "\n";
		break;
		default: cout<<"Digite una opción válida \n";
	}
}

//menu numeros
void menuNumeros(int Num1, int Num2){
	int opcion;
	cout<<"¿Que operacion desea realizar? \n";
	cout<<"1.Suma \n";
	cout<<"2.Resta \n";
	cout<<"3.Multiplicación \n";
	cout<<"4.División \n";
	cout<<"Digite el número de la opción: ";cin>>opcion;cout<<endl;
	
	switch(opcion){
		case 1:
		cout<<"Ha seleccionado Suma \n";
		cout<< Num1 << " + " << Num2 << " = " << sumaEnteros(Num1, Num2) << "\n";
		deEnteroARomano(Num1); //muestra el número 1 en romano
		cout << " + ";
		deEnteroARomano(Num2); //muestra el número 2 en romano
		cout << " = ";
		deEnteroARomano(sumaEnteros(Num1, Num2)); //muestra la suma en números romanos
		cout << "\n";
		break;
		
		case 2:
		cout<<"Ha seleccionado Resta \n";
		if(restaEnteros(Num1,Num2) >= 0){
			cout<< Num1 << " - "<< Num2 << " = " << restaEnteros(Num1, Num2) << "\n";
			deEnteroARomano(Num1); //muestra el número 1 en romano
			cout<< " - ";
			deEnteroARomano(Num2); //muestra el número 2 en romano
			cout<< " = ";
			deEnteroARomano(restaEnteros(Num1, Num2)); //muestra la resta en numeros romanos
			cout<<"\n";
			
		}else{
			cout<<"la resta da negativa y no puede ser expresada en números romanos \n";
			cout<<"La resta en enteros es: " << Num1 << " - " << Num2 << " = " << restaEnteros(Num1, Num2) << "\n";			
		}
		break;
		
		case 3:
		cout<<"Ha seleccionado Multiplicacion \n";
		cout<< Num1 << " * " << Num2 << " = " << multiplicacionEnteros(Num1, Num2) << "\n";
		deEnteroARomano(Num1); //muestra el número 1 en romano
		cout << " * ";
		deEnteroARomano(Num2); //muestra el número 2 en romano
		cout << " = ";
		deEnteroARomano(multiplicacionEnteros(Num1, Num2)); //muestra la multiplicacion en números romanos
		cout << "\n";
		break;
		
		case 4:
		cout<<"Ha seleccionado division \n";
		if(Num2 != 0){
			cout<< Num1 << " / "<< Num2 << " = " << divisionEnteros(Num1, Num2) << "\n";
			deEnteroARomano(Num1); //muestra el número 1 en romano
			cout<< " / ";
			deEnteroARomano(Num2); //muestra el número 2 en romano
			cout<< " = ";
			deEnteroARomano(divisionEnteros(Num1, Num2)); //muestra la division en numeros romanos
			cout<<"\n";
			
		}else{
			cout<<"La división no se puede hacer ya que no existe división por 0 \n";		
		}
		break;
		
		default: cout<<"Digite una opción válida \n";
		menuNumeros(Num1, Num2); //lo lleva al menu de numeros enteros otra vez
	}
}

// Operaciones de enteros
int sumaEnteros(int Num1, int Num2){
	return Num1 + Num2;
}
int restaEnteros(int Num1, int Num2){
	return Num1 - Num2;
}
int multiplicacionEnteros(int Num1, int Num2){
	return Num1 * Num2;
}
int divisionEnteros(int Num1, int Num2){
	return Num1 / Num2;
}
//Suma de matrices
void sumaMatrices(int Matriz1[100][100], int Matriz2[100][100], int Tamano){
	
	int MatrizSumada[Tamano][Tamano];
	
	//sumar las matrices
	for(int i=0;i<Tamano;i++){
		for(int j=0;j<Tamano;j++)
			MatrizSumada[i][j] = Matriz1[i][j] + Matriz2[i][j];
	}
	//mostrar la matriz sumada en enteros
	cout << "La suma de matrices da (enteros): \n";
	for(int i=0;i<Tamano;i++){
		for(int j=0;j<Tamano;j++)
			cout<<MatrizSumada[i][j]<<"  ";
			cout<<endl;
	}
	//mostrar la matriz sumada en romanos
	cout << "La suma de matrices da (romanos): \n";
	for(int i=0;i<Tamano;i++){
		for(int j=0;j<Tamano;j++){
			deEnteroARomano(MatrizSumada[i][j]);
			cout<<"  ";
		}
			cout<<endl;
	}
}

//Resta de matrices
void restaMatrices(int Matriz1[100][100], int Matriz2[100][100], int Tamano){
	
	int MatrizRestada[Tamano][Tamano];
	
	//Resta las matrices
	for(int i=0;i<Tamano;i++){
		for(int j=0;j<Tamano;j++)
			MatrizRestada[i][j] = Matriz1[i][j] - Matriz2[i][j];
	}
	//mostrar la matriz restada en enteros
	cout << "La resta de matrices da (enteros): \n";
	for(int i=0;i<Tamano;i++){
		for(int j=0;j<Tamano;j++)
			cout<<MatrizRestada[i][j]<<"  ";
			cout<<endl;
	}
	//mostrar la matriz restada en romanos
	cout << "La resta de matrices da (romanos): \n";
	for(int i=0;i<Tamano;i++){
		for(int j=0;j<Tamano;j++){
			deEnteroARomano(MatrizRestada[i][j]);
			cout<<"  ";
		}
			cout<<endl;
	}
}

//Multiplicación de matrices
void multiplicacionMatrices(int Matriz1[100][100], int Matriz2[100][100], int Tamano) {

    int MatrizMultiplicada[100][100];

    for (int row = 0; row < Tamano; row++) {
        for (int col = 0; col < Tamano; col++) {
            // Multiplica la fila A por la columna B para tener la fila y columna del producto
            for (int inner = 0; inner < Tamano; inner++) {
                MatrizMultiplicada[row][col] += Matriz1[row][inner] * Matriz2[inner][col]; //multiplicación de las 2 matrices
            }
        }
    }
    
    //mostrar la matriz multiplicada 
	cout << "La multiplicación de matrices da (enteros): \n";
	for(int i=0;i<Tamano;i++){
		for(int j=0;j<Tamano;j++)
			cout<<MatrizMultiplicada[i][j]<<"  ";
			cout<<endl;
	}
	//mostrar la matriz multiplicada en romanos
	cout << "La multiplicación de matrices da (romanos): \n";
	for(int i=0;i<Tamano;i++){
		for(int j=0;j<Tamano;j++){
			deEnteroARomano(MatrizMultiplicada[i][j]);
			cout<<"  ";
		}
			cout<<endl;
	}
}

//Determinante de las matrices
int determinante(int matriz[][MAX], int orden)
{
   int det = 0.0;
   
   if (orden == 1) {
      det = matriz[0][0];
   } else {
      for (int j = 0; j < orden; j++) {
         det = det + matriz[0][j] * cofactor(matriz, orden, 0, j); //uso del cofactor
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
int deRomanoAEntero(string rstr) {
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
void deEnteroARomano(int Numero){
	int numero, unidades, decenas, centenas, millares;
	
	unidades = Numero % 10; Numero /= 10;
 	decenas = Numero % 10; Numero /= 10;
 	centenas = Numero % 10; Numero /= 10;
 	millares = Numero % 10; Numero /= 10;

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
