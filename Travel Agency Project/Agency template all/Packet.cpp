#include "Packet.h"

Packet::Packet(vector<string> sites, Date inicio, Date fim, double precoPessoa, unsigned maxPessoas, unsigned soldTickets){

	this->sites = sites;
	inicio = begin;
	fim = end;
	precoPessoa = pricePerPerson;
	maxPessoas = maxPeople;
	this->soldTickets = soldTickets;
}

  // metodos GET

unsigned Packet::getId() const{

	return id;
}

vector<string> Packet::getSites() const{

	return sites;
}

Date Packet::getBeginDate() const{

	return begin;
}

Date Packet::getEndDate() const{

	return end;
}

double Packet::getPricePerPerson() const{

	return pricePerPerson;
}

unsigned Packet::getMaxPeople() const{

	return maxPeople;
}

unsigned Packet::getSoldTickets() const {

	return soldTickets;
}

  // metodos SET

void Packet::setId(unsigned id){

	this->id = id;
}

void Packet::setSites(vector<string> sites){

	this->sites = sites;
}

void Packet::setBeginDate(Date begin){

	this->begin = begin;
}

void Packet::setEndDate(Date end){

	this->end = end;
}

void Packet::setPricePerPerson(double pricePerPerson){

	this->pricePerPerson = pricePerPerson;
}

void Packet::setMaxPeople(unsigned maxPersons){

	this->maxPeople = maxPeople;
}

void Packet::setSoldTickets(unsigned soldTickets) {

	this->soldTickets = soldTickets;
}


/*********************************
 * Show Packet information
 ********************************/  

// shows a packet content 
/*ostream& operator<<(ostream& out, const Packet & packet){

	
	out << packet.id << endl << packet.sites << endl << packet.begin.getYear() << endl << packet.end.getYear() << endl << packet.pricePerPerson << endl << packet.maxPeople << endl << packet.soldTickets;
	


	return out

}*/
