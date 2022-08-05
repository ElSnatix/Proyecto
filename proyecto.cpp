/*
PROYECTO FINAL
Programa: Calculadora Romana
Autores: Santiago Guarguati y David Santiago l�pez
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
int matriz(int x, int y);
void suma(void);
/*
int matriz1(int x, int y);
int matriz2(int x, int y);
void matriz3(void);
*/
using namespace std;


int main(){
	//declaraci�n variables
	char cad[20];
	int num1,num2,filas,columnas;
	int rom1dec(char s[]);
	setlocale(LC_ALL,""); //car�cteres especiales
	saludo(); //llama la funcion saludo saludo
	
	//muestra la calculadora
	cout<<"\t\tEste programa es una calculadora romana que calcula en matrices \n";
	cout<<"\t\t\t\t [I]\t[V]\t[X]\n";
	cout<<"\t\t\t\t [L]\t[C]\t[D]\n";
	cout<<"\t\t\t\t [+]\t[M]\t[-]\n";
	cout<<"\t\t\t\t [x]\t[=]\t[/]\n\n";
	
	//pide el primer n�mero
	cout<<"Digite el primer n�mero (en letras may�sculas): "; 
	cin>>cad; 
	num1=rom1dec(cad); //romano a decimal --numero 1
	cout<<"El valor en decimal del primer n�mero es: "<<num1<<endl;
	
	cout<<"Digite el segundo n�mero (en letras may�sculas): "; 
	cin>>cad;
	num2=rom2dec(cad); //romano a decimal --numero 2
	cout<<"El n�mero decimal del segundo n�mero es: "<<num2<<endl;
	
	menu(num1,num2);
	cout<<"\n";
	cout<<"OPERACIONES CON MATRICES \n";
	matriz(filas,columnas);
	/*
	matriz1(filas,columnas);
	matriz2(filas,columnas);
	matriz3();
	*/
	system("PAUSE");
	return 0;
}

//Lo que pide el proyecto:

//matrices, suma, resta multiplicaci�n y divisi�n de matrices, adicional a ello hallar la determinante de ambas matrices m�ximo 4x4.


//divisi�n por cero no es posible, de darse este caso se debe mostrar al usuario una advertencia y pedir que ingrese un nuevo n�mero para reemplazar el cero.


//debe ser capaz de identificar que IIII no es n�mero v�lido y en ese caso, advertirle al usuario y dar la opci�n de ingresar otro n�mero.


//el resultado de operarlos, se deben mostrar tanto en romano como en decimales. Al final de cada operaci�n se debe dar la opci�n al usuario de realizar otra.


//Saludo
void saludo(void){
	system("color f0");
	printf("\t\t UNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS \n\n");
    cout<<"PROYECTO CALCULADORA ROMANA \n";
    cout<<"Santiago Guarguati y David santiago l�pez \n\n";
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
//De romano a natural--n�mero1
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
//romano a natural-- n�mero 2
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
//Men�
int menu(int num1, int num2){
	int opcion;
	cout<<"OPERACIONES CON 2 N�MEROS \n";
	cout<<"MEN� \n";
	cout<<"1.SUMA \n";
	cout<<"2.RESTA \n";
	cout<<"3.MULTIPLICACI�N \n";
	cout<<"4.DIVISI�N \n";
	cout<<"Digite el n�mero de la opci�n: ";cin>>opcion;cout<<endl;
	
	switch(opcion){
		case 1: cout<<"La suma es: ";cout<<num1+num2;cout<<" �: "<<endl;
		break;
		case 2: cout<<"La resta es: ";cout<<num1-num2<<endl;
		break;
		case 3: cout<<"La multiplicaci�n es: ";cout<<num1*num2<<endl;
		break;
		case 4: cout<<"La divisi�n es: ";cout<<num1/num2<<endl;
		break;
		default: cout<<"Digite una opci�n v�lida \n";
	}
}

int matriz(int x, int y)
{
	int row,fil,i,j,opcion;
    cout <<"Ingrese el numero de filas "<<endl;
    cin >>fil;
    cout <<"Ingrese el numero de columnas "<<endl;
    cin >>row;
    int matriz1[fil][row];
    for  (i=0;i<=fil-1;i++)
    {
        for  (j=0;j<=row-1;j++)
        {
            cout <<"Ingrese la posicion "<<"("<<i<<")"<<"("<<j<<")"<<" de la matriz 1"<<endl;
            cin >>matriz1[i][j];
        }
    }
    cout<<"\n";
    int matriz2[fil][row];
    for  (i=0;i<=fil-1;i++)
    {
        for  (j=0;j<=row-1;j++)
        {
            cout <<"Ingrese la posicion "<<"("<<i<<")"<<"("<<j<<")"<<" de la matriz 2"<<endl;
            cin >>matriz2[i][j];
        }
    }
   	cout<<"Men� \n";
   	cout<<"1.SUMA \n";
   	cout<<"2.RESTA \n";
   	cout<<"3.MULTIPLICACI�N \n";
   	cout<<"4.DIVISI�N \n";
   	cout<<"Digite la opci�n que quiere operar: ";cin>>opcion;
   	
   	switch(opcion){
   		case 1: cout << "\nLA SUMA DE LA MATRIZ ES\n "<<endl;
    			int matriz3[fil][row];
    			for  (i=0;i<=fil-1;i++){
       				for  (j=0;j<=row-1;j++){
            			matriz3[i][j]= matriz1[i][j]+matriz2[i][j];
            			cout << matriz3[i][j];
            			cout<<"\t";
        			}
        			cout<<"\n\n";
    			}
   		break;   
		   	
	}


}

