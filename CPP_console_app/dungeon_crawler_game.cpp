#include "dungeon_crawler_game.h"

DungeonCrawlerGame::DungeonCrawlerGame(const string& name) : 
    rng(static_cast<unsigned int>(time(nullptr))), 
    playerName(name), 
    strength(0), 
    magic(0), 
    health(100), 
    maxHealth(100),
    level(1),
    gold(50),
    armor(0),
    healthPotions(0),
    manaPotions(0),
    hasEyeJewel(false),
    hasSpiralStone(false),
    hasParchmentPiece1(false),
    hasParchmentPiece2(false),
    acceptedGoblinQuest(false),
    completedGoblinQuest(false),
    engagedHoodedFigure(false) {}

void DungeonCrawlerGame::displayWelcome() {
    cout << "\n### WELCOME TO DUNGEON CRAWLER, " << playerName << "! ###" << endl;
    cout << "===============================================" << endl;
    cout << "### Prepare to explore dangerous dungeons!" << endl;
    cout << "### Battle monsters and collect treasure!" << endl;
    cout << "### Your choices will determine your fate!" << endl;
    cout << "===============================================" << endl << endl;
}

void DungeonCrawlerGame::chooseClass() {
    cout << "\n### Choose Your Character Class ###" << endl;
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
    cout << "### Armor: " << armor << endl;
    cout << "### Health Potions: " << healthPotions << endl;
    cout << "### Mana Potions: " << manaPotions << endl;
    cout << "############################################" << endl;
    
    cout << "\n### " << playerName << " the " << characterClass << " is ready for adventure!" << endl;
    cout << "Press Enter to continue...";
    cin.ignore();
    cin.get();
}

void DungeonCrawlerGame::visitShop() {
    cout << "\n### TOWN SHOP ###" << endl;
    cout << "================" << endl;
    cout << "Welcome to the traveler\'s shop. You have " << gold << " gold." << endl;
    cout << "Items for sale:" << endl;
    cout << "1. Leather Armor (+10 max health) - 25 gold" << endl;
    cout << "2. Iron Armor (+25 max health) - 50 gold" << endl;
    cout << "3. Health Potion (+50 health when used) - 10 gold" << endl;
    cout << "4. Mana Potion (+5 magic when used) - 8 gold" << endl;
    cout << "5. Leave shop" << endl;
    
    // Town shop purchase loop
    string line;
    while (true) {
        cout << "Enter choice (1-5): ";
        if (!getline(cin, line)) return;
        if (line.empty()) continue;
        int choice = 0;
        try { choice = stoi(line); } catch (...) { cout << "Invalid input." << endl; continue; }
        switch (choice) {
            case 1:
                if (gold >= 25) {
                    gold -= 25;
                    armor += 10;
                    maxHealth += 10;
                    health += 10;
                    cout << "You purchased Leather Armor. Max health increased by 10." << endl;
                } else {
                    cout << "Not enough gold." << endl;
                }
                break;
            case 2:
                if (gold >= 50) {
                    gold -= 50;
                    armor += 25;
                    maxHealth += 25;
                    health += 25;
                    cout << "You purchased Iron Armor. Max health increased by 25." << endl;
                } else {
                    cout << "Not enough gold." << endl;
                }
                break;
            case 3:
                if (gold >= 10) {
                    gold -= 10;
                    healthPotions += 1;
                    cout << "You purchased a Health Potion." << endl;
                } else {
                    cout << "Not enough gold." << endl;
                }
                break;
            case 4:
                if (gold >= 8) {
                    gold -= 8;
                    manaPotions += 1;
                    cout << "You purchased a Mana Potion." << endl;
                } else {
                    cout << "Not enough gold." << endl;
                }
                break;
            case 5:
                cout << "Leaving shop." << endl;
                return;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}

void DungeonCrawlerGame::run() {
    displayWelcome();
    chooseClass();
    chooseWeapon();
    allocateStatPoints();
    displayCharacterSheet();

    // Offer shop visit before adventure
    cout << "\nWould you like to visit the town shop before starting your adventure? (y/n): " << endl;
    string yn;
    getline(cin, yn);
    if (!yn.empty() && (yn[0] == 'y' || yn[0] == 'Y')) {
        visitShop();
        cout << "Press Enter to continue...";
        cin.get();
    }

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

      The dark entrance to the Cave of Evil stares at you ...
    )" << endl;

    cout << "1. Light a torch and proceed carefully." << endl;
    cout << "2. Charge into the darkness with your weapon drawn." << endl;
    cout << "3. Shout to see what answers the echo." << endl;
    cout << "4. Retreat to town (end adventure for now)." << endl;
    cout << "Enter your choice (1-4): " << endl;

    // Read a line so mixing previous cin doesn't break input
    string line;
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
                cout << "The noise draws a scavenger creature, but it startle-runs and drops an old amulet." << endl;
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

    // Proceed to encounter
    cout << "\nAs you venture deeper into the cave, the air grows colder and a faint clinking sound echoes ahead." << endl;
    cout << "You look up and see a skeleton with a sword in hand charging towards you." << endl;
    cout << "He lifts his arm and swings his sword towards you." << endl;

    cout << "\n### COMBAT ENCOUNTER! ###" << endl;
    cout << "You must defend yourself!" << endl;
    int enemyHealth = 30 + (level * 10);
    cout << "Enemy Skeleton Health: " << enemyHealth << endl;

    int turn = 1;
    uniform_int_distribution<int> enemyAtkRand(2, 6);

    while (enemyHealth > 0 && health > 0) {
        cout << "\n--- Turn " << turn << " ---" << endl;
        cout << "Your Health: " << health << "/" << maxHealth << "  |  Magic: " << magic << "  |  Health potions: " << healthPotions << "  |  Mana potions: " << manaPotions << endl;
        cout << "Enemy Health: " << enemyHealth << endl;

        bool enemyBackingAway = (turn % 3 == 0);
        if (enemyBackingAway) {
            cout << "The skeleton snarls and momentarily backs away, giving you a brief reprieve." << endl;
        }

        cout << "\nChoose your action:" << endl;
        cout << "1. Attack with your weapon" << endl;
        cout << "2. Use a health potion" << endl;
        cout << "3. Use a mana potion" << endl;
        cout << "Enter your choice (1-3): ";

        // read combat choice
        string combatLine;
        int combatChoice = 0;
        while (true) {
            if (!getline(cin, combatLine)) return; // EOF safety
            if (combatLine.empty()) {
                cout << "Please enter 1-3: ";
                continue;
            }
            try {
                combatChoice = stoi(combatLine);
                if (combatChoice >= 1 && combatChoice <= 3) break;
            } catch (...) {}
            cout << "Invalid input. Enter 1-3: ";
        }

        // Player action
        if (combatChoice == 1) {
            if (enemyBackingAway) {
                cout << "You lunge forward but the skeleton has backed away � your attack misses!" << endl;
            } else {
                int playerDamage = strength + smallRand(rng);
                enemyHealth -= playerDamage;
                cout << "\nYou strike the skeleton for " << playerDamage << " damage!" << endl;
                if (enemyHealth <= 0) {
                    cout << "The skeleton crumbles to dust. You are victorious!" << endl;
                    int lootGold = 10 + smallRand(rng) * 2;
                    gold += lootGold;
                    cout << "You find " << lootGold << " gold on the skeleton." << endl;
                    break;
                }
            }
        } else if (combatChoice == 2) {
            if (healthPotions > 0) {
                healthPotions--;
                int healAmount = 50;
                int prev = health;
                health = min(maxHealth, health + healAmount);
                cout << "\nYou drink a health potion and recover " << (health - prev) << " health! (Health: " << health << "/" << maxHealth << ")" << endl;
            } else {
                cout << "\nYou have no health potions left!" << endl;
            }
        } else if (combatChoice == 3) {
            if (manaPotions > 0) {
                manaPotions--;
                int manaAmount = 5;
                magic += manaAmount;
                cout << "\nYou drink a mana potion and recover " << manaAmount << " magic! (Magic: " << magic << ")" << endl;
            } else {
                cout << "\nYou have no mana potions left!" << endl;
            }
        }

        // Enemy turn (only attacks if not backing away and still alive)
        if (enemyHealth > 0 && !enemyBackingAway) {
            int enemyDamage = 5 + enemyAtkRand(rng);
            health -= enemyDamage;
            cout << "The skeleton swings back, dealing " << enemyDamage << " damage to you! (Health: " << max(0, health) << "/" << maxHealth << ")" << endl;
            if (health <= 0) {
                cout << "\nYou have been defeated by the skeleton. GAME OVER." << endl;
                cout << "Press Enter to return to main menu...";
                cin.get();
                return;
            }
        } else if (enemyHealth > 0 && enemyBackingAway) {
            cout << "The skeleton keeps its distance, watching you warily." << endl;
        }

        turn++;
    }

    if (health > 0 && enemyHealth <= 0) {
        // Player defeated the skeleton � continue deeper into the cave
        cout << "\nYou take a moment to catch your breath and loot the remains." << endl;
        cout << "The tunnel narrows and the air grows damper as you move deeper, torchlight flickering on the walls." << endl;
        cout << "A rustling sound grows louder ahead. You lead with your torch..." << endl;
        cout << "Suddenly, a giant spider drops from the ceiling and lands before you!" << endl;

        // --- Giant Spider Encounter ---
        int spiderHealth = 50 + (level * 15);
        cout << "A GIANT SPIDER appears!" << endl;
        cout << "Spider Health: " << spiderHealth << endl;

        uniform_int_distribution<int> spiderAtkRand(4, 10);
        uniform_int_distribution<int> webChance(1, 100);
        bool webbed = false; // if true, player's attack will miss (struggles to free)
        int spiderTurn = 1;

        while (spiderHealth > 0 && health > 0) {
            cout << "\n--- Spider Turn " << spiderTurn << " ---" << endl;
            cout << "Your Health: " << health << "/" << maxHealth << "  |  Magic: " << magic << "  |  Health potions: " << healthPotions << "  |  Mana potions: " << manaPotions << endl;
            cout << "Spider Health: " << spiderHealth << endl;

            if (webbed) {
                cout << "You are tangled in webbing! Your movements are slowed this turn." << endl;
            }

            cout << "\nChoose your action:" << endl;
            cout << "1. Attack with your weapon" << endl;
            cout << "2. Use a health potion" << endl;
            cout << "3. Use a mana potion" << endl;
            cout << "Enter your choice (1-3): ";

            string combatLine;
            int combatChoice = 0;
            while (true) {
                if (!getline(cin, combatLine)) return; // EOF safety
                if (combatLine.empty()) {
                    cout << "Please enter 1-3: ";
                    continue;
                }
                try { combatChoice = stoi(combatLine); } catch (...) { cout << "Invalid input. Enter 1-3: "; continue; }
                if (combatChoice >= 1 && combatChoice <= 3) break;
            }

            // Player action
            if (combatChoice == 1) {
                if (webbed) {
                    cout << "You struggle at the webbing and try to strike, but the spider's webbing slows your blow � it misses!" << endl;
                    // escaping attempt reduces webbed flag with some chance
                    if (webChance(rng) <= 50) {
                        webbed = false;
                        cout << "You partially free yourself from the webbing." << endl;
                    }
                } else {
                    int playerDamage = strength + smallRand(rng);
                    spiderHealth -= playerDamage;
                    cout << "\nYou slash at the spider for " << playerDamage << " damage!" << endl;
                    if (spiderHealth <= 0) {
                        cout << "The giant spider collapses, legs twitching. You have slain it!" << endl;
                        int lootGold = 20 + smallRand(rng) * 3;
                        gold += lootGold;
                        cout << "You gather " << lootGold << " gold and some strange chitin from the corpse." << endl;
                        break;
                    }
                }
            } else if (combatChoice == 2) {
                if (healthPotions > 0) {
                    healthPotions--;
                    int healAmount = 50;
                    int prev = health;
                    health = min(maxHealth, health + healAmount);
                    cout << "\nYou drink a health potion and recover " << (health - prev) << " health! (Health: " << health << "/" << maxHealth << ")" << endl;
                } else {
                    cout << "\nYou have no health potions left!" << endl;
                }
            } else if (combatChoice == 3) {
                if (manaPotions > 0) {
                    manaPotions--;
                    int manaAmount = 5;
                    magic += manaAmount;
                    cout << "\nYou drink a mana potion and recover " << manaAmount << " magic! (Magic: " << magic << ")" << endl;
                } else {
                    cout << "\nYou have no mana potions left!" << endl;
                }
            }

            // Spider turn: may web (30% chance) or attack
            if (spiderHealth > 0) {
                int chance = webChance(rng);
                if (!webbed && chance <= 30) {
                    webbed = true;
                    cout << "The spider flings sticky webbing and entangles you! You'll be slowed next turn." << endl;
                } else {
                    int spiderDamage = spiderAtkRand(rng);
                    health -= spiderDamage;
                    cout << "The spider lunges and bites, dealing " << spiderDamage << " damage! (Health: " << max(0, health) << "/" << maxHealth << ")" << endl;
                    if (health <= 0) {
                        cout << "\nYou have been killed by the giant spider. GAME OVER." << endl;
                        cout << "Press Enter to return to main menu...";
                        cin.get();
                        return;
                    }
                }
            }

            spiderTurn++;
        }

        if (health > 0 && spiderHealth <= 0) {
            cout << "\nAs the spider dies, you notice a tattered scrap of parchment stuck on the spiders web." << endl;
            cout << "You pry the parchment free and you hold your torch close to read the words 'Eye Jewel of Orin' and you find a stone on the ground engraved with a spiral like an eye." << endl;
            cout << "You find a small spiral-shaped stone caught in the web and a filthy gem that glints like an eye." << endl;
            hasSpiralStone = true;
            hasEyeJewel = true;
            cout << "You place the spiral stone and the eye-like jewel into your pouch." << endl;

            cout << "\nThe path ahead winds back to town. Thoughts turn to Bladimir Okenstall, a trader who might know more about these artifacts." << endl;

            // End of Chapter choices
            cout << "\nHow will you proceed?" << endl;
            cout << "1. Create a camp here and rest until morning." << endl;
            cout << "2. Head to town now to seek Bladimir Okenstall (it's dark and raining)." << endl;
            cout << "Enter your choice (1-2): ";

            string endLine;
            int endChoice = 0;
            while (true) {
                if (!getline(cin, endLine)) return; // EOF safety
                if (endLine.empty()) { cout << "Enter 1 or 2: "; continue; }
                try { endChoice = stoi(endLine); } catch (...) { cout << "Invalid. Enter 1 or 2: "; continue; }
                if (endChoice == 1 || endChoice == 2) break;
            }

            if (endChoice == 1) {
                cout << "\nYou set up a small camp, tend to wounds, and sleep until dawn. The path at morning is clear." << endl;
                cout << "You decide to head to town in the morning to find Bladimir." << endl;
                cout << "Chapter 1 complete. Press Enter to return to main menu...";
                cin.get();
                return;
            } else {
                cout << "\nYou brave the rain and make for town under cover of darkness." << endl;
                cout << "As you approach the outskirts, shadowy figures leap from behind rocks � goblins!" << endl;

                // Simple goblin ambush encounter
                int goblinHealth = 20 + (level * 5);
                uniform_int_distribution<int> gobAtk(3, 7);
                int gobTurn = 1;

                while (goblinHealth > 0 && health > 0) {
                    cout << "\n--- Goblin Ambush Turn " << gobTurn << " ---" << endl;
                    cout << "Your Health: " << health << "/" << maxHealth << "  |  Health potions: " << healthPotions << endl;
                    cout << "Goblin Health: " << goblinHealth << endl;
                    cout << "\nChoose action: 1=Attack, 2=Use Health Potion" << endl;

                    string gLine;
                    int gChoice = 0;
                    while (true) {
                        if (!getline(cin, gLine)) return;
                        if (gLine.empty()) { cout << "Enter 1 or 2: "; continue; }
                        try { gChoice = stoi(gLine); } catch (...) { cout << "Invalid. Enter 1 or 2: "; continue; }
                        if (gChoice == 1 || gChoice == 2) break;
                    }

                    if (gChoice == 1) {
                        int dmg = strength + smallRand(rng);
                        goblinHealth -= dmg;
                        cout << "You swing and deal " << dmg << " damage to the goblin!" << endl;
                        if (goblinHealth <= 0) {
                            cout << "The goblin falls back into the mud. You survived the ambush." << endl;
                            int loot = 5 + smallRand(rng);
                            gold += loot;
                            cout << "You scavenge " << loot << " gold from the corpse." << endl;
                            break;
                        }
                    } else {
                        if (healthPotions > 0) {
                            healthPotions--;
                            int prev = health;
                            health = min(maxHealth, health + 50);
                            cout << "You use a health potion and recover " << (health - prev) << " health." << endl;
                        } else {
                            cout << "You have no health potions!" << endl;
                        }
                    }

                    // Goblin attacks
                    if (goblinHealth > 0) {
                        int dmg = gobAtk(rng);
                        health -= dmg;
                        cout << "The goblin slashes you for " << dmg << " damage! (Health: " << max(0, health) << "/" << maxHealth << ")" << endl;
                        if (health <= 0) {
                            cout << "\nYou were killed by the goblin. GAME OVER." << endl;
                            cout << "Press Enter to return to main menu...";
                            cin.get();
                            return;
                        }
                    }

                    gobTurn++;
                }

                cout << "\nYou limp into town, bruised and soaked, with the Eye Jewel and Spiral Stone safely in your pouch." << endl;
                
                // --- TOWN CENTER PHASE ---
                cout << "\n### CHAPTER 2: TOWN CENTER ###" << endl;
                cout << "==============================" << endl;
                cout << "You arrive at the town center as the sun begins to set." << endl;
                cout << "The marketplace is winding down, merchants packing their wares." << endl;
                cout << "A few townsfolk mill about, chatting quietly." << endl;
                cout << "\nAs you look around, your eyes catch a MYSTERIOUS HOODED FIGURE" << endl;
                cout << "standing in the shadows near the fountain, watching you intently." << endl;
                cout << "The figure's gaze makes you uneasy..." << endl;
                
                cout << "\nWhat do you do?" << endl;
                cout << "1. Approach the hooded figure" << endl;
                cout << "2. Ignore the figure and head to the inn to rest" << endl;
                cout << "3. Ask nearby townsfolk about the hooded figure" << endl;
                cout << "Enter your choice (1-3): ";
                
                string townLine;
                int townChoice = 0;
                while (true) {
                    if (!getline(cin, townLine)) return;
                    if (townLine.empty()) { cout << "Enter 1-3: "; continue; }
                    try { townChoice = stoi(townLine); } catch (...) { cout << "Invalid. Enter 1-3: "; continue; }
                    if (townChoice >= 1 && townChoice <= 3) break;
                }
                
                if (townChoice == 1) {
                    // Approach hooded figure - triggers quest
                    engagedHoodedFigure = true;
                    cout << "\nYou cautiously approach the hooded figure." << endl;
                    cout << "As you get closer, a raspy voice emanates from beneath the hood:" << endl;
                    cout << "\"Greetings, adventurer. I've heard tales of your... expedition into the cave.\"" << endl;
                    cout << "\"I have a proposition for you. There's trouble at Old Maggie's farm.\"" << endl;
                    cout << "\"Goblins have been raiding her livestock. Clear them out, and I'll make it worth your while.\"" << endl;
                    cout << "\nThe figure extends a gloved hand. \"50 gold upon completion. What say you?\"" << endl;
                    
                    cout << "\nDo you accept the quest?" << endl;
                    cout << "1. Accept the goblin quest" << endl;
                    cout << "2. Decline and walk away" << endl;
                    cout << "Enter your choice (1-2): ";
                    
                    string questLine;
                    int questChoice = 0;
                    while (true) {
                        if (!getline(cin, questLine)) return;
                        if (questLine.empty()) { cout << "Enter 1 or 2: "; continue; }
                        try { questChoice = stoi(questLine); } catch (...) { cout << "Invalid. Enter 1 or 2: "; continue; }
                        if (questChoice == 1 || questChoice == 2) break;
                    }
                    
                    if (questChoice == 1) {
                        // Accept quest
                        acceptedGoblinQuest = true;
                        cout << "\n\"Excellent,\" the figure hisses. \"The farm is just outside the east gate.\"" << endl;
                        cout << "\"Return to me when it's done.\"" << endl;
                        
                        // Travel to farm
                        cout << "\nPress Enter to travel to the farm...";
                        cin.get();
                        
                        cout << "\n### OLD MAGGIE'S FARM ###" << endl;
                        cout << "========================" << endl;
                        cout << "You arrive at the farm as darkness falls." << endl;
                        cout << "You can hear squealing pigs and the harsh laughter of goblins." << endl;
                        cout << "Three goblins are tormenting the livestock in the barn!" << endl;
                        
                        // Goblin combat at farm
                        uniform_int_distribution<int> gobAtkFarm(3, 8);
                        int goblinsRemaining = 3;
                        int totalGoblinLoot = 0;
                        
                        for (int i = 1; i <= 3; i++) {
                            if (health <= 0) break;
                            
                            cout << "\n### GOBLIN " << i << " OF 3 ###" << endl;
                            int gobHealth = 25 + (level * 5);
                            cout << "Goblin Health: " << gobHealth << endl;
                            
                            int farmTurn = 1;
                            while (gobHealth > 0 && health > 0) {
                                cout << "\n--- Turn " << farmTurn << " ---" << endl;
                                cout << "Your Health: " << health << "/" << maxHealth << "  |  Potions: " << healthPotions << endl;
                                cout << "Goblin Health: " << gobHealth << endl;
                                cout << "\n1. Attack" << endl;
                                cout << "2. Use health potion" << endl;
                                cout << "Enter choice (1-2): ";
                                
                                string farmLine;
                                int farmCombat = 0;
                                while (true) {
                                    if (!getline(cin, farmLine)) return;
                                    if (farmLine.empty()) { cout << "Enter 1 or 2: "; continue; }
                                    try { farmCombat = stoi(farmLine); } catch (...) { cout << "Invalid. Enter 1 or 2: "; continue; }
                                    if (farmCombat == 1 || farmCombat == 2) break;
                                }
                                
                                if (farmCombat == 1) {
                                    int dmg = strength + smallRand(rng);
                                    gobHealth -= dmg;
                                    cout << "You strike for " << dmg << " damage!" << endl;
                                    if (gobHealth <= 0) {
                                        cout << "The goblin collapses!" << endl;
                                        int loot = 8 + smallRand(rng);
                                        totalGoblinLoot += loot;
                                        cout << "You loot " << loot << " gold from the goblin." << endl;
                                        goblinsRemaining--;
                                        break;
                                    }
                                } else {
                                    if (healthPotions > 0) {
                                        healthPotions--;
                                        int prev = health;
                                        health = min(maxHealth, health + 50);
                                        cout << "You use a health potion and recover " << (health - prev) << " health." << endl;
                                    } else {
                                        cout << "No health potions available!" << endl;
                                    }
                                }
                                
                                // Goblin attacks
                                if (gobHealth > 0) {
                                    int dmg = gobAtkFarm(rng);
                                    health -= dmg;
                                    cout << "Goblin attacks for " << dmg << " damage! (Health: " << max(0, health) << "/" << maxHealth << ")" << endl;
                                    if (health <= 0) {
                                        cout << "\nYou have been defeated. GAME OVER." << endl;
                                        cout << "Press Enter to return to main menu...";
                                        cin.get();
                                        return;
                                    }
                                }
                                farmTurn++;
                            }
                        }
                        
                        if (goblinsRemaining == 0) {
                            completedGoblinQuest = true;
                            gold += totalGoblinLoot;
                            cout << "\n### QUEST COMPLETE! ###" << endl;
                            cout << "You've cleared all the goblins from the farm!" << endl;
                            cout << "Total loot collected: " << totalGoblinLoot << " gold" << endl;
                            
                            // Find mysterious items
                            cout << "\nAs you search the goblins' belongings, you find something unusual..." << endl;
                            cout << "A TORN PARCHMENT and a GLOWING STONE - similar to what you found in the cave!" << endl;
                            cout << "Why would goblins have these items?" << endl;
                            hasParchmentPiece1 = true;
                            
                            cout << "\nPress Enter to return to town...";
                            cin.get();
                            
                            // Return to hooded figure
                            cout << "\n### BACK AT TOWN CENTER ###" << endl;
                            cout << "==========================" << endl;
                            cout << "You return to the town center to find the hooded figure waiting." << endl;
                            cout << "\"Ah, you've returned. Well done,\" the figure says, stepping closer." << endl;
                            cout << "\"Now... about your payment. I believe you found something interesting?\"" << endl;
                            cout << "\nThe figure's voice turns cold:" << endl;
                            cout << "\"The parchment and stone you found - both in the cave AND on those goblins.\"" << endl;
                            cout << "\"I've been following you since you left the Cave of Evil.\"" << endl;
                            cout << "\"Those items belong to me. Hand them over... or suffer the consequences.\"" << endl;
                            
                            cout << "\nThe hooded figure draws a curved dagger!" << endl;
                            cout << "\n### BOSS FIGHT: HOODED SABOTEUR ###" << endl;
                            cout << "===================================" << endl;
                            
                            int bossHealth = 60 + (level * 15);
                            uniform_int_distribution<int> bossAtk(5, 12);
                            int bossTurn = 1;
                            
                            while (bossHealth > 0 && health > 0) {
                                cout << "\n--- Turn " << bossTurn << " ---" << endl;
                                cout << "Your Health: " << health << "/" << maxHealth << "  |  Magic: " << magic << "  |  Potions: " << healthPotions << endl;
                                cout << "Hooded Figure Health: " << bossHealth << endl;
                                
                                cout << "\n1. Physical attack (Strength-based)" << endl;
                                cout << "2. Magic attack (Magic-based, costs 2 magic)" << endl;
                                cout << "3. Use health potion" << endl;
                                cout << "Enter choice (1-3): ";
                                
                                string bossLine;
                                int bossCombat = 0;
                                while (true) {
                                    if (!getline(cin, bossLine)) return;
                                    if (bossLine.empty()) { cout << "Enter 1-3: "; continue; }
                                    try { bossCombat = stoi(bossLine); } catch (...) { cout << "Invalid. Enter 1-3: "; continue; }
                                    if (bossCombat >= 1 && bossCombat <= 3) break;
                                }
                                
                                if (bossCombat == 1) {
                                    int dmg = strength + smallRand(rng) + 2;
                                    bossHealth -= dmg;
                                    cout << "You strike with your " << weapon << " for " << dmg << " damage!" << endl;
                                } else if (bossCombat == 2) {
                                    if (magic >= 2) {
                                        magic -= 2;
                                        int dmg = magic + smallRand(rng) + 5;
                                        bossHealth -= dmg;
                                        cout << "You unleash a magical blast for " << dmg << " damage!" << endl;
                                    } else {
                                        cout << "Not enough magic! Attack fails." << endl;
                                    }
                                } else {
                                    if (healthPotions > 0) {
                                        healthPotions--;
                                        int prev = health;
                                        health = min(maxHealth, health + 50);
                                        cout << "You use a health potion and recover " << (health - prev) << " health." << endl;
                                    } else {
                                        cout << "No health potions available!" << endl;
                                    }
                                }
                                
                                if (bossHealth <= 0) {
                                    cout << "\n### VICTORY! ###" << endl;
                                    cout << "The hooded figure stumbles and falls to their knees." << endl;
                                    cout << "The hood falls back, revealing a scarred face twisted with rage." << endl;
                                    cout << "\"You... you don't understand what you've done...\" they gasp." << endl;
                                    cout << "\"Those artifacts... the ritual... it's already begun...\"" << endl;
                                    cout << "\nThe figure collapses. You search their body and find:" << endl;
                                    cout << "- 50 gold (the promised payment)" << endl;
                                    cout << "- ANOTHER PARCHMENT PIECE!" << endl;
                                    gold += 50;
                                    hasParchmentPiece2 = true;
                                    cout << "\nYou now have TWO pieces of the mysterious parchment." << endl;
                                    cout << "When placed together, they form part of a map with strange symbols." << endl;
                                    cout << "What ritual were they talking about?" << endl;
                                    break;
                                }
                                
                                // Boss attacks
                                if (bossHealth > 0) {
                                    int dmg = bossAtk(rng);
                                    // Boss special ability every 3 turns
                                    if (bossTurn % 3 == 0) {
                                        dmg += 5;
                                        cout << "The figure uses a poison strike!" << endl;
                                    }
                                    health -= dmg;
                                    cout << "The hooded figure strikes for " << dmg << " damage! (Health: " << max(0, health) << "/" << maxHealth << ")" << endl;
                                    if (health <= 0) {
                                        cout << "\nYou have been defeated by the hooded saboteur. GAME OVER." << endl;
                                        cout << "Press Enter to return to main menu...";
                                        cin.get();
                                        return;
                                    }
                                }
                                bossTurn++;
                            }
                            
                            level++;
                            cout << "\n### CHAPTER 2 COMPLETE! ###" << endl;
                            cout << "You've uncovered a conspiracy and survived an ambush!" << endl;
                            cout << "Current Stats - Health: " << health << "/" << maxHealth << ", Strength: " << strength << ", Magic: " << magic << ", Gold: " << gold << endl;
                            cout << "Level: " << level << endl;
                            cout << "\nThe mystery deepens... What do these parchment pieces reveal?" << endl;
                            cout << "Press Enter to return to main menu...";
                            cin.get();
                            return;
                        }
                        
                    } else {
                        // Decline quest
                        cout << "\n\"Pity,\" the figure mutters. \"I thought you had more courage.\"" << endl;
                        cout << "The figure melts back into the shadows and disappears." << endl;
                        cout << "\nYou head to the inn to rest, wondering who that was." << endl;
                        cout << "Press Enter to continue...";
                        cin.get();
                        cout << "\n(This storyline path ends here for now.)" << endl;
                        cout << "Press Enter to return to main menu...";
                        cin.get();
                        return;
                    }
                    
                } else if (townChoice == 2) {
                    // Ignore and go to inn
                    cout << "\nYou decide to avoid the mysterious figure and head straight to the inn." << endl;
                    cout << "As you walk away, you feel eyes watching your back..." << endl;
                    cout << "You rest for the night, but sleep uneasily." << endl;
                    cout << "\nThe hooded figure is gone in the morning. You've avoided the confrontation... for now." << endl;
                    cout << "Press Enter to return to main menu...";
                    cin.get();
                    return;
                    
                } else {
                    // Ask townsfolk
                    cout << "\nYou approach an elderly merchant packing his cart." << endl;
                    cout << "\"That hooded one? Been lurking around for days,\" he says nervously." << endl;
                    cout << "\"Nobody knows who they are. I'd stay clear if I were you.\"" << endl;
                    cout << "\nWhen you turn back to look, the hooded figure has vanished into the night." << endl;
                    cout << "You've avoided the encounter, but you can't shake the feeling you're being watched." << endl;
                    cout << "Press Enter to return to main menu...";
                    cin.get();
                    return;
                }
            }
        }
    }

    // Level complete - advance (fallback)
    level++;
    cout << "\n### LEVEL 1 COMPLETE! ###" << endl;
    cout << "You survived the cave entrance and are ready for the next challenge." << endl;
    cout << "Current Stats - Health: " << health << "/" << maxHealth << ", Strength: " << strength << ", Magic: " << magic << ", Gold: " << gold << endl;
    cout << "Advancing to Level " << level << "..." << endl;
    cout << "Press Enter to continue to the next phase...";
    cin.get();

    // Next phase menu after advancing to Level 2
    cout << "\n### NEXT PHASE: WHAT WILL YOU DO? ###" << endl;
    cout << "=====================================" << endl;
    cout << "1. Seek out Bladimir Okenstall, the artifact expert" << endl;
    cout << "2. Visit the town shop" << endl;
    cout << "3. Go home and rest" << endl;
    cout << "Enter your choice (1-3): ";

    string nextLine;
    int nextChoice = 0;
    while (true) {
        if (!getline(cin, nextLine)) return;
        if (nextLine.empty()) { cout << "Enter 1-3: "; continue; }
        try { nextChoice = stoi(nextLine); } catch (...) { cout << "Invalid. Enter 1-3: "; continue; }
        if (nextChoice >= 1 && nextChoice <= 3) break;
        cout << "Invalid. Enter 1-3: ";
    }

    if (nextChoice == 1) {
        // Bladimir Okenstall - artifact expert dialog and stat bonus
        cout << "\n### BLADIMIR OKENSTALL'S SHOP ###" << endl;
        cout << "=================================" << endl;
        cout << "You make your way to the edge of town where a small, cluttered shop" << endl;
        cout << "sits beneath a crooked sign: \"Okenstall Antiquities & Curiosities.\"" << endl;
        cout << "\nA bell chimes as you enter. An elderly man with wild gray hair" << endl;
        cout << "and spectacles perched on his nose looks up from a dusty tome." << endl;
        cout << "\n\"Ah! A visitor! Welcome, welcome!\" he exclaims." << endl;
        cout << "\"I am Bladimir Okenstall. And you... you carry something interesting.\"" << endl;
        cout << "\nHis eyes gleam as he notices your pouch." << endl;

        // Examine artifacts
        cout << "\nBladimir examines your artifacts with great interest..." << endl;
        if (hasEyeJewel || hasSpiralStone) {
            cout << "\n\"Fascinating!\" he breathes. \"Do you know what you have here?\"" << endl;
            if (hasEyeJewel) {
                cout << "\"This Eye Jewel... it's said to be part of the Eye of Orin,\"" << endl;
                cout << "\"an ancient artifact that reveals hidden truths.\"" << endl;
            }
            if (hasSpiralStone) {
                cout << "\"And this Spiral Stone! It's a key, of sorts.\"" << endl;
                cout << "\"Legends speak of a sealed chamber deep in the mountains.\"" << endl;
            }
        }

        // Explain ritual/map
        cout << "\nBladimir spreads an old map across his cluttered table." << endl;
        cout << "\"These artifacts are connected to an ancient ritual,\" he explains." << endl;
        cout << "\"Long ago, powerful mages sealed away a great evil.\"" << endl;
        cout << "\"The ritual required specific items - items like these.\"" << endl;
        cout << "\n\"This map shows the locations where the ritual was performed.\"" << endl;
        cout << "\"If someone were to gather all the pieces...\"" << endl;
        cout << "He trails off, a worried look crossing his face." << endl;
        cout << "\n\"Take this knowledge with you, adventurer. Be careful out there.\"" << endl;

        // Grant stat bonuses
        cout << "\nBladimir rummages through his belongings and produces a small vial." << endl;
        cout << "\"Here - a gift for bringing me such fascinating specimens to study.\"" << endl;
        cout << "\"This elixir will strengthen your body and mind.\"" << endl;
        cout << "\nYou drink the elixir and feel a surge of power!" << endl;
        strength += 1;
        magic += 1;
        maxHealth += 1;
        health += 1;
        cout << "### +1 Strength! +1 Magic! +1 Max Health! +1 Health! ###" << endl;
        cout << "Updated Stats - Strength: " << strength << ", Magic: " << magic << ", Health: " << health << "/" << maxHealth << endl;

    } else if (nextChoice == 2) {
        // Visit the town shop
        cout << "\nYou decide to visit the town shop to stock up on supplies." << endl;
        visitShop();

    } else {
        // Go home and rest
        cout << "\n### HOME SWEET HOME ###" << endl;
        cout << "======================" << endl;
        cout << "Weary from your adventures, you return to your modest dwelling." << endl;
        cout << "The familiar creak of the door is a welcome sound." << endl;
        cout << "\nYou light a fire in the hearth and prepare a simple meal." << endl;
        cout << "As the flames crackle, you reflect on your journey so far." << endl;
        cout << "\nThe cave, the battles, the mysterious artifacts..." << endl;
        cout << "There's still so much you don't understand." << endl;
        cout << "\nBut for now, rest is what you need most." << endl;
        cout << "You settle into your bed and drift into a deep, dreamless sleep." << endl;
        cout << "\n*** Your health has been fully restored! ***" << endl;
        health = maxHealth;
        cout << "Health: " << health << "/" << maxHealth << endl;
    }

    cout << "\nPress Enter to return to main menu...";
    cin.get();
}