//
// Created by Aung Khant Kyaw on 2024/10/16.
//


#include "Character.h"

// Constructor
Character::Character(int id, std::string name, int hp, int level, int strength, int intelligence, int agility, int mana)
        : fEntityID(id), fName(name), fHP(hp), fLevel(level), fXP(0), fStrength(strength), fIntelligence(intelligence),
          fAgility(agility), fMana(mana), fGold(100), fStatusEffect("None") {
}

// Destructor
Character::~Character() {
// Nothing to clean up, SkillList manages its own memory
}

// Accessor implementations
int Character::getEntityID() const { return fEntityID; }
std::string Character::getName() const { return fName; }
int Character::getHP() const { return fHP; }
int Character::getLevel() const { return fLevel; }
int Character::getXP() const { return fXP; }
int Character::getStrength() const { return fStrength; }
int Character::getIntelligence() const { return fIntelligence; }
int Character::getAgility() const { return fAgility; }
int Character::getMana() const { return fMana; }
std::vector<std::string> Character::getInventory() const { return fInventory; }
int Character::getGold() const { return fGold; }
std::string Character::getStatusEffect() const { return fStatusEffect; }


// Mutator implementations
void Character::setEntityID(int id) { fEntityID = id; }
void Character::setName(const std::string& name) { fName = name; }
void Character::setHP(int hp) { fHP = hp; }
void Character::setLevel(int level) { fLevel = level; }
void Character::setXP(int xp) { fXP = xp; }
void Character::setStrength(int strength) { fStrength = strength; }
void Character::setIntelligence(int intelligence) { fIntelligence = intelligence; }
void Character::setAgility(int agility) { fAgility = agility; }
void Character::setMana(int mana) { fMana = mana; }
void Character::addItemToInventory(const std::string& item) { fInventory.push_back(item); }
void Character::setGold(int gold) { fGold = gold; }
void Character::setStatusEffect(const std::string& status) { fStatusEffect = status; }


// Skill management functions (now delegated to SkillList)
void Character::AddSkill(const std::string& name, int level) {
    skills.AddSkill(name, level);
}

void Character::RemoveSkill(const std::string& name) {
    skills.RemoveSkill(name);
}

bool Character::SkillCheck(const std::string& skillName, int requiredLevel) {
    return skills.SkillCheck(skillName, requiredLevel);  // Delegate to SkillList's SkillCheck
}

void Character::ModifySkill(const std::string& name, int newLevel) {
    skills.ModifySkill(name, newLevel);
}

void Character::ReadSkills() const {
    skills.ReadSkills();
}

// Function to check if the character has any skills
bool Character::HasSkills() const {
    return skills.HasSkills();
}
