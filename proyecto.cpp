/*
PROYECTO FINAL
Programa: Calculadora Romana
Autores: Santiago Guarguati y David Santiago lópez
*/
#include <iostream>
#include <locale.h>
#include <string.h>
#include <string>

//prototipos 
void saludo(void); //saludo
void menu();
void menuMatrices();
void menuNumeros();

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
		string numeroRomano;
  		cout << "Escribe elnumero romano: \n";
  		getline(cin, numeroRomano);
  		//int numeroEntero = deRomanoAEntero(numeroRomano);
		cout << "El numero ingresado fue: " /*<< numeroEntero*/ << " o " << numeroRomano;	
		//menuNumeros();
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
void menuNumeros(){
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
		default: cout<<"Digite una opción válida \n";
		menuNumeros();
	}
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



