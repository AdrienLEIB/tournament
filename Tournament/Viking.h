#pragma once
#include <ostream>
#include "Warrior.h"


class Viking : public Warrior
{
public:
	Viking() : Warrior(120, 6, "axe") {}
};
