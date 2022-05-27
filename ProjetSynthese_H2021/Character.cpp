#include "Character.h"

Character::Character() : m_life(100), m_name(""), m_weaponDamage(-1), m_weaponName("") {}

Character::Character(std::string name, std::string weaponName, int weaponDamage) {
	m_life = 100;
	m_name = name;
	m_weaponName = weaponName;
	m_weaponDamage = weaponDamage;	
}

Character::Character(std::string name) : m_name(""), m_weaponDamage(-1), m_weaponName("") {
	m_life = 100;
	m_name = name;
}

int Character::getHP() { return m_life; }

std::string Character::getName() {
	return m_name;
}

void Character::setDamage(int amount) { 
	m_life -= amount;
	(m_life < 0) ? m_life = 0 : m_life = m_life;
}

void Character::setWeapon(std::string weaponName, int weaponDamage) {
	m_weaponName = weaponName;
	m_weaponDamage = weaponDamage;
}

std::string Character::getWeapon() { return m_weaponName; }

void Character::attack(Character &cible) {
	cible.setDamage(m_weaponDamage);
}

void Character::healHP() {
	m_life = 100;
}

bool Character::isAlive() const {
	return m_life > 0;
}
