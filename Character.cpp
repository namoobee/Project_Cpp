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
	cout << "�̸�: " << name << ", Level: " << static_cast<int>(level) << ", ������ ����: " << static_cast<int>(item_num) << endl;
}

void Character::Change_Name(string newName)
{
	name = newName;
}

void Character::Level_Up()
{
	if (level == Level::level_3)
	{
		cout << "ĳ���Ͱ� �ִ� Level�� �����Ͽ����ϴ�." << endl;
		return;
	}
	level = static_cast<Level>(static_cast<int>(level) + 1);

}

void Character::Pick_Up_Item()
{
	if (item_num > item::item_5)
	{
		cout << "�̹� �����̸� 5���� ������ �ֽ��ϴ�." << endl;
		return;
	}
	item_num = static_cast<item>(static_cast<int>(item_num) + 1);
}

void Character::Use_Item()
{
	if (item_num < item::item_1)
	{
		cout << "���� �����̰� �ϳ��� �����ϴ�." << endl;
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
		cout << "========== �����ϼ��� ===========" << endl;
		cout << "|   0. ���� ����                |" << endl;
		cout << "|   1. ĳ������ �̸� �����ϱ�   |" << endl;
		cout << "|   2. ���ο� �Ϸ�����          |" << endl;
		cout << "=================================" << endl;
		cout << "������ �ұ��?: ";
		cin >> choise;

		string newName;

		switch (choise)
		{
		case 0:
			cout << "������ �����մϴ�." << endl;
			return;
		case 1:
			cout << "���ο� �̸��� �Է����ּ���: ";
			cin >> newName;
			Change_Name(newName);
			cout << "����Ϸ�" << endl;
			break;
		case 2:
			result = true;
			break;
		default:
			cout << "�߸��� �����Դϴ�." << endl;
			break;
		}
		if (result == true) break;
	}
}

/*
		cout << "|   4. Item ���                |" << endl;
		cout << "|   2. Level Up                 |" << endl;

			cin >> newName;
			Change_Name(newName);
			cout << "����Ϸ�" << endl;
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
			cout << "Item�� �߰��Ǿ����ϴ�." << endl;
			break;
		case 4:
			Use_Item();
			cout << "Item�� ����Ͽ����ϴ�." << endl;
			break;
		case 5:
			cout << "ĳ������ ������ Ȯ���մϴ�." << endl;
			Char_Info();
			break;
		default:
			cout << "�߸��� �����Դϴ�." << endl;
			break;
*/
