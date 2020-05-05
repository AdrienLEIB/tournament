	#pragma once
	#include <iostream>
	#include <ostream>
	#include <vector>
	#include <string>
	using namespace std;

	class Warrior
	{
		int _hp;
		int _hpbase;
		int _damage;
		int _damageInitial;
		int _tourAttack;
		int _tourDefense;
		int _powerDefense;
		string _role;
		vector<string> _atout;
		vector<string> _weapon;




	public:
		Warrior(int hp, int damage, std::string weapon)
		{
			_hp = hp;
			_hpbase = hp;
			_damage = 0;
			_weapon.push_back(weapon);
			_tourDefense = 1;
			_tourAttack = 1;
		}

		Warrior(int hp, int damage, std::string weapon, std::string role)
		{
			_hp = hp;
			_hpbase = hp;
			_damage = 0;
			_weapon.push_back(weapon);
			_atout.push_back(role);
			_tourDefense = 1;
			_tourAttack = 1;
		}

		int HitPoints() const
		{
			return _hp;
		}




		bool veteranVerif() {
			for (int i = 0; i < _atout.size(); i++)
			{
				if (_atout[i] == "Veteran")
				{
					return true;
				}
			}
			return false;
		}
		bool vinciousVerif() {
			for (int i = 0; i < _atout.size(); i++)
			{
				if (_atout[i] == "Vicious") 
				{
					_atout[i] = "Vicious2";
					return true;
				}
				if (_atout[i] == "Vicious2") {
					_atout[i].clear();
					return true;
				}
			}
			return false;
		}

		bool greatSwordVerif() {
			for (int i = 0; i < _weapon.size(); i++)
			{
				if (_weapon[i] == "Great Sword") {
					return true;
				}
			}
			return false;
		}
		bool axeVerif() {
			for (int i = 0; i < _weapon.size(); i++)
			{
				if (_weapon[i] == "axe") {
					return true;
				}
			}
			return false;
		}
		bool bulkerVerif() {
			for (int i = 0; i < _atout.size(); i++)
			{
				if (_atout[i] == "bulker") {
					return true;
				}
			}
			return false;
		}
		bool armorVerif() {
			for (int i = 0; i < _atout.size(); i++)
			{
				if (_atout[i] == "armor") {
					return true;
				}
			}
			return false;
		}

		int armorEffect(int damage) {
			damage -= 1;
			return damage;
		}
		int armorOpponentEffect(int damage) {
			damage -= 3;
			return damage;
		}
		int viciousOpponentEffect(int damage) {
			damage += 20;
			return damage;
		}
		int veteranOpponentEffect(int damage) {
			damage = damage * 2;
			return damage;
		}

		int trueDamage(int damage, Warrior &opponent) {

			damage = opponent.WeaponDamage(damage);
			if (armorVerif() == true) {
				damage = armorOpponentEffect(damage);
			}

			if (opponent.armorVerif() == true) {
				damage = armorEffect(damage);
			}

			if (opponent.vinciousVerif() == true) {
				damage = viciousOpponentEffect(damage);
			}
			if (opponent.veteranVerif() == true) {
				if (opponent._hp <= opponent._hpbase*0.3) {
					damage = veteranOpponentEffect(damage);
				}
			}

			return damage;
		}

		void takeDamage(Warrior &opponent, int damage) {

			damage = trueDamage(damage, opponent);

			if (opponent.greatSwordVerif() == true) {

				if (opponent._tourAttack % 3 != 0) {

					if (bulkerVerif() == true && _powerDefense > 0) {
						if (_tourDefense % 2 == 1) {
							if (opponent.axeVerif() == true) {
								_powerDefense -= 1;
							}
						}
						else {
							_hp -= std::min(_hp, damage);


						}
						
						_tourDefense += 1;
						//cout << "Ta defense a bouge :" << _tourDefense << " : " << opponent._tourAttack << endl;
					}
					else {

						_hp -= std::min(_hp, damage);

					}
					
				}

				opponent._tourAttack += 1;
					//cout << "L'opposant ne peut pas attaquer par conséquent ta defense n'est pas censé bouger " << _tourDefense << " : " << opponent._tourAttack <<  endl;
			
			}
			else {
				if (bulkerVerif() == true && _powerDefense > 0) {
					if (_tourDefense % 2 == 1) {
						if (opponent.axeVerif() == true) {
							_powerDefense -= 1;
						}
					}
					else {
						_hp -= std::min(_hp, damage);

					}
				}
				else {

					_hp -= std::min(_hp, damage);

				}
				_tourDefense += 1;
				opponent._tourAttack += 1;
			}
			
		}

		void Engage(Warrior &opponent)
		{
			Warrior *t = this;

			while (HitPoints() > 0 && opponent.HitPoints() > 0)
			{

				opponent.takeDamage(*t, _damage);
				if (opponent.HitPoints() <= 0)
					break;



				takeDamage(opponent, opponent._damage);

			}
		}

		int WeaponDamage(int damage) {
			for (int i = 0; i < _weapon.size(); i++)
			{
				if (_weapon[i] == "axe") {
					damage = damage + 6;
				}
				if (_weapon[i] == "sword") {
					damage = damage + 5;
				}
				if (_weapon[i] == "Great Sword") {
					damage = damage + 12;
				}
			}
			return damage;
		}

		void Equip(std::string equipement) {
			if (equipement == "buckler") {
				_atout.push_back("bulker");
				_powerDefense = 3;
			}
			if (equipement == "armor") {
				_atout.push_back("armor");
				//_damage -= 1;

			}
			if (equipement == "axe") {
				_weapon.clear();
				_weapon.push_back("axe");

			}
			if (equipement == "sword") {
				_weapon.clear();
				_weapon.push_back("axe");
			}
			if (equipement == "Great Sword") {
				_weapon.clear();
				_weapon.push_back("Great Sword");
			}

		}
	};