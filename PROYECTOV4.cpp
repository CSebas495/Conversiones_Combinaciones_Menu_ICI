#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cmath>
#include <ctype.h>
#include <iomanip> // Para std::hex
/* #include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;    Usar para que el factorial pueda llegar a 13 o m�sx	 */ 
using namespace std;


string intToString(int numero) {
    stringstream ss;
    ss << numero;
    return ss.str();
}

int binarioADecimal(const string& binario) {
    int decimal = 0;
    int tamano = binario.length();

    for (int i = 0; i < tamano; ++i) {
        if (binario[i] == '1') {
            decimal += static_cast<int>(pow(2, tamano - i - 1));
        }
    }

    return decimal;
}

string binarioAOctal(const string& binario) {
    string octal = "";
    int tamano = binario.length();
    
    string binarioConCeros = binario; // Copia la cadena binaria

    // A�adir ceros a la izquierda para que el n�mero de d�gitos sea m�ltiplo de 3
    while (tamano % 3 != 0) {
        binarioConCeros.insert(0, "0");
        ++tamano;
    }

    for (int i = 0; i < tamano; i += 3) {
        string subcadena = binarioConCeros.substr(i, 3); // Tomar grupos de 3 d�gitos binarios
        int decimal = binarioADecimal(subcadena); // Convertir el grupo a decimal
        octal += intToString(decimal); // Agregar el valor decimal a la representaci�n octal
    }

    return octal;
}

string binarioAHexadecimal(const string& binario) {
    int decimal = binarioADecimal(binario); // Convertir binario a decimal
    string hexadecimal = "";

    while (decimal > 0) {
        int residuo = decimal % 16;
        char digitoHexadecimal;

        if (residuo < 10) {
            digitoHexadecimal = '0' + residuo;
        } else {
            digitoHexadecimal = 'A' + residuo - 10;
        }

        hexadecimal = digitoHexadecimal + hexadecimal;
        decimal /= 16;
    }

    return hexadecimal; // Agregar el prefijo "0x" para representaci�n hexadecimal
}

int main() {
    setlocale(LC_ALL,"");
    int opcion;

    do {
    	system("cls");
        cout << "MENU" << endl;
        cout << "1. CONVERSIONES" << endl;
        cout << "2. COMBINATORIAS" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int opcion2;
                do {
                    system("cls");
                    cout << "MENU CONVERSIONES" << endl;
                    cout << "1. CONVERSI�N DE DECIMAL A MAYA" << endl;
                    cout << "2. CONVERSI�N DE DECIMAL A BINARIO" << endl;
                    cout << "3. CONVERSI�N DE DECIMAL A OCTAL" << endl;
                    cout << "4. CONVERSI�N DE DECIMAL A HEXADECIMAL" << endl;
                    cout << "5. CONVERSI�N DE BINARIO A DECIMAL" << endl;
                    cout << "6. CONVERSI�N DE BINARIO A OCTAL" << endl;
                    cout << "7. CONVERSI�N DE BINARIO A HEXADECIMAL" << endl;
                    cout << "8. REGRESAR AL MENU ANTERIOR" << endl;
                    cout << "9. SALIR DEL PROGRAMA" << endl;
                    cout << "Seleccione una opci�n: ";
                    cin >> opcion2;

                    switch (opcion2) {
                        case 1:{
                        		system("cls");
                        	    int num, i;
                        	    bool regresarAlMenu = false; // Variable para controlar el regreso al men�
                        	    char opcion;
                        	    do {
							    cout << "Dame un n�mero entero: " << endl;
							    cin >> num;
							    cout << "El n�mero en maya es:\n";
							
							    if (num == 0) {
							        cout << "Maya: @ \n";
							    }
							
							    char maya[4] = {'.', '@', '-'};
							    int base = 1;
							
							    string mayaR = ""; // Almacena la representaci�n maya en una cadena
							
							    while (num > 0) {
							        int dig = num % 20;
							        int uni = dig % 5;
							        int lineas = dig / 5;
							
							        for (i = 0; i < lineas; i++) {
							            mayaR += maya[2];
							            mayaR += '\n';
							        }
							
							        for (i = 0; i < uni; i++) {
							            mayaR += maya[0];
							        }
							
							        if (dig == 0) {
							            mayaR += maya[1];
							        }
							
							        mayaR += "\n";
							        num /= 20;
							    }
							
							    // Imprime la representaci�n maya en orden inverso
							    for (int i = mayaR.length() - 1; i >= 0; i--) {
							    	cout << mayaR[i];
							    }
							    cout << "\n�Desea convertir otro n�mero? s/n" << endl;
								cin >> opcion;
								opcion = tolower(opcion);
								if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al men� principal
						        }
						        system("cls");
								}while (!regresarAlMenu);
							break;
						}
                        case 2: {
                        	system("cls");
                        	double numero, fraccion, BINFAC;
							int residuoE,residuo_fraccion, entero;
							char opcion;
							bool regresarAlMenu = false;
							do {
								string binario_entero = "";
								string binario_fraccion = "";
								cout << "Ingresa el n�mero que quieras convertir a binario: " << endl;
								cin >> numero;
								if (numero == 0){
									binario_entero = "0"; 
								}
								while (numero < 0){
									cout << "Ingrese un n�mero valido positivo" << endl;
									cin >> numero;
								}
								entero =static_cast<int>(numero);
								fraccion = numero - entero;
								while (entero > 0){
									residuoE = entero % 2;
									stringstream ss;
									ss << residuoE;
									binario_entero = ss.str() + binario_entero;
									entero /= 2;
								}
								while (fraccion > 0){
									BINFAC= fraccion * 2;
									residuo_fraccion = static_cast<int>(BINFAC);
									fraccion = BINFAC - residuo_fraccion;
									stringstream ss;
									ss << residuo_fraccion;
									binario_fraccion = ss.str() + binario_fraccion;
								}
								if (binario_fraccion == "")
								binario_entero = binario_entero;
								else {
								binario_entero += "." + binario_fraccion;
								}
								cout << "El n�mero en binario es: "<< binario_entero << endl;
								cout << "�Desea convertir otro n�mero? s/n" << endl;
								cin >> opcion;
								opcion = tolower(opcion);
								if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al men� principal
						        }
						        system("cls");
							}while (!regresarAlMenu);
							
                            break;}
                        case 3: {
                        	system("cls");
						    double numero, fraccion, OCTFAC;
						    int residuoE, residuo_fraccion, entero;
						    char opcion;
						    bool regresarAlMenu = false; // Variable para controlar el regreso al men�
						
						    do {
						        string octal_entero = "";
						        string octal_fraccion = "";
						        cout << "Ingresa el n�mero que quieras convertir a octal: " << endl;
						        cin >> numero;
						        if (numero == 0) {
						            octal_entero = "0";
						        }
						        while (numero < 0) {
						            cout << "Ingrese un n�mero v�lido y positivo" << endl;
						            cin >> numero;
						        }
						        entero = static_cast<int>(numero);
						        fraccion = numero - entero;
						        while (entero > 0) {
						            residuoE = entero % 8;
						            stringstream ss;
						            ss << residuoE;
						            octal_entero = ss.str() + octal_entero;
						            entero /= 8;
						        }
						        while (fraccion > 0) {
						            OCTFAC = fraccion * 8;
						            residuo_fraccion = static_cast<int>(OCTFAC);
						            fraccion = OCTFAC - residuo_fraccion;
						            stringstream ss;
						            ss << residuo_fraccion;
						            octal_fraccion = ss.str() + octal_fraccion;
						        }
						        if (octal_fraccion == "")
						            octal_entero = octal_entero;
						        else {
						            octal_entero += "." + octal_fraccion;
						        }
						        cout << "El n�mero en octal es: " << octal_entero << endl;
						        cout << "�Desea convertir otro n�mero? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al men� principal
						        }
						        system("cls");
						    } while (!regresarAlMenu); // Volver al men� principal si la variable es verdadera
						    break;
						}
                        	
                        case 4:{
                        	system("cls");    
							bool regresarAlMenu = false;
						    int numeroDecimal;
						    char opcion;

							do{
							    cout << "Ingrese un n�mero decimal: ";
							    cin >> numeroDecimal;
							    while( numeroDecimal<0){
									cout << "Ingrese un n�mero v�lido y positivo" << endl;
						            cin >> numeroDecimal;
								}
							    
							    cout << "El n�mero en hexadecimal es: " << hex << numeroDecimal << endl;
							    cout << "�Desea convertir otro n�mero? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al men� principal
						        }
						        system("cls");
							} while(!regresarAlMenu);
							                    	
							break;
						}
                        case 5:{
                        	system("cls");
                        	bool regresarAlMenu = false;
                        	char opcion;
                        	string numeroBinario;
                        	do{
							    cout << "Ingrese un n�mero binario: ";
							    cin >> numeroBinario;
							
							    int decimal = binarioADecimal(numeroBinario);
							
							    cout << "El n�mero en decimal es: " << decimal << endl;
							    cout << "�Desea convertir otro n�mero? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al men� principal
						        }
						        system("cls");
							} while(!regresarAlMenu);
                            break;}
                        case 6: {                        	
							system("cls");
                        	bool regresarAlMenu = false;
                        	char opcion;
                        	string numeroBinario;
                        	do{
								cout << "Ingrese un n�mero binario: ";
							    cin >> numeroBinario;
							
							    string octal = binarioAOctal(numeroBinario);
							
							    cout << "El n�mero en octal es: " << octal << endl;
							    cout << "�Desea convertir otro n�mero? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al men� principal
						        }
						        system("cls");
							} while(!regresarAlMenu);
                            break;}

                        case 7:{                        	
							system("cls");
                        	bool regresarAlMenu = false;
                        	char opcion;
                        	string numeroBinario;
                        	do{
								cout << "Ingrese un n�mero binario: ";
							    cin >> numeroBinario;
							
							    string hexadecimal = binarioAHexadecimal(numeroBinario);
							
							    cout << "El n�mero en hexadecimal es: " << hexadecimal << endl;
							    cout << "�Desea convertir otro n�mero? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al men� principal
						        }
						        system("cls");
							} while(!regresarAlMenu);
                            break;}
                        	
                        	
                        case 8:
                            // Regresar al men� anterior
                            break;
                        case 9:
                            cout << "Saliendo del programa..." << endl;
                            return 0;
                        default:
                            cout << "Opci�n no v�lida. Por favor, seleccione una opci�n v�lida." << endl;
                    }
                } while (opcion2 != 8); // Salir del bucle cuando se elija "REGRESAR AL MENU ANTERIOR"
                break;
            }
            case 2: {
                int opcion2;
                do {
                    system("cls");
                    cout << "MEN� COMBINATORIAS" << endl;
                    cout << "1. PERMUTACIONES ORDINARIAS" << endl;
                    cout << "2. PERMUTACIONES CON DOS ASPECTOS" << endl;
                    cout << "3. PRINCIPIO DEL PALOMAR" << endl;
                    cout << "4. COMBINACIONES" << endl;
                    cout << "5. PIRAMIDE DE PASCAL" << endl;
                    cout << "6. REGRESAR AL MEN� ANTERIOR" << endl;
                    cout << "7. SALIR DEL PROGRAMA" << endl;
                    cout << "Seleccione una opci�n: ";
                    cin >> opcion2;

                    switch (opcion2) {
                        case 1:{
                        	system("cls");
                        	bool regresarAlMenu = false;
                        	char opcion;
                        	int num, fact=1, i;
                        	do{
								cout << "Ingrese un n�mero entero para calcular sus permutaciones: ";
							    cin >> num;
							    while (num<0){
							    	cout << "Ingrese un n�mero igual o mayor a 0";
							    	cin >> num;
								}
								if(num>0){
								
								for (i=1;i<=num;i++){
									fact = fact * i;
								}
								}else{fact=0;
								}
								cout << "El n�mero de permutaciones ordinarias que existen es de: " << fact << endl;
								
							    cout << "�Desea calcular otro n�mero? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al men� principal
						        }
						        system("cls");
							} while(!regresarAlMenu);
                            break;}
							

                        case 2:{
                        	system("cls");
                        	bool regresarAlMenu = false;
                        	char opcion;
                        	int n,i,r,permut, fact1, fact2;
                        	/*mp::cpp_int fact1, fact2; usar cuando este instalado boost*/
                        	do{
								cout << "Ingrese el n�mero de elementos (n): ";
							    cin >> n;
							    cout << "Ingrese la longitud de la permutaci�n (r): ";
							    cin >> r;
								for (i=1;i<=n;i++){
									fact1 = fact1 * i;
								}
								int diff = n - r;
								for (i=1;i<=diff;i++){
									fact2 = fact2 * i;
								}								    
							
							
							
							    if (n >= r && n >= 0 && r >= 0) {
							    	/*cout << fact1 << endl;
							    	cout << fact2 << endl;
							    	mp::cpp_int permut = fact1 / fact2; Usar cuando se instale boost y checar los valores de los factoriales*/ 
							    	
							    	permut = fact1 / fact2;
							        cout << "El n�mero de permutaciones con 2 aspectos es: " << permut << endl;
							    } else {
							        cout << "Entrada no v�lida. Aseg�rese de que n >= r y ambos sean no negativos." << endl;
									cout << "Ingrese el n�mero de elementos (n): ";
								    cin >> n;
								    cout << "Ingrese la longitud de la permutaci�n (r): ";
								    cin >> r;
							    }
								
							    cout << "�Desea calcular otro n�mero? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al men� principal
						        }
						        system("cls");
							} while(!regresarAlMenu);
                            break;
							}
                        case 3:
                        	{
                        		system("cls");
                        		bool regresarAlMenu = false;
                        		int numPalomares, numPalomas;
                        		
                        		do{
                        			    

							    cout << "Ingrese el n�mero de palomares: ";
							    cin >> numPalomares;
							
							    cout << "Ingrese el n�mero de palomas: ";
							    cin >> numPalomas;
							
							    if (numPalomas > numPalomares) {
							        cout << "Principio del Palomar: Al menos un palomar debe tener m�s de una paloma." << endl;
							    } else {
							        cout << "Principio del Palomar: Todas las palomas pueden estar en palomares diferentes." << endl;
							    }
							    
							    cout << "�Desea comparar otros palomares y palomas? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al men� principal
						        }
						        system("cls");
                        			
								}while (!regresarAlMenu);
							
                            break;
							}
                        case 4:
                        	{
                        		system("cls");
                        		bool regresarAlMenu = false;
                        		int n,r2, r,i, fact1=1, fact2=1,fact3=1, combinaciones, abajo, arriba;
                        		do{
                        			cout << "Ingrese el n�mero total de elementos (n): ";
								    cin >> n;
								
								    cout << "Ingrese el n�mero de elementos en cada combinaci�n (r): ";
								    cin >> r;
								    
								    arriba = n + r - 1;
								    for (i=1;i<=arriba;i++){
									fact1 = fact1 * i;
									}
								    r2=n-1;
								    for (i=1;i<=r;i++){
									fact2 = fact2 * i;
									}
									for (i=1;i<=r2;i++){
									fact3 = fact3 * i;
									}
								    abajo = fact3 * fact2;
								    combinaciones= fact1 / abajo;
								    
								    cout << "El n�mero de combinaciones con repetici�n es de: " << combinaciones << endl; 
								    
								    cout << "�Desea calcular m�s combinaciones? (s/n)" << endl;
							        cin >> opcion;
							        opcion = tolower(opcion);
							        if (opcion != 's') {
							            regresarAlMenu = true; // Configura la variable para regresar al men� principal
							        }
							        system("cls");
                        			
								}while (!regresarAlMenu);
							
                            break;
							}
						case 5:{
							
							break;
						}
								
                        case 6:
                            // Regresar al men� anterior
                            break;
                        case 7:
                            cout << "Saliendo del programa..." << endl;
                            return 0;
                        default:
                            cout << "Opci�n no v�lida. Por favor, seleccione una opci�n v�lida." << endl;
                    }
                } while (opcion2 != 5); // Salir del bucle cuando se elija "REGRESAR AL MENU ANTERIOR"
                break;
            }
            case 3: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opci�n no v�lida. Por favor, seleccione una opci�n v�lida." << endl;
            }
        }
    } while (opcion != 3); // Salir del bucle principal cuando se elija "Salir"

    return 0;
}

