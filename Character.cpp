#include <iostream>
#include "Character.h"

using namespace std;

Character::Character(string name, Level level, item item_num)
{
	this->name = name;
	this->level = level;
	this->item_num = item_num;
}

void Character::Char_Info()
{
	cout << "이름: " << name << ", Level: " << static_cast<int>(level) << ", 눈덩이 개수: " << static_cast<int>(item_num) << endl;
}

void Character::Change_Name(string newName)
{
	name = newName;
}

void Character::Level_Up()
{
	if (level == Level::level_3)
	{
		cout << "캐릭터가 최대 Level에 도달하였습니다." << endl;
		return;
	}
	level = static_cast<Level>(static_cast<int>(level) + 1);

}

void Character::Pick_Up_Item()
{
	if (item_num > item::item_5)
	{
		cout << "이미 눈덩이를 5개나 가지고 있습니다." << endl;
		return;
	}
	item_num = static_cast<item>(static_cast<int>(item_num) + 1);
}

void Character::Use_Item()
{
	if (item_num < item::item_1)
	{
		cout << "던질 눈덩이가 하나도 없습니다." << endl;
		return;
	}
	item_num = static_cast<item>(static_cast<int>(item_num) - 1);
}

void Character::Game_Loop()
{
	int choise = 0;
	bool result = false;

	while (true)
	{
		cout << endl;
		cout << "========== 선택하세요 ===========" << endl;
		cout << "|   0. 게임 종료                |" << endl;
		cout << "|   1. 캐릭터의 이름 변경하기   |" << endl;
		cout << "|   2. 눈싸움 하러가기          |" << endl;
		cout << "=================================" << endl;
		cout << "무엇을 할까요?: ";
		cin >> choise;

		string newName;

		switch (choise)
		{
		case 0:
			cout << "게임을 종료합니다." << endl;
			return;
		case 1:
			cout << "새로운 이름을 입력해주세요: ";
			cin >> newName;
			Change_Name(newName);
			cout << "변경완료" << endl;
			break;
		case 2:
			result = true;
			break;
		default:
			cout << "잘못된 선택입니다." << endl;
			break;
		}
		if (result == true) break;
	}
}

/*
		cout << "|   4. Item 사용                |" << endl;
		cout << "|   2. Level Up                 |" << endl;

			cin >> newName;
			Change_Name(newName);
			cout << "변경완료" << endl;
			break;



			case 2:
			Level_Up();
			if (level == Level::level_3)
			{
				break;
			}
			cout << "Level Up!" << endl;
			break;
		case 3:
			Pick_Up_Item();
			cout << "Item이 추가되었습니다." << endl;
			break;
		case 4:
			Use_Item();
			cout << "Item을 사용하였습니다." << endl;
			break;
		case 5:
			cout << "캐릭터의 정보를 확인합니다." << endl;
			Char_Info();
			break;
		default:
			cout << "잘못된 선택입니다." << endl;
			break;
*/
