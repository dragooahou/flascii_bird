#pragma once
#include <WinSock2.h>
#include <sql.h>


class ScoreBoardRetriever {

private:
	SOCKET sock = INVALID_SOCKET;
	BYTE[] msg = nullptr;
public:
	ScoreBoardRetriever();
	BYTE[] Request();
	int Send(int score, string name);
	~ScoreBoardRetriever();

};
