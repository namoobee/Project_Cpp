#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Login.h"
#include "Character.h"
using namespace std;

int main()
{
	string id, pw;
	string new_id, new_pw;
	string del_id, del_pw;
	int choice = 0;
	Login login(id, pw);
	Login new_login(new_id, new_pw);
	Login del_login(del_id, del_pw);
	bool result = false;
	
	

	while (true)
	{
		cout << "---------------------------------------" << endl;
		cout << "0. 종료\n1. 로그인\n2. 회원가입\n3. 계정 삭제 \n";
		cout << "---------------------------------------" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			return 0;
		case 1:
			cout << "ID : ";
			cin >> id;
			cout << "PW : ";
			cin >> pw;
			result = login.login(id, pw);
			
			break;
		
		case 2:
			cout << "새로만들 ID를 입력해주세요: ";
			cin >> new_id;
			cout << "PW를 입력해주세요: ";
			cin >> new_pw;
			new_login.save(new_id, new_pw);
			break;
		case 3:
			cout << "삭제할 ID를 입력해주세요: ";
			cin >> del_id;
			cout << "PW를 입력해주세요: ";
			cin >> del_pw;
			del_login.delete_character(del_id, del_pw);
			break;

		default:
			cout << "잘못된 선택입니다. \n";		
		}

		if (result == true) break;

	}
	string name;
	cout << "캐릭터 이름을 입력하세요.: ";
	cin >> name;

	Character character(name);
	character.Game_Loop();

	cout << "유독 눈이 많이 내리는 올해 겨울, 철수가 눈덩이를 던저 도발을 합니다." << endl;
	cout << "눈싸움이 시작되었습니다." << endl;
	
	srand(time(NULL));

	int myHP = 7;
	int chulsHP = 5;
	int damage_1, damage_2;
	bool HP;
	int mychoice;

	while (true)
	{
		cout << "-------------------------------" << endl;
		character.Char_Info();
		cout << "나의 HP: " << myHP << " 철수의 HP: " << chulsHP << endl;
		cout << "0. 도망간다.\n1. 눈덩이를 만든다.\n2. 눈덩이를 던진다. \n";
		cout << "나는 어떤선택을 할까?" << endl;
		cin >> mychoice;

		damage_1 = rand() % 3 + 1; // 나
		damage_2 = rand() % 3 + 1; // 철수

		switch (mychoice)
		{
		case 0:
			cout << "철수의 무지막지한 공격에 도망을 선택했습니다." << endl << "당신은 패배자입니다.";
			return 0;
		case 1:
			cout << "눈덩이를 만듭니다." << endl;
			character.Pick_Up_Item();
			break;
		case 2:
			cout << "눈덩이를 던집니다." << endl;
			character.Use_Item();
			break;
		default:
				cout << "올바른 선택이 아닙니다." << endl;
		}
		if (chulsHP <= 0)
		{

		}
	}

	return 0;
}
