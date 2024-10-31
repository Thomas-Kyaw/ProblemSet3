//
// Created by Aung Khant Kyaw on 2024/10/16.
//

#include "SkillNode.h"

// Construtor for SkillNode
SkillNode::SkillNode(std::string _skillName, int _skillLevel) : skillName(_skillName), skillLevel(_skillLevel), previousSkill(
        nullptr), nextSkill(nullptr) {}

SkillNode::~SkillNode(){
    // Destructor Logic
}

// Getters
std::string SkillNode::getSkillName(){
    return skillName;
}

int SkillNode::getSkillLevel(){
    return skillLevel;
}

SkillNode* SkillNode::getPreviousSkill(){
    return previousSkill;
}

SkillNode* SkillNode::getNextSkill(){
    return nextSkill;
}

// Mutators
void SkillNode::setSkillName(std::string name){
    skillName = name;
}

void SkillNode::setSkillLevel(int level){
    skillLevel = level;
}

void SkillNode::setNextSkill(SkillNode* node){
    nextSkill = node;
}

void SkillNode::setPreviousSkill(SkillNode* node){
    previousSkill = node;
}