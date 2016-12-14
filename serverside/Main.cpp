#include "Server.h"
#include "database.h"

int main()
{
	system("color 0f");
    MySQL* m=new MySQL();
	std::cout << "Server Has Started" << std::endl;
	Server MyServer(1111, m); //Create server on port 100 (port 100?)
	for (int i = 0; i < 100; i++) //Up to 100 times...
	{
		MyServer.ListenForNewConnection(); //Accept new connection (if someones trying to connect)
	}
	delete m;
	system("pause");
	return 0;
}