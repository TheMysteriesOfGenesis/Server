#include "Server.h"
#include "database.h"

int main()
{
	system("color 5a");
    MySQL:MySQL();
	std::cout << "Server Has Started" << std::endl;
	Server MyServer(1111); //Create server on port 100
	for (int i = 0; i < 100; i++) //Up to 100 times...
	{
		MyServer.ListenForNewConnection(); //Accept new connection (if someones trying to connect)
	}
	system("pause");
	return 0;
}