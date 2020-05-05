#include "pch.h"
#include <iostream>
#include <algorithm>
#include "Swordsman.h"
#include "Viking.h"
#include "Highlander.h"
using namespace std;

/*
 * A Swordsman has 100 hit points and use a 1 hand sword that does 5 dmg
 * A Viking has 120 hit points and use a 1 hand axe that does 6 dmg
 */
static void SwordsmanVsViking()
{
	Swordsman swordsman;
	Viking viking;
	swordsman.Engage(viking);
	cout << "Swordsman (0) =" << swordsman.HitPoints() << endl;
	cout << "Viking (35) =" << viking.HitPoints() << endl;
	cout << endl;
}



/*
 * a buckler cancel all the damages of a blow one time out of two
 * a buckler is destroyed after blocking 3 blow from an axe
 */
static void SwordsmanWithBucklerVsVikingWithBuckler()
{
	Swordsman swordsman;
	swordsman.Equip("buckler");
	Viking viking;
	viking.Equip("buckler");
	swordsman.Engage(viking);
	cout << "SwordsmanWithBuckler (0) = " << swordsman.HitPoints() << endl;
	cout << "VikingWithBuckler (70) = " << viking.HitPoints() << endl;
	cout << endl;
}


/*
 * an Highlander as 150 hit points and fight with a Great Sword
 * a Great Sword is a two handed sword deliver 12 damages, but can attack only 2 every 3 )(attack ; attack ; no attack)
 * an armor : reduce all received damages by 3 & reduce delivered damages by one
 */
static void ArmoredSwordsmanVsHighlander()
{
	Highlander highlander;
	Swordsman swordsman;
	swordsman.Equip("buckler");
	swordsman.Equip("armor");
	swordsman.Engage(highlander);
	cout << "ArmoredSwordsman (0) = " << swordsman.HitPoints() << endl;
	cout << "Highlander (10) = " << highlander.HitPoints() << endl;
	cout << endl;
}


/*
 * a vicious Swordsman is a Swordsman that put poison on his weapon.
 * poison add 20 damages on two first blows
 * a veteran Highlander goes Berserk once his hit points are under 30% of his initial total
 * once Berserk, he doubles his damages
 */

static void ViciousSwordsmanVsVeteranHighlander()
{
	Swordsman swordsman("Vicious"); //
	swordsman.Equip("axe");
	swordsman.Equip("buckler");
	swordsman.Equip("armor");
	Highlander highlander("Veteran");
	swordsman.Engage(highlander);
	cout << "ViciousSwordsman (1) = " << swordsman.HitPoints() << endl;
	cout << "VeteranHighlander (0) = " << highlander.HitPoints() << endl;
	//cout << endl;
}




int main(int argc, char *argv[])
{
	SwordsmanVsViking();
	SwordsmanWithBucklerVsVikingWithBuckler();
	ArmoredSwordsmanVsHighlander();
	ViciousSwordsmanVsVeteranHighlander();
	return 0;
}
















