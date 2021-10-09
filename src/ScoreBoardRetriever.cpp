#include <WinSock2.h>
#include <stdio.h>
#include "ScoreBoardRetriever.h"

ScoreBoardRetriever::ScoreBoardRetriever()
{
	WSAData data = { 0 };
	int result = 0;
	result = WSAStartup(MAKEWORD(2, 2), &data);
	if (result) {
		throw std::runtime_error("Could not startup winsock! \n");
	}
	sock = socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP);

}

BYTE[] ScoreBoardRetriever::Request()
{
	return 0;
}

int ScoreBoardRetriever::Send(int score, string name)
{
	return 0;
}

ScoreBoardRetriever::~ScoreBoardRetriever()
{

}


