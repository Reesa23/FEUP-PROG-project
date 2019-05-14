#include "Agency.h"
#include <fstream>


Agency::Agency(string fileName){

	ifstream info(fileName);
	//agency Agency_struct;
	vector<string> agency_info;
	string name;


	
	while (getline(info, name))
	{			
		agency_info.push_back(name);
	}
	info.close();
	

	name = agency_info[0];
	VATnumber = stoi(agency_info[1]);
	URL = agency_info[2];
	address = agency_info[3];
	string clientsFileName = agency_info[4];
	string packetsFileName = agency_info[5];

	// CLIENTS //

	ifstream clientsFile(clientsFileName);
	Client temp_client;
	//vector<Client> vector_client;
	vector<string> client_list;
	string line;


	while (getline(clientsFile, line))
	{

		if (line != "::::::::::") client_list.push_back(line);
		else
		{
			temp_client.setName(client_list[0]);
			temp_client.setVATnumber(stoi(client_list[1]));
			temp_client.setFamilySize(stoi(client_list[2]));
			temp_client.setAddress(client_list[3]);
			//temp_client.setPacketList(client_list[4]);
			//function to obtain the vector of packs bought
			string packs_list = client_list[4];
			vector <string> temp_vect;
			string temp_str;
			for (int i = 0; i < packs_list.length(); i++) {
				if (i == ';') {
					temp_vect.push_back(temp_str);
					temp_str.clear();
				}
				else {
					temp_str += packs_list[i];
				}
			}
			temp_vect.push_back(temp_str);
			temp_client.setPacketList(temp_vect);

			temp_client.setTotalPurchased(temp_client.getPacketList().size());

			clients.push_back(temp_client);

			client_list.clear();
		}
	}

	temp_client.setName(client_list[0]);
	temp_client.setVATnumber(stoi(client_list[1]));
	temp_client.setFamilySize(stoi(client_list[2]));
	temp_client.setAddress(client_list[3]);
	//temp_client.setPacketList(client_list[4]);
	//function to obtain the vector of packs bought
	string packs_list = client_list[4];
	vector <string> temp_vect;
	string temp_str;
	for (int i = 0; i < packs_list.length(); i++) {
		if (i == ';') {
			temp_vect.push_back(temp_str);
			temp_str.clear();
		}
		else {
			temp_str += packs_list[i];
		}
	}
	temp_vect.push_back(temp_str);
	temp_client.setPacketList(temp_vect);

	temp_client.setTotalPurchased(temp_client.getPacketList().size());

	clients.push_back(temp_client);

	// TRAVEL PACKS //

}

  // metodos GET
string Agency::getName() const{

	return name;
}

unsigned Agency::getVATnumber() const{

	return VATnumber;
}

Address Agency::getAddress() const{

	return address;
}

string Agency::getURL() const{

	return URL;
}

vector<Client> Agency::getClients() const{

	return clients;
}

vector<Packet> Agency::getPackets() const{

	return packets;
}

  
  // SET Methods

void Agency::setName(string name){

	this->name = name;
}

void Agency::setVATnumber(unsigned VATnumber){

	this->VATnumber = VATnumber;

}

void Agency::setAddress(Address address){

	this->address = address;

}
  void Agency::setURL(string url){

	  this->URL = URL;
}

  void Agency::setClients(vector<Client> & clients){

	  this->clients = clients;

  }
  void Agency::setPackets(vector<Packet> & packets){

	  this->packets = packets;
}


  /*void Agency::changeclient()
  {



  }*/
/*********************************
 * Mostrar Loja
 ********************************/  

// mostra o conteudo de uma agencia
/* ostream& operator<<(ostream& out, const Agency & agency){

	return cout << agency.name << endl << agency.VATnumber << endl << agency.URL << endl << agency.address << endl << agency.clients << endl << agency.packets;
}
*/