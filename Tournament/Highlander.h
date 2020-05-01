#pragma once
#include "Warrior.h"


class Highlander : public Warrior
{
public:
	Highlander() : Warrior(150, 12, "Great Sword") {}
	Highlander(std::string role);
};

Highlander::Highlander(std::string role) : Warrior(150, 12,"Great Sword", role) {
};