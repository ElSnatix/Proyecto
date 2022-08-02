/*
PROYECTO FINAL
Programa: Calculadora Romana
Autores: Santiago Guarguati y David Santiago lópez
*/
#include <iostream>
#include <locale.h>
#include <string.h>
#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000
//prototipos 
void saludo(void); //saludo
int rom1dec(char s[]); //romanos a enteros 1
int rom2dec(char s[]); //romanos a enteros 2
int menu(int num1, int num2);

using namespace std;


int main(){
	//declaración variables
	char cad[20];
	int num1,num2;
	int rom1dec(char s[]);
	setlocale(LC_ALL,""); //carácteres especiales
	saludo(); //llama la funcion saludo saludo
	
	//muestra la calculadora
	cout<<"\t\tEste programa es una calculadora romana que calcula en matrices \n";
	cout<<"\t\t\t\t [I]\t[V]\t[X]\n";
	cout<<"\t\t\t\t [L]\t[C]\t[D]\n";
	cout<<"\t\t\t\t [+]\t[M]\t[-]\n";
	cout<<"\t\t\t\t [x]\t[=]\t[/]\n\n";
	
	//pide el primer número
	cout<<"Digite el primer número (en letras mayúsculas): "; 
	cin>>cad; 
	num1=rom1dec(cad); //romano a decimal --numero 1
	cout<<"El valor en decimal del primer número es: "<<num1<<endl;
	
	cout<<"Digite el segundo número (en letras mayúsculas): "; 
	cin>>cad;
	num2=rom2dec(cad); //romano a decimal --numero 2
	cout<<"El número decimal del segundo número es: "<<num2<<endl;
	
	menu(num1,num2);
	system("PAUSE");
	return 0;
}

//Lo que pide el proyecto:

//matrices, suma, resta multiplicación y división de matrices, adicional a ello hallar la determinante de ambas matrices máximo 4x4.


//división por cero no es posible, de darse este caso se debe mostrar al usuario una advertencia y pedir que ingrese un nuevo número para reemplazar el cero.


//debe ser capaz de identificar que IIII no es número válido y en ese caso, advertirle al usuario y dar la opción de ingresar otro número.


//el resultado de operarlos, se deben mostrar tanto en romano como en decimales. Al final de cada operación se debe dar la opción al usuario de realizar otra.


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
//De romano a natural--número1
int rom1dec(char s[]){
	int i,valor;
	int r=0;
	for(i=0;i<strlen(s);i++){
		switch(s[i]){
			case 'IV': valor=4;
			break;
			case 'IX': valor=9;
			break;
			case 'I': valor=1;
			break;
			case 'V': valor=5;
			break;
			case 'X': valor=10;
			break;
			case 'L': valor=50;
			break;
			case 'C': valor=100;
			break;
			case 'D': valor=500;
			break;
			case 'M': valor=1000;
			break;
			default: break;
		}
		r+=valor;
	}
	
	
	return r;
}
//romano a natural-- número 2
int rom2dec(char s[]){
	int i,valor;
	int r=0;
	for(i=0;i<strlen(s);i++){
		switch(s[i]){
			case 'IV': valor=4;
			break;
			case 'IX': valor=9;
			break;
			case 'I': valor=1;
			break;
			case 'V': valor=5;
			break;
			case 'X': valor=10;
			break;
			case 'L': valor=50;
			break;
			case 'C': valor=100;
			break;
			case 'D': valor=500;
			break;
			case 'M': valor=1000;
			break;
			default: break;
		}
		r+=valor;
	}
	
	
	return r;
}
//Menú
int menu(int num1, int num2){
	int opcion;
	cout<<"MENÚ \n";
	cout<<"1.SUMA \n";
	cout<<"2.RESTA \n";
	cout<<"3.MULTIPLICACIÓN \n";
	cout<<"4.DIVISIÓN \n";
	cout<<"Digite el número de la opción: ";cin>>opcion;cout<<endl;
	
	switch(opcion){
		case 1: cout<<"La suma es: ";cout<<num1+num2;cout<<" ó: "<<endl;
		break;
		case 2: cout<<"La resta es: ";cout<<num1-num2<<endl;
		break;
		case 3: cout<<"La multiplicación es: ";cout<<num1*num2<<endl;
		break;
		case 4: cout<<"La división es: ";cout<<num1/num2<<endl;
		break;
		default: cout<<"Digite una opción válida \n";
	}
}
