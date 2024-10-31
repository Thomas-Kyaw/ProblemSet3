//
// Created by Aung Khant Kyaw on 2024/10/16.
//

#ifndef PROBLEMSET3_SKILLLIST_H
#define PROBLEMSET3_SKILLLIST_H

#include "SkillNode.h"
#include <iostream>

class SkillList {
private:
    SkillNode* head;  // Pointer to the first node in the list

public:
    // Constructor and Destructor
    SkillList();
    ~SkillList();

    // List management functions
    void AddSkill(const std::string& name, int level = 1); // Add skill to the end of the list
    void RemoveSkill(const std::string& name);             // Remove skill by name
    SkillNode* FindSkill(const std::string& name) const;         // Find skill by name
    void ModifySkill(const std::string& name, int newLevel); // Modify skill's level
    void ReadSkills() const;
    bool SkillCheck(const std::string& skillName, int requiredLevel) const; // Skill check function
    bool HasSkills() const;                                // Check if the list has any skills
};

#endif //PROBLEMSET3_SKILLLIST_H
