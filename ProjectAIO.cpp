#include <iostream>
#include<string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>
#include <stdlib.h>


using namespace std;


class Action;
class Opponent;





class GummyFighter {
protected:  //variable used by both GummyFighter class and Opponent class
    string name;
    int level;
    int health;
    int strength;
    int defense;
    int luck;
    int uniqueID;
    int stamina;
public: //methods
    GummyFighter(string , int , int ); //overloaded constructor
    GummyFighter(); //defualt constructor

    string getName(); //getters and setters
    void setName(string );
    int getLevel();
    void setLevel(int );
    int getHealth();
    void setHealth(int );
    int getStrength();
    void setStrength(int );
    int getDefense();
    void setDefense(int );
    int getLuck();
    void setLuck(int );
    int getStamina();
    void setStamina(int );
    void setID(int);
    int getID();

    void viewCreated(GummyFighter& ); //Display user gummyfighter after user creates it
    
    void displayStats(GummyFighter& user); //Displays user Stamina and Health during battle

    void attackOp(Opponent& AI, GummyFighter& user, int); //Calls attackOpponent located in the Action class
    int trainn(GummyFighter&); //Calls the train method located in the Action class
    void deff(GummyFighter& ); //Calls the defend method located in the Action class
    

    bool luckChance(GummyFighter& );//If you get lucky you get a damage Multiplier

    void cheater(GummyFighter& ); //special method

    ~GummyFighter(); //destorys GummyFighter class pointer object
private:
    Action* act; //Allows act to hold memory address of an object of the Action class.

};


class Opponent : public GummyFighter {
public:
    Opponent(string , int , int );//overloaded constructor
    Opponent(); //default constructor

    string getName(); //getters and setters
    void setName(string );
    int getLevel();
    void setLevel(int );
    int getHealth();
    void setHealth(int );
    int getStrength();
    void setStrength(int );
    int getDefense();
    void setDefense(int );
    int getLuck();
    void setLuck(int );
    int getStamina();
    void setStamina(int );
    
    void statRandomizer(); //Randomizes Opponents stats based off of choosen difficulty 

    void AIstats(Opponent&); //Displays opponent's Health and Stamina during battle
    void fullStats(Opponent&); //Displays opponent's Full Stats before battle

    void attackUser(Opponent& , GummyFighter& , int ); //Call attackUser located in the Action class
    void actionRandomizer(Opponent& , GummyFighter& ); //Calls Action 

    bool AIluckChance(Opponent&); //AI luck

    ~Opponent(); //destorys Opponent class pointer object

private:
    Action* AIact; //Allows AIact to hold memory address of an object of the Action class.
};


class Action {
public:
    Action(); //default

    void attackOpponent(Opponent& , GummyFighter& , int ); //Attacking mechanics

    void attackUser(Opponent& , GummyFighter& , int ); //Attacking mechanics

    void defend(GummyFighter& ); //Defending Mechanics

    void AIdefend(Opponent& ); //Defending Mechanics

    int train(GummyFighter& ); //Trains or boosts a random user stat


    //moveset methods
    int roundkick();
    int jab();
    int uppercut();
    int takedown();
    int kick();
    int knee();

    //hook, elbow, sidekick, frontkick



    void actionRandomizer(Opponent& , GummyFighter& ); //AI Randomly chooses Attack of Defend during battle versus User

private:
    int damage = 0;

    int calculateDamage(int , GummyFighter& , Opponent& ); //calculateDamage

    int calculateAIDamage(int , GummyFighter& , Opponent& ); //calculateDamage

};

//----------------------------------------------------------------------------------GummyFighter------------------------------------------------------------------------------------------------

GummyFighter::GummyFighter(string name, int level, int uniqueID) { //constrcutor implementation 
    this->name = name;
    this->level = level;
    this->uniqueID = uniqueID;
    strength = 0;
    defense = 0;
    luck = 0;
    health = 0;
    stamina = 0;
    act = new Action(); //dynamically allocate memory for an object of the Action class
}
GummyFighter::GummyFighter() { //defualt constrcutor implementation 
    name = "";
    level = 0;
    uniqueID = 0;
    strength = 0;
    defense = 0;
    luck = 0;
    health = 0;
    stamina = 0;
    act = new Action(); //dynamically allocate memory for an object of the Action class
}

string GummyFighter::getName() { return name; } //getters and setters
void GummyFighter::setName(string n) { name = n; }
int GummyFighter::getLevel() { return level; }
void GummyFighter::setLevel(int l) { level = l; }
int GummyFighter::getHealth() { return health; }
void GummyFighter::setHealth(int h) { health = h; }
int GummyFighter::getStrength() { return strength; }
void GummyFighter::setStrength(int a) { strength = a; }
int GummyFighter::getDefense() { return defense; }
void GummyFighter::setDefense(int d) { defense = d; }
int GummyFighter::getLuck() { return luck; }
void GummyFighter::setLuck(int lu) { luck = lu; }
int GummyFighter::getStamina() { return stamina; }
void GummyFighter::setStamina(int s) { stamina = s; }
void GummyFighter::setID(int I) { uniqueID = I; }
int GummyFighter::getID() { return uniqueID; }


void GummyFighter::viewCreated(GummyFighter& user) { 
    cout << "Your name: " << user.getName() << endl;
    cout << "Your Health: " << user.getHealth() << endl;
    cout << "Your Stamina: " << user.getStamina() << endl;
    cout << "Your Strength: " << user.getStrength() << endl;
    cout << "Your Defense: " << user.getDefense() << endl;
    cout << "Your Luck: " << user.getLuck() << endl;
    cout << "Your ID : " << user.getID() << endl;

}
void GummyFighter::displayStats(GummyFighter& user) {
    cout << "User Health: " << user.getHealth() << endl;
    cout << "User Stamina: " << user.getStamina() << endl;
    cout << "\n";
}


int GummyFighter::trainn(GummyFighter& user) { //calls Action
    return act->train(user);
}

void GummyFighter::attackOp(Opponent& AI, GummyFighter& user, int option) { //calls Action
    
    act->attackOpponent(AI, user, option);
}

GummyFighter::~GummyFighter() { //deletes action object
    delete act;
}

bool GummyFighter::luckChance(GummyFighter& user) { //Luck implementation
   
    int lucky = (rand() % user.getLuck() + 1);
    if (lucky == 69) {
        return true;

    }
    return false;

}

void GummyFighter::deff(GummyFighter& user) { //calls action
    act->defend(user);
}

void GummyFighter::cheater(GummyFighter& user) { //If user name is FettyWap
    user.setStamina(1000);
    user.setStrength(1000);
    user.setHealth(1000);
    user.setDefense(1000);
    user.setLuck(1000);
}
//----------------------------------------------------------------------------------Opponent------------------------------------------------------------------------------------------------

Opponent::Opponent(string name, int level, int uniqueID) : GummyFighter(name, level, uniqueID) { //constructor implmentation 
    statRandomizer();
    AIact = new Action();

}
Opponent::Opponent() { //defualt constructor implmentation 
    
    name = "";
    level = 0;
    uniqueID = 0;
    strength = 0;
    defense = 0;
    luck = 0;
    health = 0;
    stamina = 0;
    
    statRandomizer();
    
    AIact = new Action();
    
}
string Opponent::getName() { return name; } //getters and setter
void Opponent::setName(string n) { name = n; }
int Opponent::getLevel() { return level; }
void Opponent::setLevel(int l) { level = l; }
int Opponent::getHealth() { return health; }
void Opponent::setHealth(int h) { health = h; }
int Opponent::getStrength() { return strength; }
void Opponent::setStrength(int a) { strength = a; }
int Opponent::getDefense() { return defense; }
void Opponent::setDefense(int d) { defense = d; }
int Opponent::getLuck() { return luck; }
void Opponent::setLuck(int lu) { luck = lu; }
int Opponent::getStamina() { return stamina; }
void Opponent::setStamina(int s) { stamina = s; }

Opponent::~Opponent() { //deletes Action object
    delete AIact;
}

void Opponent::statRandomizer() {
    
    int points = 60; //AI pool of points
    int temp;
    if (getLevel() == 1) { //Based off of user level choosen
        points = 60;
        setHealth(100);
        setStamina(100);
        

        temp = (rand() % points) + 1;
        points -= temp;
        setStrength(temp); 

        temp = (rand() % points) + 1;
        points -= temp;
        setDefense(temp);

        temp = (rand() % points) + 1;
        points -= temp;
        setLuck(temp);
    }
    else if (getLevel() == 2) {
        points = 80;
        setHealth(125);
        setStamina(125);
        

        temp = (rand() % points) + 10;
        points -= temp;
        setStrength(temp); 

        temp = (rand() % points) + 10;
        points -= temp;
        setDefense(temp);

        temp = (rand() % points) + 10;
        points -= temp;
        setLuck(temp);

    }
    else if (getLevel() == 3) {
        points = 120;
        setHealth(150);
        setStamina(150);
        

        temp = (rand() % points) + 1;
        points -= temp;
        setStrength(temp); //1 to 20 random Easy

        temp = (rand() % points) + 1;
        points -= temp;
        setDefense(temp);

        temp = (rand() % points) + 1;
        points -= temp;
        setLuck(temp);
       

    }
    
    
}


void Opponent::attackUser(Opponent& AI, GummyFighter& user, int option) { //Calls attackUser in Action class
    AIact->attackUser(AI, user, option);
}
void Opponent::actionRandomizer(Opponent& AI, GummyFighter& user) { //calls actionRandomizer in Action class
    AIact->actionRandomizer(AI, user);
}
void Opponent::AIstats(Opponent& AI) { //displays opponent stats during battle
    cout << "Opponent Health: " << AI.getHealth() << endl;
    cout << "Opponent Stamina: " << AI.getStamina();
    cout << "\n";
}
void Opponent::fullStats(Opponent& AI) { //Opponent stats before battle
    cout << "Opponent name: " << AI.getName() << endl;
    cout << "Opponent Health: " << AI.getHealth() << endl;
    cout << "Opponent Stamina: " << AI.getStamina() << endl;
    cout << "Opponent Strength: " << AI.getStrength() << endl;
    cout << "Opponent Defense: " << AI.getDefense() << endl;
    cout << "Opponent Luck: " << AI.getLuck() << endl;
    cout << "Opponent ID : " << AI.getID() << endl;
}
bool AIluckChance(Opponent& AI) {
    int lucky = (rand() % AI.getLuck() + 1);
    if (lucky == 69) {
        return true;

    }
    return false;

} //AI luck

//----------------------------------------------------------------------------------Action-------------------------------------------------------------------------------------------------------

Action::Action() {} //default cons

void Action::attackOpponent(Opponent& AI, GummyFighter& user, int option) { // User Attacks Opponent, get a option = moveset
    int realdamage = 0;
    
    switch (option) {
    case 1:
        
        if (user.getStamina() < 30) { //so the game does not go for ever
            cout << "Not enough stamina" << endl;  //should it send the user to defend;
            cout << "\n";
            break;
        }
        realdamage = calculateDamage(roundkick(), user, AI);
        
        AI.setHealth(AI.getHealth() - realdamage);
        
        user.setStamina(user.getStamina() - 30);
        break;
    case 2:
        if (user.getStamina() < 5) { //so the game does not go for ever
            cout << "Not enough stamina" << endl;
            cout << "\n";
            break;
        }
        realdamage = calculateDamage(jab(), user, AI);
        AI.setHealth(AI.getHealth() - realdamage);
        user.setStamina(user.getStamina() - 5);
        break;

    case 3:
        if (user.getStamina() < 15) { //so the game does not go for ever
            cout << "Not enough stamina" << endl;
            cout << "\n";
            break;
        }
        realdamage = calculateDamage(uppercut(), user, AI);
        AI.setHealth(AI.getHealth() - realdamage);
        user.setStamina(user.getStamina() - 15);
        break;
    case 4:
        if (user.getStamina() < 40) { //so the game does not go for ever
            cout << "Not enough stamina" << endl;
            cout << "\n";
            break;
        }
        realdamage = calculateDamage(takedown(), user, AI);
        AI.setHealth(AI.getHealth() - realdamage);
        user.setStamina(user.getStamina() - 40);
        break;
    case 5:
        if (user.getStamina() < 20) { //so the game does not go for ever
            cout << "Not enough stamina" << endl;
            cout << "\n";
            break;
        }
        realdamage = calculateDamage(kick(), user, AI);
        AI.setHealth(AI.getHealth() - realdamage);
        user.setStamina(user.getStamina() - 20);
        break;
    case 6:
        if (user.getStamina() < 30) { //so the game does not go for ever
            cout << "Not enough stamina" << endl;
            cout << "\n";
            break;
        }
        realdamage = calculateDamage(knee(), user, AI);
        AI.setHealth(AI.getHealth() - realdamage);
        user.setStamina(user.getStamina() - 20);
        break;
    }
    
    return;

}

void Action::attackUser(Opponent& AI, GummyFighter& user, int option) { //Opponent Attacks User
    int realdamage = 0;
    
    switch (option) {
    case 1:
        if (AI.getStamina() < 30) { //so the game does not go for ever
            cout << "AI defends..." << endl;  //should it send the user to defend;
            AIdefend(AI);
            break;
        }
        cout << "AI sends a Roundkick..." << endl;
        realdamage = calculateDamage(roundkick(), user, AI);
        user.setHealth(user.getHealth() - realdamage);
        AI.setStamina(AI.getStamina() - 30); //Stamina is something you use up, but can get back by defending at the cost of your health
        break;
    case 2:
        if (AI.getStamina() < 5) { //so the game does not go for ever
            cout << "AI defends..." << endl;  //should it send the user to defend;
            AIdefend(AI);
            break;
        }
        cout << "AI sends a Jab..." << endl;
        realdamage = calculateDamage(jab(), user, AI);
        user.setHealth(user.getHealth() - realdamage);
        AI.setStamina(AI.getStamina() - 5); //Stamina is something you use up, but can get back by defending at the cost of your health
        break;

    case 3:
        if (AI.getStamina() < 15) { //so the game does not go for ever
            cout << "AI defends..." << endl;  //should it send the user to defend;
            AIdefend(AI);
            break;
        }
        cout << "AI sends a Uppercut..." << endl;
        realdamage = calculateDamage(uppercut(), user, AI);
        user.setHealth(user.getHealth() - realdamage);
        AI.setStamina(AI.getStamina() - 15); //Stamina is something you use up, but can get back by defending at the cost of your health
        break;
    case 4:
        if (AI.getStamina() < 40) { //so the game does not go for ever
            cout << "AI defends..." << endl;  //should it send the user to defend;
            AIdefend(AI);
            break;
        }
        cout << "AI sends a Takedown..." << endl;
        realdamage = calculateDamage(takedown(), user, AI);
        user.setHealth(user.getHealth() - realdamage);
        AI.setStamina(AI.getStamina() - 40); //Stamina is something you use up, but can get back by defending at the cost of your health
        break;
    case 5:
        if (AI.getStamina() < 20) { //so the game does not go for ever
            cout << "AI defends..." << endl;  //should it send the user to defend;
            AIdefend(AI);
            break;
        }
        cout << "AI sends a Kick..." << endl;
        realdamage = calculateDamage(kick(), user, AI);
        user.setHealth(user.getHealth() - realdamage);
        AI.setStamina(AI.getStamina() - 20); //Stamina is something you use up, but can get back by defending at the cost of your health
        break;
    case 6:
        if (AI.getStamina() < 30) { //so the game does not go for ever
            cout << "AI defends..." << endl;  //should it send the user to defend;
            AIdefend(AI);
            break;
        }
        cout << "AI sends a Knee..." << endl;
        realdamage = calculateDamage(knee(), user, AI);
        user.setHealth(user.getHealth() - realdamage);
        AI.setStamina(AI.getStamina() - 30); //Stamina is something you use up, but can get back by defending at the cost of your health
        break;
    }
    
    return;
}

void Action::defend(GummyFighter& user) { //User defends
    user.setStamina(user.getStamina() + 50);
    return;
}

void Action::AIdefend(Opponent& AI) { //Opponent defends
    AI.setStamina(AI.getStamina() + 50);
    cout << "AI defends..." << endl;
    return;
}

int Action::train(GummyFighter& user) { //User Trains
    int training = (rand() % 20) + 1; //based off of random
    int stat = (rand() % 5) + 1;
    if (stat == 1) { 
        user.setHealth(user.getHealth() + training);
    }
    else if (stat == 2) {
        user.setStrength(user.getStrength() + training);
    }
    else if (stat == 3) {
        user.setDefense(user.getDefense() + training);
    }
    else if (stat == 4) {
        user.setLuck(user.getLuck() + training);
    }
    else if (stat == 5) {
        user.setStamina(user.getStamina() + training);
    }

    return stat;
}



int Action::roundkick() { //moveset methods
    damage = 50;
    return damage;
}
int Action::jab() {
    damage = 10;
    return damage;
}
int Action::uppercut() {
    damage = 15;
    return damage;
}
int Action::takedown() {
    damage = 40;
    return damage;
}
int Action::kick() {
    damage = 20;
    return damage;
}
int Action::knee() {
    damage = 30;
    return damage;
}



void Action::actionRandomizer(Opponent& AI, GummyFighter& user) { //AI action random either attack or defend
    int action = (rand() % 2) + 1;
    if (action == 1) {
        int AIaction = (rand() % 6) + 1;
        attackUser(AI, user, AIaction);
    }
    else if (action == 2) {
        AIdefend(AI);
    }
    return;

}

int Action::calculateDamage(int movedam, GummyFighter& user, Opponent& AI) { //calculate damage given to Oppoenet based off of user strength and AI defense
    
    if (user.getStrength() <= 20) {
        
        
        if (AI.getDefense() <= 20) {
            movedam -= 1;
        }
        else if (AI.getDefense() > 20 && 60 > AI.getDefense()) {
            movedam -= 4;
        }
        else if (60 > AI.getDefense()) {
            movedam -= 5;
        }
        

    }

    else if (user.getStrength() > 20 && user.getStrength() < 60) {
        
        
        if (AI.getDefense() <= 20) {
            movedam -= 1;
        }
        else if (AI.getDefense() > 20 && 60 > AI.getDefense()) {
            movedam -= 5;
        }
        else if (60 > AI.getDefense()) {
            movedam -= 6;
        }
        

    }

    else if (user.getStrength() > 60) {
        
        
        if (AI.getDefense() <= 20) {
            
            movedam -= 0;
        }
        else if (AI.getDefense() > 20 && 60 > AI.getDefense()) {
            
            movedam -= 10;
        }
        else if (60 > AI.getDefense()) {
            
            movedam -= 8;
        }
        

    }
    
    if (user.luckChance(user) == true) { //Luck
         movedam *= 2;
    }

    return movedam;
}

int Action::calculateAIDamage(int movedam, GummyFighter& user, Opponent& AI) { //Check if Logic makes sense
    if (AI.getStrength() <= 20) {

        if (user.getDefense() <= 20) {
            movedam -= 1;
        }
        else if (user.getDefense() > 20 && 60 > user.getDefense()) {
            movedam -= 4;
        }
        else if (60 > user.getDefense()) {
            movedam -= 5;
        }
        
    }

    else if (AI.getStrength() > 20 && AI.getStrength() < 60) {

        if (user.getDefense() <= 20) {
            movedam -= 1;
        }
        else if (user.getDefense() > 20 && 60 > user.getDefense()) {
            movedam -= 5;
        }
        else if (60 > user.getDefense()) {
            movedam -= 6;
        }
        

    }

    else if (AI.getStrength() > 60) {

        if (user.getDefense() <= 20) {
            movedam -= 0;
        }
        else if (user.getDefense() > 20 && 60 > user.getDefense()) {
            movedam -= 10;
        }
        else if (60 > user.getDefense()) {
            movedam -= 8;
        }
        

    }
    if (AI.luckChance(AI) == true) { //Luck
        movedam *= 2;
    }

    return movedam;
}

//----------------------------------------------------------------------------------Main-------------------------------------------------------------------------------------------------------

void saveToFile(string& filename, GummyFighter& user) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << user.getName() << endl;
        outFile << user.getLevel() << endl;
        outFile << user.getHealth() << endl;
        outFile << user.getStrength() << endl;
        outFile << user.getDefense() << endl;
        outFile << user.getLuck() << endl;
        outFile << user.getID() << endl;
        outFile << user.getStamina() << endl;
        outFile.close();
        cout << "Data saved successfully." << endl;
    }
    else {
        cerr << "Unable to open file for saving." << endl;
         
    }
}

void loadFromFile(GummyFighter& user) {
    cout << "What is the file name?" << endl;
    string filename;
    cin >> filename;
    filename += ".txt";
    ifstream inFile(filename);

    if (inFile.is_open()) {
        string name;
        int level, health, strength, defense, luck, id, stamina;
        getline(inFile, name);
        inFile >> level >> health >> strength >> defense >> luck >> id >> stamina;

        user.setName(name);
        user.setLevel(level);
        user.setHealth(health);
        user.setStrength(strength);
        user.setDefense(defense);
        user.setLuck(luck);
        user.setID(id);
        user.setStamina(stamina);

        inFile.close();
        cout << "Data loaded successfully." << endl;
    }
    else {
        cerr << "Unable to open file for loading." << endl;
        loadFromFile(user);
    }
}
void UserFighter(GummyFighter& user) { //To create user character
    int stren = 0;
    int def = 0;
    int luc = 0;
    int poolp = 0; // Total available stat credits
    if (user.getLevel() == 1) {
        poolp = 120;
        user.setHealth(120);
        user.setStamina(120);
    }
    else if (user.getLevel() == 2) {
        poolp = 100;
        user.setHealth(120);
        user.setStamina(120);
    }
    else if (user.getLevel() == 3) {
        poolp = 60;
        user.setHealth(100);
        user.setStamina(100);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    cout << "You have: " << poolp << " stat credits to build your fighter's strength, defense, and luck." << endl;

    // Input for strength
    cout << "How many stat credits for strength?" << endl;
    cin >> stren;
    while (stren < 0 || stren > poolp) { // Validate input
        cout << "Invalid input. Please enter a number between 0 and " << poolp << ": ";
        cin >> stren;
    }
    user.setStrength(stren + 1);
    poolp -= stren;

    system("cls");

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // Input for defense
    cout << "You have: " << poolp << " stat credits left. How many stat credits for defense?" << endl;
    cin >> def;
    while (def < 0 || def > poolp) { // Validate input
        cout << "Invalid input. Please enter a number between 0 and " << poolp << ": ";
        cin >> def;
    }
    user.setDefense(def + 1);
    poolp -= def;
    system("cls");

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // Input for luck
    cout << "You have: " << poolp << " stat credits left. How many stat credits for luck?" << endl;
    cin >> luc;
    while (luc < 0 || luc > poolp) { // Validate input
        cout << "Invalid input. Please enter a number between 0 and " << poolp << ": ";
        cin >> luc;
    }
    user.setLuck(luc + 1);
    poolp -= luc;

    system("cls");

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // Set default values for health and stamina


    // Display created fighter
    user.viewCreated(user);

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));


}








int main()
{
    // Create User bear//
    int dif;
    string nombre;
    int choice = 0;
    int game;
    int attackc;
    int maxh;
    int maxs;
    string filename;
    int stattrained = 0;
    
    vector<string> namess = { "Alice", "Bob", "Charlie", "David", "Emma", "Frank", "Grace", "Henry", "Ivy", "Jack" }; //Names for AI
    int opnamenum = (rand() % 10 + 0);
    string opname = namess.at(opnamenum);//randomly choose a name
    
    GummyFighter user; //objects for User and Opponent
    Opponent AI;
    
    cout << "Welcome to..." << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //from ascii art archive text to art
    cout << R"(
   ____ _   _ __  __ __  ____   __  _____ ___ ____ _   _ _____ _____ ____  
  / ___| | | |  \/  |  \/  \ \ / / |  ___|_ _/ ___| | | |_   _| ____|  _ \ 
 | |  _| | | | |\/| | |\/| |\ V /  | |_   | | |  _| |_| | | | |  _| | |_) |
 | |_| | |_| | |  | | |  | | | |   |  _|  | | |_| |  _  | | | | |___|  _ < 
  \____|\___/|_|__|_|_| _|_| |_|   |_|   |___\____|_| |_| |_| |_____|_| \_\
)" << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << R"(
              / ___| | | |  / \  |  \/  |  _ \_ _/ _ \| \ | |              
             | |   | |_| | / _ \ | |\/| | |_) | | | | |  \| |              
             | |___|  _  |/ ___ \| |  | |  __/| | |_| | |\  |              
              \____|_| |_/_/   \_\_|  |_|_|  |___\___/|_| \_|              
    )" << endl;
  
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    cout << "\n";
    cout << "(1) New Game" << endl;
    cout << "(2) Load Game" << endl;
    cin >> game;
    cin.clear();

    if (game == 1) { //Creates User GummyFighter


        //Game startup will display a load and a play option ---> chooses difficulty again
        cout << "Name your Gummy Fighter (No Spaces):" << endl;



        cin >> nombre;
        
        user.setName(nombre);
        //Set difficulty				//should user be able to change difficulty, maybe ti requires to exit game
        cout << "Choose difficulty: " << endl;
        cout << "(1) : Easy" << endl;
        cout << "(2) : Medium" << endl;
        cout << "(3) : Hard" << endl;

        cin >> dif;
        user.setLevel(dif);
        cin.clear();
        system("cls");

        //create a random uniqueID here
        int ID = 0;
        user.setID(ID++);

        //should health and stamina be set to both 0
        AI.setName(opname);
        AI.setLevel(user.getLevel());
        AI.setID(1738);
        AI.statRandomizer();
           //should there be opponent object passed here
        
        cout << "Create your stats: " << endl;
        UserFighter(user);
        
        
    }

    else if(game == 2){ //Loads User Gummy Fighter
        
        
        loadFromFile(user);
        cout << "\n";
        user.viewCreated(user);
        cout << "\n";
        AI.setName(opname);
        AI.setLevel(user.getLevel());
        AI.setID(1738);
        AI.statRandomizer();
    
    }

    if (nombre == "FettyWap") { //Give max Stats if User Name is FettyWap
        cout << "\n";
        cout << "Hi FettyWap, You are the GOAT!" << endl;
        user.cheater(user);
        user.viewCreated(user);
    }

    maxh = user.getHealth(); //saves health and stamina in order to reset after battle
    maxs = user.getStamina();

    
    bool toContinue = true;
    int ca = 0;
    cout << "\n";
    cout << "\n";
    cout << "Your Opponent: " << endl; //displays who you are fighting
    AI.fullStats(AI);
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    
    while (toContinue) { //Game Loop
        cout << "\n";
        cout << "Menu: " << endl; 
        cout << "(1) Battle an Opponent " << endl;
        cout << "(2) Train " << endl;
        cout << "(3) Change Difficulty " << endl;
        cout << "(4) Save " << endl;
        cout << "(5) Exit " << endl; //in train is more you could change difficulty or keep same opponent

        
        cin >> choice;
        cin.ignore();
        system("cls");
        
        
       

        switch (choice) { 
            case 1: //battle loop -> attack or defend
                while (user.getHealth() > 0 && AI.getHealth() > 0) {


                    cout << "(1) Attack or (2) Defend?" << endl;
                    cin >> ca;
                    system("cls");
                    if (ca == 1) {
                        cout << "User Stamina: " << user.getStamina() << endl;
                        cout << "\n";
                        cout << "Chooses an Attack: " << endl;
                        cout << "(1) Roundkick: Cost = 30 " << endl;
                        cout << "(2) Jab: Cost = 5 " << endl;
                        cout << "(3) Uppercut: Cost = 15 " << endl;
                        cout << "(4) Takedown: Cost = 40 " << endl;
                        cout << "(5) Kick: Cost = 20" << endl;
                        cout << "(6) Knee: Cost = 30" << endl;

                        cin >> attackc;
                        system("cls");
                        user.attackOp(AI, user, attackc);




                        cin.clear();
                        // cout the opponents stats after attack
                        AI.AIstats(AI);

                        std::this_thread::sleep_for(std::chrono::milliseconds(3000));

                        if (AI.getHealth() > 0) {
                            cout << "\n";
                            cout << "Opponents turn..." << endl;
                            cout << "\n";
                            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                            AI.actionRandomizer(AI, user);
                            cout << "\n";
                            user.displayStats(user);
                            //cout the user stats
                        }
                        
                        
                    }

                    else if (ca == 2) {
                        cout << "Current Stamina increased..." << endl;
                        user.deff(user);
                        cout << "Current Stamina: " << user.getStamina() << endl;
                        cout << "Opponents turn..." << endl;
                        AI.actionRandomizer(AI, user); //make method actionRandomizer in Opponent
                        
                        
                        
                    }

                   
                }
                cout << "\n";

                if (user.getHealth() > 0) {
                    cout << user.getName() << " Wins" << endl;
                }
                else if (AI.getHealth() > 0) {
                    cout << AI.getName() << " Wins" << endl;
                }
                
                cout << "\n";
            

                break;


            case 2: // train // reset health and stamina here or right after the battle I suppose
                
                cout << "Training..." << endl;
            
                stattrained = user.trainn(user);
                if (stattrained == 1) {
                    cout << "You trained health..." << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    cout << "Health: " << user.getHealth() << endl;
                    maxh = user.getHealth();
                    continue;
                }
                if (stattrained == 2) {
                    cout << "You trained strength..." << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    cout << "Strength: " << user.getStrength() << endl;
                    continue;
                }
                if (stattrained == 3) {
                    cout << "You trained defense..." << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    cout << "Defense: " << user.getDefense() << endl;
                    continue;
                }
                if (stattrained == 4) {
                    cout << "You trained luck..." << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    cout << "Luck: " << user.getLuck() << endl;
                    continue;
                }
                if (stattrained == 5) {
                    cout << "You trained stamina..." << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                    cout << "Stamina: " << user.getStamina() << endl;
                    maxs = user.getStamina();
                    continue;
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                system("cls");
                continue;
 
            
            case 3: //change difficulty
                cout << "Choose difficulty: " << endl;
                cout << "(1) : Easy" << endl;
                cout << "(2) : Medium" << endl;
                cout << "(3) : Hard" << endl;
                cin >> dif;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                
                if (dif == 1) {
                    user.setLevel(1);
                    cout << "Difficulty changed to Easy " << endl;
                }
                else if (dif == 2) {
                    user.setLevel(2);
                    cout << "Difficulty changed to Medium " << endl;
                }
                else if (dif == 3) {
                    user.setLevel(3);
                    cout << "Difficulty changed to Hard " << endl;
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                system("cls");
                break;

            case 4: //save
                cout << "Please enter a filename: " << endl;
                cin >> filename;
                filename += ".txt";
                saveToFile(filename, user);
                system("cls");
                break;

            case 5: //exit
                cout << "Thanks for playing!" << endl;

                toContinue = false;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;


        }
        if (choice == 5) {
            break;
        }
        AI.setName(opname); //resets after a battle or train
        AI.setLevel(user.getLevel());
        AI.setID(1738);
        AI.statRandomizer();

        user.setHealth(maxh); //reset after train
        user.setStamina(maxs);

        cout << "New Opponent: " << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        cout << "\n";
        AI.fullStats(AI);
        

    }

   




    return 0;

}

