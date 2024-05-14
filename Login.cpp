#include <iostream>
#include "Login.h"


using namespace std;

Login::Login(string id, string password) 
{
	this->id = id;
	this->password = password;
}

// �α��� 
bool Login::login(string id, string password)
{
	if (Login::load(id, password))
	{
		cout << "�α��� ����" << endl;
		return true;
	}
	else
	{
		cout << "�α��� ����" << endl;
		return false;
	}
}

// ���̵� Ȯ��
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

// ȸ������
void Login::save(string ID, string PW)
{
	ofstream save_file;
	save_file.open("Character.txt");
	if (save_file)
	{
		save_file << ID << endl << PW << endl;
		save_file.close();
	}
	cout << "������ �����Ǿ����ϴ�." << endl;
}
// ���� ����
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
	
	cout << "������ �����Ǿ����ϴ�." << endl;
}