#pragma once

#include <stdio.h>
#include <string>

using namespace std;

//Connection object to store data about a connection
class Client
{
public:
	bool loggedIn;
	int portNumber;
	std::string *username; //should be replaces by an actual reference to the user object when finished
	Client(int portnumber);
	int login(std::string *username);
	bool getLoggedIn();
	string* getUsername();
	~Client();
};

