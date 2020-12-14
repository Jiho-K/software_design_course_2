//Client_B.hpp
#ifndef Client_B_H // include guard
#define Client_B_H
#include <iostream>
#include <string>
#include "LoginServer.hpp"

class Client_B{
	private:
	LoginServer* instance;
	
	public:
	Client_B() {
		instance = LoginServer::getInstance();
	}
	
	void add(string username, string  password){
		instance -> add(username, password);
	}
	
	User* validate(string username, string password){
		return instance -> validate(username, password);
	}
};

#endif 