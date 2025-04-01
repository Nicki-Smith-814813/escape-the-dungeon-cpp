//*****************************************************
//Author.....: Nicki Smith
//Assignment.: Escape the Dungeon
//Description: A simple text-based adventure game.
//*****************************************************

#include <iostream>
using namespace std;

// Function prototypes
void startGame(string playerName, string weapon);
void pathDecision(int choice, string playerName, string weapon);
void majorDecision(string playerName, string weapon);
void fightMonster(string playerName, string weapon);
bool stealthCheck();

int main() {
    string playerName, weapon;  // Declare variables for player's name and chosen weapon
    int weaponChoice;  // Variable to store the player's weapon choice
    
    // Welcome the player and ask for their character's name
    cout << "Welcome to \"Escape the Dungeon\"!\n";
    cout << "Enter your character's name: ";
    cin >> playerName;  // Take input for the player's name
    
    // Ask the player to choose a weapon
    cout << "Choose your weapon:\n";
    cout << "1. Bow and Dagger\n";
    cout << "2. Longsword\n";
    cout << "Enter your choice (1-2): ";
    cin >> weaponChoice;  // Take input for weapon choice
    
    // Based on the player's choice, assign the weapon
    weapon = (weaponChoice == 1) ? "Bow and Dagger" : "Longsword";  // Ternary operator for assignment
    
    // Start the game by calling the startGame function
    startGame(playerName, weapon);
    
    return 0;  // End of main function
}

// Function to start the game and introduce the player to the dungeon
void startGame(string playerName, string weapon) {
    int choice;  // Variable to store the player's path choice
    
    // Print a welcome message and display the player's weapon choice
    cout << "\nWelcome, " << playerName << "! You have chosen " << weapon << ".\n";
    cout << "You find yourself trapped in a dark dungeon.\n";
    cout << "Your mission is to find a way out.\n\n";
    
    // Provide the player with four possible paths
    cout << "There are four paths ahead of you:\n";
    cout << "1. A narrow passage filled with cobwebs.\n";
    cout << "2. A stairway leading downward.\n";
    cout << "3. A door with strange markings.\n";
    cout << "4. A tunnel with eerie noises.\n";
    cout << "Choose your path (1-4): ";
    cin >> choice;  // Take input for path choice
    
    // Call the pathDecision function to handle the path choice
    pathDecision(choice, playerName, weapon);
}

// Function to handle the player's decision based on the chosen path
void pathDecision(int choice, string playerName, string weapon) {
    if (choice == 1) {
        // If the player chooses path 1, they fall into a pit and lose
        cout << "You carefully navigate through the passage but fall into a hidden pit. Game Over!\n";
    } else if (choice == 2) {
        // If the player chooses path 2, they find a chest and proceed to a major decision
        cout << "You descend the stairs and find a mysterious chest.\n";
        majorDecision(playerName, weapon);  // Call the majorDecision function
    } else if (choice == 3) {
        // If the player chooses path 3, they are locked in and lose
        cout << "The door is locked. You hear footsteps approaching. Game Over!\n";
    } else if (choice == 4) {
        // If the player chooses path 4, they encounter a monster and must decide
        int fightChoice;  // Variable to store player's decision to fight or escape
        cout << "The tunnel leads to a monster's lair. A fearsome beast stands before you!\n";
        cout << "1. Fight the monster\n";
        cout << "2. Try to escape\n";
        cout << "Choose your action (1-2): ";
        cin >> fightChoice;  // Take input for fight or escape decision
        
        if (fightChoice == 1) {
            // If the player chooses to fight, call the fightMonster function
            fightMonster(playerName, weapon);
        } else {
            // If the player chooses to escape, they are caught and lose
            cout << "You attempt to escape, but the monster catches you. Game Over!\n";
        }
    } else {
        // If the player inputs an invalid choice, restart the game
        cout << "Invalid choice. Try again.\n";
        startGame(playerName, weapon);  // Recursively call startGame for a new attempt
    }
}

// Function to handle the fight against the monster
void fightMonster(string playerName, string weapon) {
    if (weapon == "Longsword") {
        // If the player has a longsword, they can easily defeat the monster
        cout << playerName << " bravely fights the monster using " << weapon << "!\n";
        cout << "With powerful swings, you slay the monster and find a hidden exit! You escaped! Congratulations!\n";
    } else if (weapon == "Bow and Dagger") {
        // If the player has a Bow and Dagger, they must attempt a stealth check
        bool stealth = stealthCheck();  // Call the stealthCheck function to determine success or failure
        
        if (stealth) {
            // If stealth check is successful, they can defeat the monster from a distance using the bow
            cout << playerName << " successfully sneaks up on the monster and uses the bow to defeat it from a distance.\n";
            cout << "You escaped! Congratulations!\n";
        } else {
            // If stealth check fails, the player fights the monster with the dagger
            cout << playerName << " failed the stealth check. You must fight the monster with your dagger.\n";
            cout << "After a fierce battle, you defeat the monster with the dagger. You escaped! Congratulations!\n";
        }
    } else {
        // If the player has an unknown weapon, they lose the fight
        cout << "You fight valiantly, but the monster overpowers you. Game Over!\n";
    }
}

// Function to simulate the stealth check (using a dice roll)
bool stealthCheck() {
    int roll = rand() % 20 + 1;  // Generate a random number between 1 and 20 to simulate a dice roll
    cout << "You attempt to sneak past the monster...\n";
    cout << "Rolling for stealth... You rolled a " << roll << "!\n";
    return roll >= 15;  // If the roll is 15 or higher, the stealth check is successful (75% chance)
}

// Function to handle the decision after finding the mysterious chest
void majorDecision(string playerName, string weapon) {
    int decision;  // Variable to store the player's decision for the chest
    
    cout << "You have found a mysterious chest.\n";
    cout << "What do you want to do?\n";
    cout << "1. Open the chest.\n";
    cout << "2. Ignore the chest and keep moving.\n";
    cout << "3. Go back to the starting point.\n";
    cout << "Choose your action (1-3): ";
    cin >> decision;  // Take input for the decision
    
    // Use a switch statement to handle different decisions
    switch (decision) {
        case 1:
            // If the player opens the chest, they find a key and escape
            cout << "The chest contains a key! You use it to unlock a hidden exit. You escaped! Congratulations, " << playerName << "!\n";
            break;
        case 2:
            // If the player ignores the chest, they get lost in the dungeon and lose
            cout << "You move forward but get lost in the dungeon. Game Over!\n";
            break;
        case 3:
            // If the player returns to the starting point, restart the game
            cout << "You return to the starting point.\n";
            startGame(playerName, weapon);  // Recursively call startGame for a new attempt
            break;
        default:
            // If the player enters an invalid choice, prompt them again
            cout << "Invalid choice. Try again.\n";
            majorDecision(playerName, weapon);  // Recursively call majorDecision for a new attempt
    }
}
