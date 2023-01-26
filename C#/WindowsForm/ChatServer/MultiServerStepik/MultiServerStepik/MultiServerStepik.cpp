#include <iostream>
#include <WinSock2.h>
#include<WS2tcpip.h>
#include <cstdlib>
#include <string>
#include <map>

#define CHARSIZE 4096

#pragma comment(lib, "ws2_32.lib")

using namespace std;

map <int, string> NameBD;

int Counter = 0;
int UnBlock = 0;


int main() {
	// инициализация WinSock
	WSAData wsData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsData) != 0) {
		cerr << "Error version!";
		exit(1);
	}

	// Создание Сокета
	SOCKET listening = socket(AF_INET, SOCK_STREAM, NULL);
	if (listening == INVALID_SOCKET) {
		cerr << "Invalid socket!";
		exit(1);
	}
	SOCKADDR_IN addr;
	ZeroMemory(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	//addr.sin_addr.S_un.S_addr = inet_pton(AF_INET, "192.168.1.45", &(addr.sin_addr));
	addr.sin_addr.S_un.S_addr = INADDR_ANY;

	// bind
	bind(listening, (SOCKADDR*)&addr, sizeof(addr));

	// listen
	listen(listening, SOMAXCONN);

	fd_set master;

	FD_ZERO(&master);

	FD_SET(listening, &master);

	while (true) {
		fd_set copy = master;

		int socketConnect = select(0, &copy, nullptr, nullptr, nullptr);
		for (int i = 0; i < socketConnect; i++) {
			SOCKET sock = copy.fd_array[i];
			if (sock == listening) {
				// accept a new connection
				SOCKET client = accept(listening, (struct sockaddr*)&addr, nullptr);
				char host[NI_MAXHOST];
				char servce[NI_MAXHOST];

				ZeroMemory(host, NI_MAXHOST);
				ZeroMemory(servce, NI_MAXHOST);

				if (getnameinfo((sockaddr*)&addr, sizeof(addr), host, NI_MAXHOST, servce, NI_MAXHOST, 0) == 0) {
					cout << endl << host << " connected on port " << servce << endl;
				}
				else {
					inet_ntop(AF_INET, &addr.sin_addr, host, NI_MAXHOST);
					cout << endl << host << " connected on port: " << ntohs(addr.sin_port) << endl;
				}

				// add the new connection to the list of clients
				FD_SET(client, &master);

				char* name = new char[CHARSIZE];
				bool BoolName = false;;
				char conn[CHARSIZE] = "\nconnecting...";
				recv(client, name, CHARSIZE, NULL);
				
				if (strlen(name) >= 1) {
					BoolName = true;
					
					name[19] = '\0';
					NameBD[Counter] = name;
					int h = 0, l = strlen(conn);
					
					for (h; h < strlen(name); h++, l++) {
						conn[l] = name[h];
					}
					conn[l] = '\0';
				}
				
				// send a welcome message to connected client
				char welcomeMsg[] = "Welcome to the Char Server;;;S";
				
				send(client, welcomeMsg, strlen(welcomeMsg), NULL);
				for (int i = 0; i < master.fd_count; i++) {
					SOCKET outSock = master.fd_array[i];

					if (outSock != listening && outSock != sock) {
						send(outSock, conn, strlen(conn), 0);
					}
				}
				if (BoolName)
					for (auto c = NameBD.begin(); c != NameBD.end(); c++)
						cout << endl << c->first << " " << c->second << endl;
				
				Counter++;
			}
			else {
				char* buf = new char[CHARSIZE];
				ZeroMemory(buf, CHARSIZE);

				int ByteIn = recv(sock, buf, CHARSIZE, 0);
				if (ByteIn <= 0) {
					char conn[CHARSIZE] = "\ndisconnecting...";
					int h = 0, l = strlen(conn);
					for (int j = 0; j < master.fd_count; j++) {
						SOCKET outSock = master.fd_array[j];

						if (outSock != listening && outSock == sock) {
							//map<int, string>::iterator it = NameBD.find(j-1);
							int h = 0, l = strlen(conn);

							for (h; h < NameBD[j-1].length(); h++, l++) {
								conn[l] = NameBD[j-1][h];
							}
							conn[l] = '\0';
							
							int k;
							for (k = 0; k < Counter-1; k++) {
								NameBD[j - 1 + k] = NameBD[j + k];
							}
							map<int, string>::iterator it = NameBD.find(j - 1 + k);
							NameBD.erase(it);
						}
					}
					for (int i = 0; i < master.fd_count; i++) {
						SOCKET outSock = master.fd_array[i];

						send(outSock, conn, strlen(conn), 0);

					}
					
					closesocket(sock);
					FD_CLR(sock, &master);
					Counter--;
						
				}
				else {
						
					for (int i = 0; i < master.fd_count; i++) {
						SOCKET outSock = master.fd_array[i]; 
						
						send(outSock, buf, strlen(buf), 0);
						
					}
					for (int i = 0; i < strlen(buf); i++) cout << buf[i];
					cout << endl;
				}

			}
		}
	}

	// закрытие WinSock
	WSACleanup();
}	
	