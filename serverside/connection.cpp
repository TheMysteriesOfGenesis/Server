#include "connection.h"



connection::connection(int id)
{
	portNumber = id;
}

int connection::login(std::string * username)
{
	return 0;
}

bool connection::getLoggedIn()
{
	return loggedIn;
}

string * connection::getUsername()
{
	return nullptr;
}


connection::~connection()
{
}
