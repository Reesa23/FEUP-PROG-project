#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>
#include <string>
#include "structs.h"
#include "functions.h"

int menu1()


{
	client cliente;
	address morada;
	string test;
	
	ofstream clientFile("clients.txt");


	int tcomp;
	cout << "\n:::::::::::::::::::::::\n\n";
	cout << "--> CRIAR NOVO CLIENTE <-- \n";
	cin.ignore(1000, '\n');
	cout << "\n--> Nome: ";
	getline(cin, cliente.client_name);
	cout << "\n--> NIF: ";
	cin >> cliente.client_nif;
	cout << "\n--> Numero de pessoas no agregado familiar: ";
	cin >> cliente.family_members;

	//morada
	cout << "\n--> Morada: \n\n	- Rua: ";
	cin.ignore(1000, '\n');
	getline(cin, cliente.client_address.street);
	cout << "\n	- Porta: ";
	cin >> cliente.client_address.door;
	cout << "\n	- Andar: ";
	cin >> cliente.client_address.floor;
	cout << "\n	- Codigo postal: ";
	cin >> cliente.client_address.postal_code;
	cout << "\n	- Localidade: ";
	cin >> cliente.client_address.locality;

	cout << "\n--> Lista de pacotes turisticos comprados: ";
	cin >> test;
	cliente.n_bought_travelpacks.push_back(test);
	cout << "\n--> Total de compras efetuadas: ";
	cin >> cliente.total_packs_purchased;

	
	return 1;

}

