#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib,"ws2_32.lib") //Required for WinSock
#include <string> //For std::string
#include <iostream> //For std::cout, std::endl
#include <WinSock2.h> //For win sockets
#include "encryption.h"
#include "database.h"
#include "FileTransferData.h"
#include "PacketManager.h"
#include "PacketStructs.h"
#include <Windows.h>
#include <vector> //for std::vector
class Connection
{
private:
	AESEncryption* cipher;
	std::string username;
public:
	Connection(SOCKET socket_)
	{
		socket = socket_;
		ActiveConnection = true; //Default to active connection 
	}
	void logIn(std::string username, std::string password);
	bool loggedIn;
	bool ActiveConnection; //True if connection is active, false if inactive(due to a disconnect)
	SOCKET socket;
	//file transfer data
	FileTransferData file; //Object that contains information about our file that is being sent to the client from this server
	PacketManager pm; //Packet Manager for outgoing data for this connection
	void decode(std::string message);
	void encode(std::string message);
	void logOut();
	~Connection();
	
};

class Server
{
public:
	Server(int PORT, MySQL* sql, bool BroadcastPublically = false);
	bool ListenForNewConnection();

private:

	MySQL* sql;

	bool sendall(int ID, char * data, int totalbytes);
	bool recvall(int ID, char * data, int totalbytes);

	bool Getint32_t(int ID, int32_t & _int32_t);
	bool GetPacketType(int ID, PacketType & _packettype);

	void SendString(int ID, std::string & _string);
	bool GetString(int ID, std::string & _string);

	bool ProcessPacket(int ID, PacketType _packettype);
	bool HandleSendFile(int ID);

	static void ClientHandlerThread(int ID);
	static void PacketSenderThread();

	void DisconnectClient(int ID); //Called to properly disconnect and clean up a client (if possible)
private:
	std::vector<std::shared_ptr<Connection>> connections;
	std::mutex connectionMgr_mutex; //mutex for managing connections (used when a client disconnects)
	int UnusedConnections = 0; //# of Inactive Connection Objects that can be reused

	SOCKADDR_IN addr; //Address that we will bind our listening socket to
	int addrlen = sizeof(addr);
	SOCKET sListen;
};

static Server * serverptr; //Serverptr is necessary so the static ClientHandler method can access the server instance/functions.
