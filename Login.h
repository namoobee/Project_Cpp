#pragma once
#include <string>
#include <fstream>

using namespace std;

class Login
{
private:
	string id, password;
	
public:

	Login(string id, string password);

	bool login(string id, string password);
	void save(string ID, string PW);
	bool load(string id, string password);
	void delete_character(string id, string password);
};