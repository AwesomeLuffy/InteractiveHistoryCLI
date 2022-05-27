#pragma once
#include <string>
class Character {
public:
	Character();
	Character(std::string name, std::string weaponName, int weaponDamage);
	Character(std::string name);
	int getHP();
	std::string getName();
	void setDamage(int amount);
	void setWeapon(std::string weaponName, int weaponDamage);
	std::string getWeapon();
	void attack(Character &cible);
	void healHP();
	bool isAlive() const;
private:
	int m_life;
	std::string m_name;
	std::string m_weaponName;
	int m_weaponDamage;
};

