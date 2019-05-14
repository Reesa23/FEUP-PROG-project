#include "Date.h"

Date::Date(){
}

Date::Date(string date){
  
	string temp;
	vector <string> dateInfo;
	for (int i = 0; i < date.length(); i++)
	{
		if (date[i] == '/')
		{
			dateInfo.push_back(temp);
			temp.clear();
		}
		else
			temp += date[i];
	}
	dateInfo.push_back(temp);

	year = stoi(dateInfo[0]);
	month = stoi(dateInfo[1]);
	day = stoi(dateInfo[2]);

}


Date::Date(unsigned short day, unsigned short month, unsigned year){

	this->day = day;
	this->month = month;
	this->year = year;
}

/*********************************
 * GET Methods
 ********************************/
unsigned short Date::getDay() const{

	return day;

}

  
unsigned short Date::getMonth() const{

	return month;

}
    
unsigned Date::getYear() const{

	return year;

}

/*********************************
 * SET Methods
 ********************************/

void Date::setDay(unsigned short day){
  
	this->day = day;

}
void Date::setMonth(unsigned short month){
  
	this->month = month;

}

void Date::setYear(unsigned year){

	this->year = year;

}


/*********************************
 * Show Date
 ********************************/  

// disply a Date in a nice format
ostream& operator<<(ostream& out, const Date & date){

	return cout << date.year << "/" << date.month << "/" << date.day;

}

