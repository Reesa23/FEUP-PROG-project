#pragma once
#include <iostream>
#include <vector>
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
	string identifier, places, price_per_person, max_number_of_ppl, n_sold;
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
