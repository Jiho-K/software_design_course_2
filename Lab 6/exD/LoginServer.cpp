#include <string>
#include <iostream>
#include  <vector>
#include "LoginServer.hpp"

LoginServer* LoginServer::instance= nullptr;;

LoginServer* LoginServer::getInstance(){
	if(instance == nullptr){
		instance = new LoginServer();
	}
	return instance;
}
	
User* LoginServer::validate(string username, string password){
	//Iterate over all users in vector
	for(vector<User>::iterator u = users.begin(); u != users.end(); u++){
		if(u -> username == username && u ->password == password){
			return &(*u); //defrence then get the adress to return only a pointer to a user
		}
	}
	return nullptr;
}