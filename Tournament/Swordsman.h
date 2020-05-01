#pragma once

#pragma once
#include <ostream>
#include "Warrior.h"


class Swordsman : public Warrior
{

public:
	Swordsman() : Warrior(100, 5, "sword") {
	}
	//void Swordsman(std::string name) : Warrior(100, 5,name);
	Swordsman(std::string role);
};

Swordsman::Swordsman(std::string role) : Warrior(100, 5, "sword", role) {
};

