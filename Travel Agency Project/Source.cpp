#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


struct date
{
	string year, month, day;
};

struct address
{
	string street, door, floor, postal_code, locality;
};

struct travelpack
{
	int  n_sold, max_number_of_ppl;
	string identifier, places, price_per_person;
	date arrival, departure;

};

struct client
{
	int total_packs_purchased;
	string client_name, client_nif, family_members;
	address client_address;
	vector<string> n_bought_travelpacks;
};

struct agency
{
	string agency_name, agency_nif, url;
	address agency_address;
	vector<travelpack> travelpack_list;
	vector<client> client_list;
};

address GetAddress(string info)
{
	address temp;
	string name;
	vector<string> temp_vector;
	stringstream input_stringstream(info);

	while(getline(input_stringstream, name, '/'))
	{
		temp_vector.push_back(name);
	}
	temp.street = temp_vector[0];
	temp.door =  temp_vector[1];
	temp.floor = temp_vector[2];
	temp.postal_code = temp_vector[3];
	temp.locality = temp_vector[4];

	return temp;
}

vector<string> GetPacks(string info)
{

	string name;
	vector<string> temp_vector;
	stringstream input_stringstream(info);

	while (getline(input_stringstream, name, ';'))
	{
		temp_vector.push_back(name);
	}

	return temp_vector;
}

date GetDate(string info)
{
	date temp;
	string name;
	vector<string> temp_date;
	stringstream input_stringstream(info);

	while (getline(input_stringstream, name, '/'))
	{
		temp_date.push_back(name);
	}
	temp.year = temp_date[0];
	temp.month = temp_date[1];
	temp.day = temp_date[2];

	return temp;
}

client novocliente()
{
	client cliente;
	address morada;
	string test;

	//int tcomp;
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
	cliente.client_address.street = " " + cliente.client_address.street + " ";
	cout << "\n	- Porta: ";
	cin >> cliente.client_address.door;
	cliente.client_address.door = " " + cliente.client_address.door + " ";
	cout << "\n	- Andar: ";
	cin >> cliente.client_address.floor;
	cliente.client_address.floor = " " + cliente.client_address.floor + " ";
	cout << "\n	- Codigo postal: ";
	cin >> cliente.client_address.postal_code;
	cliente.client_address.postal_code = " " + cliente.client_address.postal_code + " ";
	cout << "\n	- Localidade: ";
	cin >> cliente.client_address.locality;
	cliente.client_address.locality = " " + cliente.client_address.locality + " ";

	cout << "\n--> Lista de pacotes turisticos comprados: ";
	cin.ignore(1000, '\n');
	getline(cin,test);
	cliente.n_bought_travelpacks.push_back(test);
	cout << "\n--> Total de compras efetuadas: ";
	cin >> cliente.total_packs_purchased;

	return cliente;
}

client alterarcliente(agency &Agency_struct)
{
	for (unsigned int i = 0; i < Agency_struct.client_list.size(); i++)
	{
		cout << "\n"<<Agency_struct.client_list[i].client_name;
	}

	client cliente;
	address morada;
	string test;

	int j;
	cout << "\nDigite a posicao daquele que pretende alterar: ";
	cin >> j;
	cout << "\n--> Nome: ";
	//cin >> Agency_struct.client_list[j].client_name;
	cin.ignore(1000, '\n');
	getline(cin, Agency_struct.client_list[j].client_name);
	cout << "\n--> NIF: ";
	cin >> Agency_struct.client_list[j].client_nif;
	cout << "\n--> Numero de pessoas no agregado familiar: ";
	cin >> Agency_struct.client_list[j].family_members;

	//morada
	cout << "\n--> Morada: \n\n	- Rua: ";
	cin.ignore(1000, '\n');
	getline(cin, Agency_struct.client_list[j].client_address.street);
	cout << "\n	- Porta: ";
	cin >> Agency_struct.client_list[j].client_address.door;
	cout << "\n	- Andar: ";
	cin >> Agency_struct.client_list[j].client_address.floor; 
	cout << "\n	- Codigo postal: ";
	cin >> Agency_struct.client_list[j].client_address.postal_code;
	cout << "\n	- Localidade: ";
	cin >> Agency_struct.client_list[j].client_address.locality;

	cout << "\n--> Lista de pacotes turisticos comprados: ";
	cin >> test; //Agency_struct.client_list[j].n_bought_travelpacks;
	Agency_struct.client_list[j].n_bought_travelpacks.push_back(test);
	cout << "\n--> Total de compras efetuadas: ";
	cin >> Agency_struct.client_list[j].total_packs_purchased;

	return Agency_struct.client_list[j];
}

void removercliente(agency &Agency_struct)
{
	for (unsigned int i = 0; i < Agency_struct.client_list.size(); i++)
	{
		cout << "\n"<< Agency_struct.client_list[i].client_name;
	}

	cout << "\nDigite a posicao daquele que pretende remover: ";
	int j;
	cin >> j;
	Agency_struct.client_list.erase(Agency_struct.client_list.begin()+j);
}

travelpack novotp()
{
	travelpack tp;
	//address morada;
	//string test;

	//int tcomp;
	cout << "\n:::::::::::::::::::::::\n\n";
	cout << "--> CRIAR NOVO PACOTE TURISTICO <-- \n";
	
	cout << "\n--> Identificador: ";
	cin>> tp.identifier;
	cout << "\n--> Local(ais) turistico(s) a visitar: ";
	cin.ignore(1000, '\n');
	getline(cin,tp.places);

	//data de partida
	cout << "\n--> Data de partida: \n\n	- Ano: ";
	cin >> tp.departure.year;
	cout << "\n	- Mes: ";
	cin >> tp.departure.month;
	cout << "\n	- Dia: ";
	cin >> tp.departure.day;

	//data de chegada
	cout << "\n--> Data de chegada: \n\n	- Ano: ";
	cin >> tp.arrival.year;
	cout << "\n	- Mes: ";
	cin >> tp.arrival.month;
	cout << "\n	- Dia: ";
	cin >> tp.arrival.day;

	cout << "\n--> Preco por pessoa: ";
	cin >> tp.price_per_person;
	cout << "\n--> Numero maximo de pessoas que se podem inscrever no pacote: ";
	cin >> tp.max_number_of_ppl;

	return tp;
}

travelpack alterartp(agency &Agency_struct)
{
	for (unsigned int i = 0; i < Agency_struct.travelpack_list.size(); i++)
	{
		cout << "\n"<<Agency_struct.travelpack_list[i].identifier;
	}

	travelpack tp;
	//address morada;
	//string test;

	int j;
	cout << "\nDigite a posicao daquele que pretende alterar: ";
	cin >> j;

	//address morada;
	//string test;
	
	//int tcomp;
	cout << "\n:::::::::::::::::::::::\n\n";
	cout << "--> ALTERAR PACOTE TURISTICO <-- \n";

	cout << "\n--> Identificador: ";
	cin >> Agency_struct.travelpack_list[j].identifier;
	cout << "\n--> Local(ais) turistico(s) a visitar: ";
	cin.ignore(1000, '\n');
	getline(cin, Agency_struct.travelpack_list[j].places);

	//data de partida
	cout << "\n--> Data de partida: \n\n	- Ano: ";
	cin >> Agency_struct.travelpack_list[j].departure.year;
	cout << "\n	- Mes: ";
	cin >> Agency_struct.travelpack_list[j].departure.month;
	cout << "\n	- Dia: ";
	cin >> Agency_struct.travelpack_list[j].departure.day;

	//data de chegada
	cout << "\n--> Data de chegada: \n\n	- Ano: ";
	cin >> Agency_struct.travelpack_list[j].arrival.year;
	cout << "\n	- Mes: ";
	cin >> Agency_struct.travelpack_list[j].arrival.month;
	cout << "\n	- Dia: ";
	cin >> Agency_struct.travelpack_list[j].arrival.day;

	cout << "\n--> Preco por pessoa: ";
	cin >> Agency_struct.travelpack_list[j].price_per_person;
	cout << "\n--> Numero maximo de pessoas que se podem inscrever no pacote: ";
	cin >> Agency_struct.travelpack_list[j].max_number_of_ppl;

	cout << "\n--> Numero de lugares vendidos: ";
	cin >> Agency_struct.travelpack_list[j].n_sold;

	return Agency_struct.travelpack_list[j];

}


void removertp(agency &Agency_struct)
{
	for (unsigned int i = 0; i < Agency_struct.travelpack_list.size(); i++)
	{
		cout << "\n"<<Agency_struct.travelpack_list[i].identifier;
	}

	cout << "\nDigite a posicao daquele que pretende remover: ";
	int j;
	cin >> j;

	string n = Agency_struct.travelpack_list[j].identifier;
	//n=stoi(n);
	if (stoi(n) > 0) {
		Agency_struct.travelpack_list[j].identifier = to_string(0 - stoi(n));
	}

	// delete: Agency_struct.travelpack_list.erase(Agency_struct.travelpack_list.begin() + j);
}

void dadoscliente(agency &Agency_struct)
{
	for (unsigned int i = 0; i < Agency_struct.client_list.size(); i++)
	{
		cout << "\n"<<Agency_struct.client_list[i].client_name;
	}

	client cliente;
	address morada;
	string test;

	int j;
	cout << "\nDigite a posicao daquele que pretende alterar: ";
	cin >> j;
	cout << "\nNome: " << Agency_struct.client_list[j].client_name;
	cout << "\nNIF: " << Agency_struct.client_list[j].client_nif;
	cout << "\nAgregado familiar: " << Agency_struct.client_list[j].family_members;
	cout << "\nMorada: " << Agency_struct.client_list[j].client_address.street<<"/"<< Agency_struct.client_list[j].client_address.door<<"/"<< Agency_struct.client_list[j].client_address.floor<<"/"<<Agency_struct.client_list[j].client_address.postal_code<<"/"<< Agency_struct.client_list[j].client_address.locality;
	cout << "\nLista de pacotes turisticos comprados: ";
	for (int i = 0; i < (Agency_struct.client_list[j].n_bought_travelpacks.size());i++)
	{
		cout << Agency_struct.client_list[j].n_bought_travelpacks[i];
	}
	cout << "\nTotal de compras efetuadas: " << Agency_struct.client_list[j].total_packs_purchased;


}

void dadostodosclientes(agency &Agency_struct)
{

	for (int j = 0; j < Agency_struct.client_list.size(); j++)

	{
		cout << "\n:::::::::::::::::::::::\n";

		cout << "Nome: " << Agency_struct.client_list[j].client_name;
		cout << "\nNIF: " << Agency_struct.client_list[j].client_nif;
		cout << "\nAgregado familiar: " << Agency_struct.client_list[j].family_members;
		cout << "\nMorada: " << Agency_struct.client_list[j].client_address.street << "/" << Agency_struct.client_list[j].client_address.door << "/" << Agency_struct.client_list[j].client_address.floor << "/" << Agency_struct.client_list[j].client_address.postal_code << "/" << Agency_struct.client_list[j].client_address.locality;
		cout << "\nLista de pacotes turisticos comprados: ";
		for (int i = 0; i < Agency_struct.client_list[j].n_bought_travelpacks.size(); i++)
		{
			cout << Agency_struct.client_list[j].n_bought_travelpacks[i];
		}
		cout << "\nTotal de compras efetuadas: " << Agency_struct.client_list[j].total_packs_purchased;
	}
}

void dadostp(agency &Agency_struct)
{
	
	for (unsigned int i = 0; i < Agency_struct.travelpack_list.size(); i++)
	{
		cout << "\n:::::::::::::::::::::::\n";
		cout << "\n Identificador: " << Agency_struct.travelpack_list[i].identifier;
		cout << "\n Destino(s): " << Agency_struct.travelpack_list[i].places;
		cout << "\n Partida: " << Agency_struct.travelpack_list[i].departure.year << "/" << Agency_struct.travelpack_list[i].departure.month << "/" << Agency_struct.travelpack_list[i].departure.day;
		cout << "\n Chegada: " << Agency_struct.travelpack_list[i].arrival.year << "/" << Agency_struct.travelpack_list[i].arrival.month << "/" << Agency_struct.travelpack_list[i].arrival.day;
		cout << "\n Custo por pessoa: " << Agency_struct.travelpack_list[i].price_per_person;
		cout << "\n Numero de lugares disponiveis: " << Agency_struct.travelpack_list[i].max_number_of_ppl;
		cout << "\n Numero de lugares vendidos: " << Agency_struct.travelpack_list[i].n_sold;
	}

}

// CHECKPOINT 
void filterdest(agency &Agency_struct)
{
	cout << "Pretended destination: ";
	string destination;
	cin >> destination;

}


/*void filterdate(agency &Agency_struct)
{
	
}
*/

/*filterboth(agency &Agency_struct)
{
	
}
*/

void comprarpacote(agency &Agency_struct)
{
	for (unsigned int i = 0; i < Agency_struct.client_list.size(); i++)
	{
		cout << "\n" <<Agency_struct.client_list[i].client_name;
	}

	client cliente;
	address morada;
	string test;

	int cl;
	cout << "\nDigite a posicao relativa ao cliente: ";
	cin >> cl;

	for (unsigned int i = 0; i < Agency_struct.travelpack_list.size(); i++)
	{
		cout << "\n"<<Agency_struct.travelpack_list[i].identifier;
	}

	travelpack tp;

	int j;
	cout << "\nDigite a posicao relativa ao pacote pretendido: ";
	cin >> j; 

	Agency_struct.client_list[cl].n_bought_travelpacks.push_back("  ");
	Agency_struct.client_list[cl].n_bought_travelpacks.push_back(Agency_struct.travelpack_list[j].identifier);
	Agency_struct.client_list[cl].total_packs_purchased += 1;

	Agency_struct.travelpack_list[j].n_sold += 1;
	Agency_struct.travelpack_list[j].max_number_of_ppl -= 1;

}

// tp data option menu CHECKPOINT //

void menutpdata(agency &Agency_struct)
{
	cout << "\n\n [1] --> see all data; \n [2] --> filter by destination; \n [3] --> filter by date; \n [4] --> filter by date and destination;\n\n  ";
	char option;
	cin >> option;
	switch (option)
	{
	case '1':
		dadostp(Agency_struct);
		break;

	/*case 2:
		filterdest();
		break;

	case 3:
		filterdate();
		break;

	case 4:
		filterboth();
		break;*/

	/////  CHECKPOINT  -  ARRANJAR O DEFAULT  /////

	default:
		cout << " Invalid option. Please select one of the above.";
		menutpdata(Agency_struct);
		
	}

}

int main()
{

	// info da agency
	ifstream info("agency.txt");
	agency Agency_struct;
	vector<string> agency_info;
	string name;


	if (info.is_open())
	{
		while (getline(info, name))
		{
			agency_info.push_back(name);
		}
		info.close();
	}
	else cout << "Unable to open file";

	
	Agency_struct.agency_name = agency_info[0];
	Agency_struct.agency_nif = agency_info[1];
	Agency_struct.url = agency_info[2];

	Agency_struct.agency_address = GetAddress(agency_info[3]);

	
	ifstream info2(agency_info[4]);
	client temp_client;
	vector<client> vector_client;
	vector<string> client_list;
	string line;
	

	while (getline(info2, line))
	{
	
			if (line != "::::::::::") client_list.push_back(line);
			else
			{
				temp_client.client_name = client_list[0];
				temp_client.client_nif = client_list[1];
				temp_client.family_members = client_list[2];
				temp_client.client_address = GetAddress(client_list[3]);
				temp_client.n_bought_travelpacks = GetPacks(client_list[4]);
				temp_client.total_packs_purchased = temp_client.n_bought_travelpacks.size();
				vector_client.push_back(temp_client);

				client_list.clear();
			}
	}
	temp_client.client_name = client_list[0];
	temp_client.client_nif = client_list[1];
	temp_client.family_members = client_list[2];
	temp_client.client_address = GetAddress(client_list[3]);
	temp_client.n_bought_travelpacks = GetPacks(client_list[4]);
	temp_client.total_packs_purchased = temp_client.n_bought_travelpacks.size();
	vector_client.push_back(temp_client);
	Agency_struct.client_list = vector_client;

	/////travelpacks

	ifstream info3(agency_info[5]);
	travelpack temp_tp;
	vector<travelpack> vector_tp;
	vector<string> tp_list;
	string name3;
	string lastcreated;
	getline(info3, lastcreated);

	while (getline(info3, name3))
	{
		
		if (name3 != "::::::::::") tp_list.push_back(name3);
		else
		{
			temp_tp.identifier = tp_list[0];
			temp_tp.places = tp_list[1];
			temp_tp.arrival = GetDate(tp_list[2]);
			temp_tp.departure = GetDate(tp_list[3]);
			temp_tp.price_per_person = tp_list[4];
			temp_tp.max_number_of_ppl = stoi(tp_list[5]);
			temp_tp.n_sold = stoi(tp_list[6]);
			vector_tp.push_back(temp_tp);

			tp_list.clear();

		}
	}
	temp_tp.identifier = tp_list[0];
	temp_tp.places = tp_list[1];
	temp_tp.arrival = GetDate(tp_list[2]);
	temp_tp.departure = GetDate(tp_list[3]);
	temp_tp.price_per_person = tp_list[4];
	temp_tp.max_number_of_ppl = stoi(tp_list[5]);
	temp_tp.n_sold = stoi(tp_list[6]);
	vector_tp.push_back(temp_tp);

	Agency_struct.travelpack_list = vector_tp;
	
	bool end = false;

	while (!end) {
		int n;
		cout << "\n\n\n:::::::::::::::::::::::\n";
		cout << "\n     NICE HOLIDAYS     \n";
		cout << "\n:::::::::::::::::::::::\n\n";
		cout << "Select the pretended option: \n \n" << "[1] - add client; \n[2] - change client; \n[3] - remove client; \n[4] - create travel pack; \n[5] - change travel pack; \n[6] - remove travel pack; \n[7] - specific client data; \n[8] - all clients data; \n[9] - travel packs data; \n[10] - purchase travel pack; \n[11] - save changes and exit;\n\n";
		cin >> n;
		switch (n) {
		case 1:
			Agency_struct.client_list.push_back(novocliente());
			break;
		case 2:
			alterarcliente(Agency_struct);
			break;
		case 3:
			removercliente(Agency_struct);
			break;
		case 4:
			Agency_struct.travelpack_list.push_back(novotp()); 
			break;
		case 5:
			alterartp(Agency_struct);
			break;
		case 6:
			removertp(Agency_struct);
			break;
		case 7:
			dadoscliente(Agency_struct);
			break;
		case 8:
			dadostodosclientes(Agency_struct);
			break;
		case 9:
			//dadostp(Agency_struct);
			menutpdata(Agency_struct);
			break;
		case 10:
			comprarpacote(Agency_struct);
			break;

		case 11:
			
			//client update

			info2.close();
			ofstream info2(agency_info[4]);
			info2.clear();

			int sizevariable = Agency_struct.client_list.size() - 1;

			for (int i = 0; i < sizevariable; i++)
			{
				info2 << Agency_struct.client_list[i].client_name << endl << Agency_struct.client_list[i].client_nif << endl << Agency_struct.client_list[i].family_members << endl << Agency_struct.client_list[i].client_address.street << "/" << Agency_struct.client_list[i].client_address.door << "/" << Agency_struct.client_list[i].client_address.floor << "/" << Agency_struct.client_list[i].client_address.postal_code << "/" << Agency_struct.client_list[i].client_address.locality << endl;

				int sizevariable2 = Agency_struct.client_list[i].n_bought_travelpacks.size();

				for (int j = 0; j < sizevariable2; j++)
				{
					info2 << Agency_struct.client_list[i].n_bought_travelpacks[j] << " ";
				}

				info2 << endl << Agency_struct.client_list[i].total_packs_purchased << endl << "::::::::::" << endl;

			}

			//last one

			int i = Agency_struct.client_list.size() - 1;

			info2 << Agency_struct.client_list[i].client_name << endl << Agency_struct.client_list[i].client_nif << endl << Agency_struct.client_list[i].family_members << endl << Agency_struct.client_list[i].client_address.street << "/" << Agency_struct.client_list[i].client_address.door << "/" << Agency_struct.client_list[i].client_address.floor << "/" << Agency_struct.client_list[i].client_address.postal_code << "/" << Agency_struct.client_list[i].client_address.locality << endl;

			int sizevariable2 = Agency_struct.client_list[i].n_bought_travelpacks.size();

			for (int j = 0; j < sizevariable2; j++)
			{
				info2 << Agency_struct.client_list[i].n_bought_travelpacks[j] << " ";
			}

			info2 << endl << Agency_struct.client_list[i].total_packs_purchased << endl;


			//end = true;


			//travel pack update

			info3.close();
			ofstream info3(agency_info[5]);
			info3.clear();

			sizevariable2 = Agency_struct.travelpack_list.size() - 1;

			info3 << lastcreated << endl;

			for (int i = 0; i < sizevariable2; i++) 
			{
				info3 << Agency_struct.travelpack_list[i].identifier << endl << Agency_struct.travelpack_list[i].places << endl << Agency_struct.travelpack_list[i].departure.day << "/" << Agency_struct.travelpack_list[i].departure.month << "/" << Agency_struct.travelpack_list[i].departure.year << endl << Agency_struct.travelpack_list[i].arrival.day << "/" << Agency_struct.travelpack_list[i].arrival.month << "/" << Agency_struct.travelpack_list[i].arrival.year << endl << Agency_struct.travelpack_list[i].price_per_person << endl << Agency_struct.travelpack_list[i].max_number_of_ppl << endl << Agency_struct.travelpack_list[i].n_sold << endl << "::::::::::" << endl;

			}

			//last one

			i = Agency_struct.client_list.size() - 1;

			info3 << Agency_struct.travelpack_list[i].identifier << endl << Agency_struct.travelpack_list[i].places << endl << Agency_struct.travelpack_list[i].departure.day << "/" << Agency_struct.travelpack_list[i].departure.month << "/" << Agency_struct.travelpack_list[i].departure.year << endl << Agency_struct.travelpack_list[i].arrival.day << "/" << Agency_struct.travelpack_list[i].arrival.month << "/" << Agency_struct.travelpack_list[i].arrival.year << endl << Agency_struct.travelpack_list[i].price_per_person << endl << Agency_struct.travelpack_list[i].max_number_of_ppl << endl << Agency_struct.travelpack_list[i].n_sold << endl;
			
			end = true;

			break;
		}

		}
	
}