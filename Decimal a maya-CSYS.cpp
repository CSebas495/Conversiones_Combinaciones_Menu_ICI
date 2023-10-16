#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

main(){
	
	int numero,residuo, i;
	vector<int> residuos;
	cout << "Ingresa un numero entero para convertir a maya: " << endl;
	cin >> numero;
	cout << endl;
	
	
	while(numero < 0){
		cout << "Ingrese un numero postivo entero porfavor" << endl;
		cin >> numero;
	}
	
	
	if (numero == 0){
		cout << "El numero en maya es: " << endl;
		cout << "<@>" << endl;
		return 0;
	}
	
	
	while(numero > 0){
		residuo = numero % 20;
		residuos.push_back(residuo);
		numero /= 20;
	}
	
	
	reverse(residuos.begin(), residuos.end());
	
	cout << "El numero el maya es: " << endl;
	
	for(i=0; i < residuos.size(); i++){
		
		switch(residuos[i]){
		
			case 1:{
				cout << endl;
				cout << "    ©    " << endl;
				cout << endl;
				break;
			}
			
			case 2:{
				cout << endl;
				cout << "   © ©   " << endl;
				cout << endl;
				break;
			}	
			
			case 3:{
				cout << endl;
				cout << "  © © ©  " << endl;
				cout << endl;
				break;
			}	
			
			case 4:{
				cout << endl;
				cout << " © © © © " << endl;
				cout << endl;
				break;
			}	
			
			case 5:{
				cout << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}	
			
			case 6:{
				cout << endl;
				cout << "    ©    " << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}	
			
			case 7:{
				cout << endl;
				cout << "   © ©   " << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}	
			
			case 8:{
				cout << endl;
				cout << "  © © ©  " << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}	
			
			case 9:{
				cout << endl;
				cout << " © © © © " << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}	
			
			case 10:{
				cout << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}	
			
			case 11:{
				cout << endl;
				cout << "    ©    " << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}	
			
			case 12:{
				cout << endl;
				cout << "   © ©   " << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}	
			
			case 13:{
				cout << endl;
				cout << "  © © ©  " << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}	
			
			case 14:{
				cout << endl;
				cout << " © © © © " << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}	
			
			case 15:{
				cout << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}	
			
			case 16:{
				cout << endl;
				cout << "    ©    " << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}	
			
			case 17:{
				cout << endl;
				cout << "   © ©   " << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}	
			
			case 18:{
				cout << endl;
				cout << "  © © ©  " << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}	
			
			case 19:{
				cout << endl;
				cout << " © © © © " << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << "_________" << endl;
				cout << endl;
				break;
			}
			
			case 0:{
				cout << endl;
				cout << "   <@>   " << endl;
				cout << endl;
				break;
			}		
		}
	}
}
