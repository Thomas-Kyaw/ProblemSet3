//
// Created by Aung Khant Kyaw on 2024/10/16.
//

#ifndef PROBLEMSET3_SKILLNODE_H
#define PROBLEMSET3_SKILLNODE_H

#include <iostream>

class SkillNode {
private:
    std::string skillName; // Name of the Skill
    int skillLevel; // Skill level
    SkillNode* previousSkill; // Pointer to the previous Skill
    SkillNode* nextSkill; // Pointer to the next skill
public:
    // Constructor for SkillNode
    SkillNode(std::string _skillName, int _skillLevel);
    // Destructor for SkillNode
    ~SkillNode();

    // Getters
    std::string getSkillName();

    int getSkillLevel();

    SkillNode* getPreviousSkill();

    SkillNode* getNextSkill();

    // Mutators
    void setSkillName(std::string name);

    void setSkillLevel(int level);

    void setNextSkill(SkillNode* node);

    void setPreviousSkill(SkillNode* node);
};


#endif //PROBLEMSET3_SKILLNODE_H
