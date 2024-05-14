#pragma once
#include <string>
#include <fstream>
#include <vector>

using namespace std;

enum class Level { level_1 = 1, level_2, level_3 };
enum class item {item_1 = 1, item_2, item_3, item_4, item_5 };

class Character
{
private:
	string name;
	Level level;
	item item_num;

public:
	Character(string name = "", Level level = Level::level_1, item item = item::item_1);

	void Char_Info();
	void Change_Name(string newName);
	void Level_Up();
	void Pick_Up_Item();
	void Use_Item();
	void Game_Loop();
};