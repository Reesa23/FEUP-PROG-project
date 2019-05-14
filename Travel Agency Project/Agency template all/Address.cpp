#include "Address.h"


Address::Address(){
}

Address::Address(string adr_str) {

	vector <string> addressInfo;
	string temp = "";

	for (int i = 0; i < adr_str.length(); i++)
	{
		if (adr_str[i] == '/')
		{
			addressInfo.push_back(temp);
			temp.clear();
		}
		else
		{
			temp += adr_str[i];
		}
	}
	addressInfo.push_back(temp);

	street = addressInfo[0];
	doorNumber = stoi(addressInfo[1]);
	floor = addressInfo[2];
	postalCode = addressInfo[3];
	location = addressInfo[4];

}

Address::Address(string street, unsigned short doorNumber, string floor, string postalCode, string location){

	this->street = street;
	this->doorNumber = doorNumber;
	this->floor = floor;
	this->postalCode = postalCode;
	this->location = location;
}

  // metodos GET


string Address::getStreet() const{

	return street;
}

unsigned short Address::getDoorNumber() const{

	return doorNumber;
}

string Address::getFloor() const{
  
	return floor;
}

string Address::getPostalCode() const{

	return postalCode;
}

string Address::getLocation() const{

	return location;
}


  // metodos SET

void Address::setStreet(string street){

	this->street = street;
  // REQUIRES IMPLEMENTATION
}

void Address::setDoorNumber(unsigned short doorNumber){
	
	this->doorNumber = doorNumber;
  // REQUIRES IMPLEMENTATION
}

void Address::setFloor(string floor){

	this->floor = floor;
  // REQUIRES IMPLEMENTATION
}

void Address::setPostalCode(string postalCode){

	this->postalCode = postalCode;
  // REQUIRES IMPLEMENTATION
}

void Address::setLocation(string  location){

	this->location = location;
}


/*********************************
 * Mostrar Address
 ********************************/  

ostream& operator<<(ostream& out, const Address & address){

	return cout << address.street << " / " << address.doorNumber << " / " << address.floor << " / " << address.postalCode << " / " << address.location;

}
