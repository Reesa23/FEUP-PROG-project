#include "Client.h"

Client::Client()
{
}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address){
  
	this->name = name;
	this->VATnumber = VATnumber;
	this->familySize = familySize;
	this->address = address;
}

Client::Client(string name, unsigned VATnumber, unsigned short familySize, Address address, vector<string> & packets, unsigned totalPurchased){
  
	this->name = name;
	this->VATnumber = VATnumber;
	this->familySize = familySize;
	this->address = address;
	this->packets = packets;
	this->totalPurchased = totalPurchased;

}

  // GET methods

string Client::getName() const{
  
	return name;
}
  
unsigned Client::getVATnumber() const{
  
	return VATnumber;
}

unsigned short Client::getFamilySize() const{
  
	return familySize;
}

Address Client::getAddress() const{
  
	return address;
}

vector<string> Client::getPacketList() const{
  
	return packets;
}

unsigned Client::getTotalPurchased() const{
  
	return totalPurchased;
}
  
  // metodos SET
	  
void Client::setName(string nome){
  
	this->name = name;
}

void Client::setVATnumber(unsigned VATnumber){
  
	this->VATnumber = VATnumber;
}

void Client::setFamilySize(unsigned short familySize){
  
	this->familySize = familySize;
}
void Client::setAddress(Address address){
  
	this->address = address;
}
void Client::setPacketList(vector<string> & packets){
  
	this->packets = packets;
}
void Client::setTotalPurchased(unsigned totalPurchased){
  
	this->totalPurchased = totalPurchased;
}
  
  // outros metodos
/*
ostream& operator<<(ostream& out, const Client & client){

	return cout << client.name << endl << client.VATnumber << endl << client.familySize << endl << client.address << endl << client.packets << endl << client.totalPurchased;

}*/
