#include "dungeon_crawler_game.h"
#include "Character.h"
#include "Shop.h"

DungeonCrawlerGame::DungeonCrawlerGame(const string& name) : 
    rng(static_cast<unsigned int>(time(nullptr))), 
    playerName(name), 
    level(1),
    gold(50),
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

void DungeonCrawlerGame::run() {
    displayWelcome();

    // Use Character module for player stats and choices
    Character player;
    player.chooseClass();
    player.chooseWeapon();
    player.allocateStatPoints();
    player.displayCharacterSheet(playerName);

    // Offer shop visit before adventure
    cout << "\nWould you like to visit the town shop before starting your adventure? (y/n): " << endl;
    string yn;
    getline(cin, yn);
    if (!yn.empty() && (yn[0] == 'y' || yn[0] == 'Y')) {
        Shop::visit(player, gold);
        cout << "Press Enter to continue...";
        cin.get();
    }

    // --- Level 1: Entrance to the Cave of Evil ---
    cout << "\n### LEVEL 1: The Cave of EVIL ###" << endl;
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

    // Continue using local variables (deprecated ones from Character left in file for now)
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
        }
        catch (...) {}
        cout << "Invalid input. Enter 1-4: ";
    }

    uniform_int_distribution<int> smallRand(1, 6);

    switch (choice) {
    case 1: {
        cout << "\nYou light a torch and step forward, the tunnel reveals uneven stones and old markings." << endl;
        int foundGold = 5 + smallRand(rng);
        gold += foundGold;
        cout << "Hidden in a crack you find a small pouch containing " << foundGold << " gold!" << endl;
        cout << "You proceed safely deeper, senses alert." << endl;
        break;
    }
    case 2: {
        cout << "\nYou charge into the dark, sword raised. Something latches onto your leg!" << endl;
        int damage = smallRand(rng);
        player.health -= damage;
        cout << "You struggle free but take " << damage << " damage. (Health: " << max(0, player.health) << "/" << player.maxHealth << ")" << endl;
        if (player.health <= 0) {
            cout << "\nYou succumb to your wounds in the darkness. GAME OVER." << endl;
            cout << "Press Enter to return to main menu...";
            cin.get();
            return;
        }
        cout << "Bruised but alive, you press on." << endl;
        break;
    }
    case 3: {
        cout << "\nYou let out a shout and the cave answers with a chorus of clicks and a distant scuttling." << endl;
        int reaction = smallRand(rng);
        if (reaction >= 5) {
            cout << "The noise draws a scavenger creature, but it startle-runs and drops an old amulet." << endl;
            cout << "You pick up the amulet (+1 Magic)." << endl;
            player.magic += 1;
        }
        else {
            cout << "The echo wakes a nest of bats that graze you as they pass." << endl;
            int damage = 1 + smallRand(rng) % 2;
            player.health -= damage;
            cout << "You take " << damage << " damage. (Health: " << max(0, player.health) << "/" << player.maxHealth << ")" << endl;
            if (player.health <= 0) {
                cout << "\nYou fall in the dark. GAME OVER." << endl;
                cout << "Press Enter to return to main menu...";
                cin.get();
                return;
            }
        }
        break;
    }
    case 4: {
        cout << "\nYou decide discretion is the better part of valor and return to town for now." << endl;
        cout << "Level 1 aborted. Press Enter to return to main menu...";
        cin.get();
        return;
    }
    default:
        break;
    }

    // TODO: continue refactoring combat & scenes to use Character instance
    // For now, update remaining references to use player where appropriate.

    cout << "\nPress Enter to return to main menu...";
    cin.get();
}