#ifndef LoginServer_H // include guard
#define LoginServer_H
#include <string>
#include <iostream>
#include  <vector>

using namespace std;
struct User{
	string username;
	string password;
};

class LoginServer{
	private:
	vector<User> users;
	static LoginServer* instance;
	LoginServer(){}
	
	public:
	LoginServer(const LoginServer& src) = delete;
	
	void operator=(const LoginServer& rhs) = delete;
	
	static LoginServer* getInstance();
	
	void add(string username, string password){
		users.push_back({username, password});
	}
	
	User* validate(string username, string password);
};
#endif