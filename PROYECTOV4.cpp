#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <sstream>
#include <string>
#include <cmath>
#include <ctype.h>
#include <iomanip> // Para std::hex
/* #include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;    Usar para que el factorial pueda llegar a 13 o másx	 */ 
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

    // Añadir ceros a la izquierda para que el número de dígitos sea múltiplo de 3
    while (tamano % 3 != 0) {
        binarioConCeros.insert(0, "0");
        ++tamano;
    }

    for (int i = 0; i < tamano; i += 3) {
        string subcadena = binarioConCeros.substr(i, 3); // Tomar grupos de 3 dígitos binarios
        int decimal = binarioADecimal(subcadena); // Convertir el grupo a decimal
        octal += intToString(decimal); // Agregar el valor decimal a la representación octal
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

    return hexadecimal; // Agregar el prefijo "0x" para representación hexadecimal
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
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int opcion2;
                do {
                    system("cls");
                    cout << "MENU CONVERSIONES" << endl;
                    cout << "1. CONVERSIÓN DE DECIMAL A MAYA" << endl;
                    cout << "2. CONVERSIÓN DE DECIMAL A BINARIO" << endl;
                    cout << "3. CONVERSIÓN DE DECIMAL A OCTAL" << endl;
                    cout << "4. CONVERSIÓN DE DECIMAL A HEXADECIMAL" << endl;
                    cout << "5. CONVERSIÓN DE BINARIO A DECIMAL" << endl;
                    cout << "6. CONVERSIÓN DE BINARIO A OCTAL" << endl;
                    cout << "7. CONVERSIÓN DE BINARIO A HEXADECIMAL" << endl;
                    cout << "8. REGRESAR AL MENU ANTERIOR" << endl;
                    cout << "9. SALIR DEL PROGRAMA" << endl;
                    cout << "Seleccione una opción: ";
                    cin >> opcion2;

                    switch (opcion2) {
                        case 1:{
                        		system("cls");
                        	    int num, i;
                        	    bool regresarAlMenu = false; // Variable para controlar el regreso al menú
                        	    char opcion;
                        	    do {
							    cout << "Dame un número entero: " << endl;
							    cin >> num;
							    cout << "El número en maya es:\n";
							
							    if (num == 0) {
							        cout << "Maya: @ \n";
							    }
							
							    char maya[4] = {'.', '@', '-'};
							    int base = 1;
							
							    string mayaR = ""; // Almacena la representación maya en una cadena
							
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
							
							    // Imprime la representación maya en orden inverso
							    for (int i = mayaR.length() - 1; i >= 0; i--) {
							    	cout << mayaR[i];
							    }
							    cout << "\n¿Desea convertir otro número? s/n" << endl;
								cin >> opcion;
								opcion = tolower(opcion);
								if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al menú principal
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
								cout << "Ingresa el número que quieras convertir a binario: " << endl;
								cin >> numero;
								if (numero == 0){
									binario_entero = "0"; 
								}
								while (numero < 0){
									cout << "Ingrese un número valido positivo" << endl;
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
								cout << "El número en binario es: "<< binario_entero << endl;
								cout << "¿Desea convertir otro número? s/n" << endl;
								cin >> opcion;
								opcion = tolower(opcion);
								if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al menú principal
						        }
						        system("cls");
							}while (!regresarAlMenu);
							
                            break;}
                        case 3: {
                        	system("cls");
						    double numero, fraccion, OCTFAC;
						    int residuoE, residuo_fraccion, entero;
						    char opcion;
						    bool regresarAlMenu = false; // Variable para controlar el regreso al menú
						
						    do {
						        string octal_entero = "";
						        string octal_fraccion = "";
						        cout << "Ingresa el número que quieras convertir a octal: " << endl;
						        cin >> numero;
						        if (numero == 0) {
						            octal_entero = "0";
						        }
						        while (numero < 0) {
						            cout << "Ingrese un número válido y positivo" << endl;
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
						        cout << "El número en octal es: " << octal_entero << endl;
						        cout << "¿Desea convertir otro número? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al menú principal
						        }
						        system("cls");
						    } while (!regresarAlMenu); // Volver al menú principal si la variable es verdadera
						    break;
						}
                        	
                        case 4:{
                        	system("cls");    
							bool regresarAlMenu = false;
						    int numeroDecimal;
						    char opcion;

							do{
							    cout << "Ingrese un número decimal: ";
							    cin >> numeroDecimal;
							    while( numeroDecimal<0){
									cout << "Ingrese un número válido y positivo" << endl;
						            cin >> numeroDecimal;
								}
							    
							    cout << "El número en hexadecimal es: " << hex << numeroDecimal << endl;
							    cout << "¿Desea convertir otro número? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al menú principal
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
							    cout << "Ingrese un número binario: ";
							    cin >> numeroBinario;
							
							    int decimal = binarioADecimal(numeroBinario);
							
							    cout << "El número en decimal es: " << decimal << endl;
							    cout << "¿Desea convertir otro número? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al menú principal
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
								cout << "Ingrese un número binario: ";
							    cin >> numeroBinario;
							
							    string octal = binarioAOctal(numeroBinario);
							
							    cout << "El número en octal es: " << octal << endl;
							    cout << "¿Desea convertir otro número? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al menú principal
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
								cout << "Ingrese un número binario: ";
							    cin >> numeroBinario;
							
							    string hexadecimal = binarioAHexadecimal(numeroBinario);
							
							    cout << "El número en hexadecimal es: " << hexadecimal << endl;
							    cout << "¿Desea convertir otro número? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al menú principal
						        }
						        system("cls");
							} while(!regresarAlMenu);
                            break;}
                        	
                        	
                        case 8:
                            // Regresar al menú anterior
                            break;
                        case 9:
                            cout << "Saliendo del programa..." << endl;
                            return 0;
                        default:
                            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                    }
                } while (opcion2 != 8); // Salir del bucle cuando se elija "REGRESAR AL MENU ANTERIOR"
                break;
            }
            case 2: {
                int opcion2;
                do {
                    system("cls");
                    cout << "MENÚ COMBINATORIAS" << endl;
                    cout << "1. PERMUTACIONES ORDINARIAS" << endl;
                    cout << "2. PERMUTACIONES CON DOS ASPECTOS" << endl;
                    cout << "3. PRINCIPIO DEL PALOMAR" << endl;
                    cout << "4. COMBINACIONES" << endl;
                    cout << "5. PIRAMIDE DE PASCAL" << endl;
                    cout << "6. REGRESAR AL MENÚ ANTERIOR" << endl;
                    cout << "7. SALIR DEL PROGRAMA" << endl;
                    cout << "Seleccione una opción: ";
                    cin >> opcion2;

                    switch (opcion2) {
                        case 1:{
                        	system("cls");
                        	bool regresarAlMenu = false;
                        	char opcion;
                        	int num, fact=1, i;
                        	do{
								cout << "Ingrese un número entero para calcular sus permutaciones: ";
							    cin >> num;
							    while (num<0){
							    	cout << "Ingrese un número igual o mayor a 0";
							    	cin >> num;
								}
								if(num>0){
								
								for (i=1;i<=num;i++){
									fact = fact * i;
								}
								}else{fact=0;
								}
								cout << "El número de permutaciones ordinarias que existen es de: " << fact << endl;
								
							    cout << "¿Desea calcular otro número? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al menú principal
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
								cout << "Ingrese el número de elementos (n): ";
							    cin >> n;
							    cout << "Ingrese la longitud de la permutación (r): ";
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
							        cout << "El número de permutaciones con 2 aspectos es: " << permut << endl;
							    } else {
							        cout << "Entrada no válida. Asegúrese de que n >= r y ambos sean no negativos." << endl;
									cout << "Ingrese el número de elementos (n): ";
								    cin >> n;
								    cout << "Ingrese la longitud de la permutación (r): ";
								    cin >> r;
							    }
								
							    cout << "¿Desea calcular otro número? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al menú principal
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
                        			    

							    cout << "Ingrese el número de palomares: ";
							    cin >> numPalomares;
							
							    cout << "Ingrese el número de palomas: ";
							    cin >> numPalomas;
							
							    if (numPalomas > numPalomares) {
							        cout << "Principio del Palomar: Al menos un palomar debe tener más de una paloma." << endl;
							    } else {
							        cout << "Principio del Palomar: Todas las palomas pueden estar en palomares diferentes." << endl;
							    }
							    
							    cout << "¿Desea comparar otros palomares y palomas? (s/n)" << endl;
						        cin >> opcion;
						        opcion = tolower(opcion);
						        if (opcion != 's') {
						            regresarAlMenu = true; // Configura la variable para regresar al menú principal
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
                        			cout << "Ingrese el número total de elementos (n): ";
								    cin >> n;
								
								    cout << "Ingrese el número de elementos en cada combinación (r): ";
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
								    
								    cout << "El número de combinaciones con repetición es de: " << combinaciones << endl; 
								    
								    cout << "¿Desea calcular más combinaciones? (s/n)" << endl;
							        cin >> opcion;
							        opcion = tolower(opcion);
							        if (opcion != 's') {
							            regresarAlMenu = true; // Configura la variable para regresar al menú principal
							        }
							        system("cls");
                        			
								}while (!regresarAlMenu);
							
                            break;
							}
						case 5:{
							
							break;
						}
								
                        case 6:
                            // Regresar al menú anterior
                            break;
                        case 7:
                            cout << "Saliendo del programa..." << endl;
                            return 0;
                        default:
                            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                    }
                } while (opcion2 != 5); // Salir del bucle cuando se elija "REGRESAR AL MENU ANTERIOR"
                break;
            }
            case 3: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            }
        }
    } while (opcion != 3); // Salir del bucle principal cuando se elija "Salir"

    return 0;
}

