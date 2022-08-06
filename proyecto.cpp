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

using std::cout; using std::endl;
using std::cin;
using std::string; using std::reverse;

//prototipos 
void saludo(void); //saludo
void menu();
void menuMatrices();
void menuNumeros(int Num1, int Num2);
int deRomanoAEntero(string rstr);
void deEnteroARomano(int Numero);
int sumaEnteros(int Num1, int Num2);
int restaEnteros(int Num1, int Num2);
int multiplicacionEnteros(int Num1, int Num2);
int divisionEnteros(int Num1, int Num2);

using namespace std;

int main(){
	//declaración variables
	setlocale(LC_ALL,""); //carácteres especiales
	saludo(); //llama la funcion saludo saludo
	menu();
	
	
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
	cout<<"Digite el número de la opción: ";cin>>opcion;cout<<endl;
	
	if(opcion == 1){
		cout<<"Ha seleccionado Matrices \n";
		menuMatrices();
	}
	
	if(opcion == 2){			
		cout<<"Ha seleccionado Numeros naturales \n";
		string NumeroRomano1;
		string NumeroRomano2;
		cout<<"Ingrese el primer numero \n";
		cin >> NumeroRomano1;  
		cout<<"Ingrese el segundo numero \n";
		cin >> NumeroRomano2;  		
  		int NumeroEntero1 = deRomanoAEntero(NumeroRomano1);
  		int NumeroEntero2 = deRomanoAEntero(NumeroRomano2);
		cout << "El primer numero ingresado fue: " << NumeroEntero1 << " o " << NumeroRomano1 << "\n";
		cout << "El segundo numero ingresado fue: " << NumeroEntero2 << " o " << NumeroRomano2 << "\n";	
		menuNumeros(NumeroEntero1, NumeroEntero2);
	}else{	 
		cout<<"Digite una opción válida \n";
	}
}

//menu matrices
void menuMatrices(){
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
		break;
		case 2:
		cout<<"Ha seleccionado Resta \n";
		break;
		case 3:
		cout<<"Ha seleccionado Multiplicacion \n";
		break;
		case 4:
		cout<<"Ha seleccionado division \n";
		break;
		case 5:
		cout<<"Ha seleccionado determinante \n";
		break;
		default: cout<<"Digite una opción válida \n";
		menuMatrices();
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
		deEnteroARomano(Num1);
		cout << " + ";
		deEnteroARomano(Num2);
		cout << " = ";
		deEnteroARomano(sumaEnteros(Num1, Num2));
		cout << "\n";
		break;
		case 2:
		cout<<"Ha seleccionado Resta \n";
		if(restaEnteros >= 0){
			cout<<"puta";
		}else{
			cout<<"la resta da ";
		}
		break;
		case 3:
		cout<<"Ha seleccionado Multiplicacion \n";
		break;
		case 4:
		cout<<"Ha seleccionado division \n";
		break;
		default: cout<<"Digite una opción válida \n";
		menuNumeros(Num1, Num2);
	}
}

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



