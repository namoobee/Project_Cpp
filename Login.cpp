#include <iostream>
#include "Login.h"


using namespace std;

Login::Login(string id, string password) 
{
	this->id = id;
	this->password = password;
}

// 로그인 
bool Login::login(string id, string password)
{
	if (Login::load(id, password))
	{
		cout << "로그인 성공" << endl;
		return true;
	}
	else
	{
		cout << "로그인 실패" << endl;
		return false;
	}
}

// 아이디 확인
bool Login::load(string id, string password)
{
	ifstream load_file;
	load_file.open("Character.txt");
	string line;
	bool found = false;

	while (getline(load_file, line))
	{
		if (found)
		{
			password = line;
			break;
		}
		else if (line == id)
		{
			found = true;
		}
	}
	load_file.close();
	return found;
}

// 회원가입
void Login::save(string ID, string PW)
{
	ofstream save_file;
	save_file.open("Character.txt");
	if (save_file)
	{
		save_file << ID << endl << PW << endl;
		save_file.close();
	}
	cout << "계정이 생성되었습니다." << endl;
}
// 계정 삭제
void Login::delete_character(string id, string password)
{
	ifstream load_file;
	load_file.open("Character.txt");
	ofstream new_file;
	new_file.open("New_Character.txt");
	string line;

	while (getline(load_file, line))
	{
			new_file << line << "\n";
	}
	load_file.close();
	new_file.close();

	remove("Character.txt");
	rename("New_Character.txt", "Character.txt");
	
	cout << "계정이 삭제되었습니다." << endl;
}