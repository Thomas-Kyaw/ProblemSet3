//
// Created by Aung Khant Kyaw on 2024/10/16.
//

#include "SkillList.h"

// Constructor
SkillList::SkillList() : head(nullptr) {}

// Destructor
SkillList::~SkillList() {
    // Delete all nodes in the list
    SkillNode* current = head;
    while (current != nullptr) {
        SkillNode* toDelete = current;
        current = current->getNextSkill();
        delete toDelete;
    }
}

// Check if the list has any skills
bool SkillList::HasSkills() const {
    return head != nullptr;
}

// Add a new skill to the list
void SkillList::AddSkill(const std::string& name, int level) {
    SkillNode* newSkill = new SkillNode(name, level);

    if (head == nullptr) {
        // List is empty, new skill becomes the head
        head = newSkill;
    } else {
        // Append skill to the end of the list
        SkillNode* current = head;
        while (current->getNextSkill() != nullptr) {
            current = current->getNextSkill();
        }
        current->setNextSkill(newSkill);
        newSkill->setPreviousSkill(current);
    }

    std::cout << "You have learned a new skill: " << name << std::endl;
}

// Find a skill by name
SkillNode* SkillList::FindSkill(const std::string& name) const {
    SkillNode* current = head;
    while (current != nullptr) {
        if (current->getSkillName() == name) {
            return current;
        }
        current = current->getNextSkill();
    }
    return nullptr; // Skill not found
}

// Remove a skill by name
void SkillList::RemoveSkill(const std::string& name) {
    SkillNode* toRemove = FindSkill(name);
    if (toRemove == nullptr) {
        std::cout << "Skill not found: " << name << std::endl;
        return;
    }

    if (toRemove == head) {
        head = toRemove->getNextSkill(); // If removing the head, move head forward
        if (head != nullptr) {
            head->setPreviousSkill(nullptr);
        }
    } else {
        // Reconnect previous and next nodes
        if (toRemove->getPreviousSkill() != nullptr) {
            toRemove->getPreviousSkill()->setNextSkill(toRemove->getNextSkill());
        }
        if (toRemove->getNextSkill() != nullptr) {
            toRemove->getNextSkill()->setPreviousSkill(toRemove->getPreviousSkill());
        }
    }

    delete toRemove; // Free memory
    std::cout << "You forgot the skill: " << name << std::endl;
}

// Modify a skill's level
void SkillList::ModifySkill(const std::string& name, int newLevel) {
    SkillNode* skill = FindSkill(name);
    if (skill == nullptr) {
        std::cout << "Skill not found: " << name << std::endl;
        return;
    }
    skill->setSkillLevel(newLevel);
    std::cout << "You have modified the skill: " << name << " to level " << newLevel << std::endl;
}

// Display all skills in the list
void SkillList::ReadSkills() const {
    SkillNode* current = head;
    if (current == nullptr) {
        std::cout << "No skills learned yet." << std::endl;
        return;
    }

    std::cout << "Skills: " << std::endl;
    while (current != nullptr) {
        std::cout << " - " << current->getSkillName() << " (Level " << current->getSkillLevel() << ")" << std::endl;
        current = current->getNextSkill();
    }
}

bool SkillList::SkillCheck(const std::string& skillName, int requiredLevel) const {
    SkillNode* skill = FindSkill(skillName);  // Reuse FindSkill to locate the skill
    if (skill == nullptr) {
        std::cout << "You do not have the skill: " << skillName << std::endl;
        return false;
    } else if (skill->getSkillLevel() < requiredLevel) {
        std::cout << "Your skill level in " << skillName << " is too low. Required level: " << requiredLevel << ".\n";
        return false;
    }
    return true;  // Skill exists and level is sufficient
}