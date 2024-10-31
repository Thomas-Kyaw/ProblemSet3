#include <iostream>
#include <limits> // For input validation
#include "Character.h"

// Function to handle the robber encounter and skill checks
void RobberEncounter(Character& thePlayer) {
    int choice = 0;

    // Present the scenario
    std::cout << "\nA robber demands you hand over your money and your life!" << std::endl;
    std::cout << "What do you want to do?\n";
    std::cout << "1. Give him your money.\n";
    std::cout << "2. Intimidate him. (Requires 'Intimidation Skill' at level 3)\n";
    std::cout << "3. Persuade him. (Requires 'Persuasion Skill' at level 5)\n";
    std::cout << "4. Fight him.\n";
    std::cout << "Enter your choice: ";

    // Input validation for the choice
    while (!(std::cin >> choice) || (choice < 1 || choice > 4)) {
        std::cout << "Invalid input. Please enter a valid number (1-4): ";
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input
    }

    // Process the player's choice
    switch (choice) {
        case 1:
            std::cout << "You gave the robber your money. The game ends.\n";
            break;
        case 2:
            // Skill check for Intimidation (level 3)
            if (thePlayer.SkillCheck("Intimidation", 3)) {
                std::cout << "You successfully intimidate the robber! He runs away.\n";
            } else {
                std::cout << "Your intimidation fails. The robber isn't scared.\n";
                std::cout << "*Fight* (or the game ends).\n";
            }
            break;
        case 3:
            // Skill check for Persuasion (level 5)
            if (thePlayer.SkillCheck("Persuasion", 5)) {
                std::cout << "You successfully persuade the robber. He lets you go.\n";
            } else {
                std::cout << "Your persuasion fails. The robber isn't convinced.\n";
                std::cout << "*Fight* (or the game ends).\n";
            }
            break;
        case 4:
            std::cout << "You choose to fight the robber!\n";
            std::cout << "*Fight sequence begins* (or the game ends).\n";
            break;
        default:
            std::cout << "Invalid choice.\n";
    }
}

// Main menu function to manage skills
void SkillManagement(Character& thePlayer) {
    int choice = 0;
    std::string skillName;
    int skillLevel;

    // Runtime loop for skill management
    while (true) {
        // Display menu options
        std::cout << "\n=== Skill Management ===\n";
        std::cout << "1. Add a Skill\n";
        std::cout << "2. Remove a Skill\n";
        std::cout << "3. Find a Skill\n";
        std::cout << "4. Modify a Skill\n";
        std::cout << "5. Display All Skills\n";
        std::cout << "6. Exit Skill Management\n";
        std::cout << "Enter your choice: ";

        // Input validation for menu choice
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number: ";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input
        }

        // Process the user's choice
        switch (choice) {
            case 1:
                // Add a skill
                std::cout << "Enter skill name to add: ";
                std::cin >> skillName;
                thePlayer.AddSkill(skillName);
                break;

            case 2:
                // Remove a skill
                if (thePlayer.HasSkills()) { // Check if there are skills to remove
                    std::cout << "Enter skill name to remove: ";
                    std::cin >> skillName;
                    thePlayer.RemoveSkill(skillName);
                } else {
                    std::cout << "No skills available to remove.\n";
                }
                break;

            case 3:
                // Find a skill
                std::cout << "Enter skill name to find: ";
                std::cin >> skillName;
                if (thePlayer.SkillCheck(skillName, 1)) {
                    std::cout << "Skill '" << skillName << "' found!" << std::endl;
                } else {
                    std::cout << "Skill '" << skillName << "' not found." << std::endl;
                }
                break;

            case 4:
                // Modify a skill
                if (thePlayer.HasSkills()) { // Check if there are skills to modify
                    std::cout << "Enter skill name to modify: ";
                    std::cin >> skillName;

                    // Input validation for skill level
                    std::cout << "Enter new skill level: ";
                    while (!(std::cin >> skillLevel)) {
                        std::cout << "Invalid input. Please enter a valid number for skill level: ";
                        std::cin.clear(); // Clear the error flag
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input
                    }

                    thePlayer.ModifySkill(skillName, skillLevel);
                } else {
                    std::cout << "No skills available to modify.\n";
                }
                break;

            case 5:
                // Display all skills
                thePlayer.ReadSkills();
                break;

            case 6:
                // Exit the loop
                std::cout << "Exiting skill management.\n";
                return; // End skill management

            default:
                std::cout << "Invalid choice. Please choose a number between 1 and 6.\n";
        }
    }
}

int main() {
    // Create a Character object
    Character thePlayer(1, "thePlayer", 100, 5, 10, 15, 8, 20);

    int mainChoice = 0;

    // Main game loop for skill management and scenarios
    while (true) {
        // Display main menu options
        std::cout << "\n=== Main Menu ===\n";
        std::cout << "1. Manage Skills\n";
        std::cout << "2. Encounter: Robber\n";
        std::cout << "3. Exit Game\n";
        std::cout << "Enter your choice: ";

        // Input validation for menu choice
        while (!(std::cin >> mainChoice)) {
            std::cout << "Invalid input. Please enter a number: ";
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the input
        }

        // Process main menu choice
        switch (mainChoice) {
            case 1:
                // Manage skills
                SkillManagement(thePlayer);
                break;

            case 2:
                // Engage in a scenario (Robber encounter)
                RobberEncounter(thePlayer);
                break;

            case 3:
                // Exit the game
                std::cout << "Exiting the game. Goodbye!\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please choose a number between 1 and 3.\n";
        }
    }

    return 0;
}
