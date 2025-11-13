#include "dungeon_crawler_game.h"

DungeonCrawlerGame::DungeonCrawlerGame(const string& name) : 
    rng(time(nullptr)), 
    playerName(name), 
    strength(0), 
    magic(0), 
    health(100), 
    maxHealth(100),
    level(1),
    gold(50) {}

void DungeonCrawlerGame::displayWelcome() {
    cout << "\n### WELCOME TO DUNGEON CRAWLER, " << playerName << "! ###" << endl;
    cout << "===============================================" << endl;
    cout << "### Prepare to explore dangerous dungeons!" << endl;
    cout << "### Battle monsters and collect treasure!" << endl;
    cout << "### Your choices will determine your fate!" << endl;
    cout << "===============================================" << endl << endl;
}

void DungeonCrawlerGame::chooseClass() {
    cout << "### Choose Your Character Class ###" << endl;
    cout << "==================================" << endl;
    cout << "1. ### Warrior   - High strength, low magic" << endl;
    cout << "2. ### Mage      - High magic, low strength" << endl;
    cout << "3. ### Paladin   - Balanced strength and magic" << endl;
    cout << "4. ### Ranger    - Medium strength, medium magic" << endl;
    cout << "Enter your choice (1-4): ";
    
    int classChoice;
    cin >> classChoice;
    
    switch (classChoice) {
        case 1:
            characterClass = "Warrior";
            strength = 15;
            magic = 5;
            cout << "\n### You chose Warrior! Masters of combat and strength!" << endl;
            break;
        case 2:
            characterClass = "Mage";
            strength = 5;
            magic = 15;
            cout << "\n### You chose Mage! Wielders of powerful magic!" << endl;
            break;
        case 3:
            characterClass = "Paladin";
            strength = 10;
            magic = 10;
            cout << "\n### You chose Paladin! Holy warriors with balanced abilities!" << endl;
            break;
        case 4:
            characterClass = "Ranger";
            strength = 8;
            magic = 7;
            cout << "\n### You chose Ranger! Swift and versatile adventurers!" << endl;
            break;
        default:
            characterClass = "Warrior";
            strength = 15;
            magic = 5;
            cout << "\n### Invalid choice! Defaulting to Warrior!" << endl;
            break;
    }
    cout << "Base Stats - Strength: " << strength << ", Magic: " << magic << endl;
}

void DungeonCrawlerGame::chooseWeapon() {
    cout << "\n### Choose Your Starting Weapon ###" << endl;
    cout << "===================================" << endl;
    
    if (characterClass == "Warrior") {
        cout << "1. ### Iron Sword    (+3 Strength)" << endl;
        cout << "2. ### War Hammer    (+4 Strength, -1 Magic)" << endl;
        cout << "3. ### Sword & Shield (+2 Strength, +1 Health)" << endl;
    }
    else if (characterClass == "Mage") {
        cout << "1. ### Crystal Staff  (+3 Magic)" << endl;
        cout << "2. ### Spell Tome    (+4 Magic, -1 Strength)" << endl;
        cout << "3. ### Lightning Wand (+2 Magic, +1 Health)" << endl;
    }
    else if (characterClass == "Paladin") {
        cout << "1. ### Holy Blade    (+2 Strength, +1 Magic)" << endl;
        cout << "2. ### Divine Mace   (+2 Strength, +2 Magic)" << endl;
        cout << "3. ### Sacred Shield (+1 Strength, +1 Magic, +2 Health)" << endl;
    }
    else { // Ranger
        cout << "1. ### Elven Bow     (+2 Strength, +1 Magic)" << endl;
        cout << "2. ### Twin Blades   (+3 Strength)" << endl;
        cout << "3. ### Crossbow      (+2 Strength, +1 Health)" << endl;
    }
    cout << "Enter your choice (1-3): ";
    
    int weaponChoice;
    cin >> weaponChoice;
    
    if (characterClass == "Warrior") {
        switch (weaponChoice) {
            case 1: weapon = "Iron Sword"; strength += 3; break;
            case 2: weapon = "War Hammer"; strength += 4; magic -= 1; break;
            case 3: weapon = "Sword & Shield"; strength += 2; health += 10; maxHealth += 10; break;
            default: weapon = "Iron Sword"; strength += 3; break;
        }
    }
    else if (characterClass == "Mage") {
        switch (weaponChoice) {
            case 1: weapon = "Crystal Staff"; magic += 3; break;
            case 2: weapon = "Spell Tome"; magic += 4; strength -= 1; break;
            case 3: weapon = "Lightning Wand"; magic += 2; health += 10; maxHealth += 10; break;
            default: weapon = "Crystal Staff"; magic += 3; break;
        }
    }
    else if (characterClass == "Paladin") {
        switch (weaponChoice) {
            case 1: weapon = "Holy Blade"; strength += 2; magic += 1; break;
            case 2: weapon = "Divine Mace"; strength += 2; magic += 2; break;
            case 3: weapon = "Sacred Shield"; strength += 1; magic += 1; health += 20; maxHealth += 20; break;
            default: weapon = "Holy Blade"; strength += 2; magic += 1; break;
        }
    }
    else { // Ranger
        switch (weaponChoice) {
            case 1: weapon = "Elven Bow"; strength += 2; magic += 1; break;
            case 2: weapon = "Twin Blades"; strength += 3; break;
            case 3: weapon = "Crossbow"; strength += 2; health += 10; maxHealth += 10; break;
            default: weapon = "Elven Bow"; strength += 2; magic += 1; break;
        }
    }
    
    cout << "\n### You equipped: " << weapon << "!" << endl;
    cout << "Updated Stats - Strength: " << strength << ", Magic: " << magic << ", Health: " << health << endl;
}

void DungeonCrawlerGame::allocateStatPoints() {
    const int totalPoints = 10;
    int remainingPoints = totalPoints;
    
    cout << "\n### Allocate Bonus Stat Points ###" << endl;
    cout << "==================================" << endl;
    cout << "You have " << totalPoints << " bonus points to distribute!" << endl;
    cout << "Current Stats - Strength: " << strength << ", Magic: " << magic << endl;
    
    while (remainingPoints > 0) {
        cout << "\nRemaining points: " << remainingPoints << endl;
        cout << "1. Add to Strength (current: " << strength << ")" << endl;
        cout << "2. Add to Magic (current: " << magic << ")" << endl;
        cout << "3. Finish allocation" << endl;
        cout << "Choose where to add a point: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                if (remainingPoints > 0) {
                    strength++;
                    remainingPoints--;
                    cout << "### Added 1 point to Strength! (Now: " << strength << ")" << endl;
                }
                break;
            case 2:
                if (remainingPoints > 0) {
                    magic++;
                    remainingPoints--;
                    cout << "### Added 1 point to Magic! (Now: " << magic << ")" << endl;
                }
                break;
            case 3:
                cout << "Finishing with " << remainingPoints << " unused points." << endl;
                remainingPoints = 0;
                break;
            default:
                cout << "### Invalid choice!" << endl;
                break;
        }
    }
    
    cout << "\n### Stat Allocation Complete! ###" << endl;
}

void DungeonCrawlerGame::displayCharacterSheet() {
    cout << "\n############################################" << endl;
    cout << "###        CHARACTER SHEET               ###" << endl;
    cout << "############################################" << endl;
    cout << "### Name: " << playerName << endl;
    cout << "### Class: " << characterClass << endl;
    cout << "### Weapon: " << weapon << endl;
    cout << "### Strength: " << strength << endl;
    cout << "### Magic: " << magic << endl;
    cout << "### Health: " << health << "/" << maxHealth << endl;
    cout << "### Level: " << level << endl;
    cout << "### Gold: " << gold << endl;
    cout << "############################################" << endl;
    
    cout << "\n### " << playerName << " the " << characterClass << " is ready for adventure!" << endl;
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

void DungeonCrawlerGame::run() {
    displayWelcome();
    chooseClass();
    chooseWeapon();
    allocateStatPoints();
    displayCharacterSheet();
    
    // --- Level 1: Entrance to the Cave of Evil ---
    cout << "\n### LEVEL 1: CAVE ENTRANCE ###" << endl;
    cout << "You find yourself at the entrance of the Cave of Evil." << endl;
    cout << "A strange compulsion tugs at your chest, urging you inside." << endl;
    cout << "You step into the cave; it's pitch dark. What do you do next?" << endl << endl;

    // ASCII art: skull-like cave entrance
    cout << R"(
               .-''''-.
             .'  .--.  '.
            /   ;    \   ;   -.
           ;   ;      -   \     ;
      ;   ;   ;  .--.  ;   ;  |
        | |   | ;    ; |   |
       .--|   | ;     ;|   |;--.
    - ;   ;   ;        ;   ;     ;

      The dark endtrance to the Cave of Evil stares at you ...
    )" << endl;

    cout << "1. Light a torch and proceed carefully." << endl;
    cout << "2. Charge into the darkness with your weapon drawn." << endl;
    cout << "3. Shout to see what answers the echo." << endl;
    cout << "4. Retreat to town (end adventure for now)." << endl;
    cout << "Enter your choice (1-4): ";
    
    // Read a line so mixing previous cin doesn't break input
    string line;
    getline(cin, line); // consume leftover newline
    int choice = 0;
    while (true) {
        if (!getline(cin, line)) return; // EOF safety
        if (line.empty()) {
            cout << "Please enter 1-4: ";
            continue;
        }
        try {
            choice = stoi(line);
            if (choice >= 1 && choice <= 4) break;
        } catch (...) {}
        cout << "Invalid input. Enter 1-4: ";
    }
    
    // Random helper
    uniform_int_distribution<int> smallRand(1, 6);
    
    switch (choice) {
        case 1: { // Light torch
            cout << "\nYou light a torch and step forward, the tunnel reveals uneven stones and old markings." << endl;
            int foundGold = 5 + smallRand(rng); // 6-11 gold
            gold += foundGold;
            cout << "Hidden in a crack you find a small pouch containing " << foundGold << " gold!" << endl;
            cout << "You proceed safely deeper, senses alert." << endl;
            break;
        }
        case 2: { // Charge in
            cout << "\nYou charge into the dark, sword raised. Something latches onto your leg!" << endl;
            int damage = smallRand(rng) + (level / 1); // small damage
            health -= damage;
            cout << "You struggle free but take " << damage << " damage. (Health: " << max(0, health) << "/" << maxHealth << ")" << endl;
            if (health <= 0) {
                cout << "\nYou succumb to your wounds in the darkness. GAME OVER." << endl;
                cout << "Press Enter to return to main menu...";
                cin.get();
                return;
            }
            cout << "Bruised but alive, you press on." << endl;
            break;
        }
        case 3: { // Shout
            cout << "\nYou let out a shout and the cave answers with a chorus of clicks and a distant scuttling." << endl;
            int reaction = smallRand(rng);
            if (reaction >= 5) {
                cout << "The noise draws a scavenger creature, but it startsle-runs and drops an old amulet." << endl;
                cout << "You pick up the amulet (+1 Magic)." << endl;
                magic += 1;
            } else {
                cout << "The echo wakes a nest of bats that graze you as they pass." << endl;
                int damage = 1 + smallRand(rng) % 2;
                health -= damage;
                cout << "You take " << damage << " damage. (Health: " << max(0, health) << "/" << maxHealth << ")" << endl;
                if (health <= 0) {
                    cout << "\nYou fall in the dark. GAME OVER." << endl;
                    cout << "Press Enter to return to main menu...";
                    cin.get();
                    return;
                }
            }
            break;
        }
        case 4: { // Retreat
            cout << "\nYou decide discretion is the better part of valor and return to town for now." << endl;
            cout << "Level 1 aborted. Press Enter to return to main menu...";
            cin.get();
            return;
        }
        default:
            break;
    }
    
    // Level complete - advance
    level++;
    cout << "\n### LEVEL 1 COMPLETE! ###" << endl;
    cout << "You survived the cave entrance and are ready for the next challenge." << endl;
    cout << "Current Stats - Health: " << health << "/" << maxHealth << ", Strength: " << strength << ", Magic: " << magic << ", Gold: " << gold << endl;
    cout << "Advancing to Level " << level << "..." << endl;
    cout << "Press Enter to continue to the next phase...";
    cin.get();
    
    // Next phase placeholder (actual exploration/encounters to be implemented)
    cout << "\n(Next phase not implemented yet — dungeon exploration coming soon.)" << endl;
    cout << "Press Enter to return to main menu...";
    cin.get();
}