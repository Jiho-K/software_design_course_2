//Client_A.hpp
#ifndef Client_A_H // include guard
#define Client_A_H
#include <iostream>
#include <string>
#include "LoginServer.hpp"
class Client_A{
	private:
	LoginServer* instance;
	
	public:
	Client_A() {
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