//
// Created by Aung Khant Kyaw on 2024/10/16.
//

#ifndef PROBLEMSET3_CHARACTER_H
#define PROBLEMSET3_CHARACTER_H

#include <iostream>
#include <vector>
#include "SkillList.h"  // Include SkillList instead of SkillNode

class Character {
private:
    int fEntityID;
    std::string fName;
    int fHP;
    int fLevel;
    int fXP;
    int fStrength;
    int fIntelligence;
    int fAgility;
    int fMana;
    std::vector<std::string> fInventory;
    int fGold;
    std::string fStatusEffect;

    // Use SkillList to manage the character's skills
    SkillList skills;

public:
    // Constructor
    Character(int id, std::string name, int hp, int level, int strength, int intelligence, int agility, int mana);

    // Destructor
    ~Character();

    // Accessors
    int getEntityID() const;
    std::string getName() const;
    int getHP() const;
    int getLevel() const;
    int getXP() const;
    int getStrength() const;
    int getIntelligence() const;
    int getAgility() const;
    int getMana() const;
    std::vector<std::string> getInventory() const;
    int getGold() const;
    std::string getStatusEffect() const;

    // Mutators
    void setEntityID(int id);
    void setName(const std::string& name);
    void setHP(int hp);
    void setLevel(int level);
    void setXP(int xp);
    void setStrength(int strength);
    void setIntelligence(int intelligence);
    void setAgility(int agility);
    void setMana(int mana);
    void addItemToInventory(const std::string& item);
    void setGold(int gold);
    void setStatusEffect(const std::string& status);

    // Skill Management through SkillList
    void AddSkill(const std::string& name, int level = 1);
    void RemoveSkill(const std::string& name);
    bool SkillCheck(const std::string& skillName, int requiredLevel); // Check skill existence and level
    void ModifySkill(const std::string& name, int newLevel);
    void ReadSkills() const;

    bool HasSkills() const; // Check if the character has any skills
};

#endif //PROBLEMSET3_CHARACTER_H
