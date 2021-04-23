#include "lands.h"

using namespace std;

Land* getRandomLand()
{
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);
    
    switch(selection)
    {
        case LAKE:
            return new Lake;
            break;
        case FOREST:
            return new Forest;
            break;
        case DESERT:
            return new Desert;
            break;
        case PLAINS:
            return new Plains;
            break;
        case RIVER:
            return new River;
            break;
        case BEACH:
            return new Beach;
            break;
        case TAIGA:
            return new Taiga;
            break;
        case TUNDRA:
            return new Tundra;
            break;
        default:
            return new Lake;
            break;
    }
}

string Lake::getShortDescription()
{
    return "Lake";
}

string Lake::getLongDescription()
{
    return "You arrive at a large lake filled with clear sparkling water.";
}

string Lake::visit(Player& p)
{
    string description = "You drink from the lake, replenishing your thirst";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
}

string Forest::getShortDescription()
{
    
    return "Forest";
}

string Forest::getLongDescription()
{
    return "You arrive in dense forest filled with trees and foliage.";
}

string Forest::visit(Player& p)
{
    string description = "You forage for berries but find nothing.";
    
    int chance = rand() % 100;
    
    // Chance to find berries
    if(chance > 50)
    {
        description = "You foraged for berries in the forest and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance to get mauled by bear
    if(chance < 10 && chance > 5)
    {
        description = "You are attacked by a hungry bear in the woods!";
        p.setHealth(p.getHealth() - 1);
    }
    
    // Chance to get double mauled
    if(chance < 5)
    {
        description = "You are attacked by two very large bears!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    
    
    return description;
}

// Desert
string Desert::getShortDescription()
{
    
    return "desert";
}

string Desert::getLongDescription()
{
    return "You arrive in an extremely hot, dry desert";
}

string Desert::visit(Player& p)
{
    string description = "The heat of the desert makes you dehydrated.";
    
    p.setThirst(p.getThirst() - 1);

    return description;
}

// Plains
string Plains::getShortDescription()
{
    
    return "plains";
}

string Plains::getLongDescription()
{
    return "You arrive in a wide open plain with tall grasses as far as the eye can see.";
}

string Plains::visit(Player& p)
{
    string description = "You fail to find any water...";
    
    int chance = rand() % 100;
    
    // Chance to find food
    if(chance > 50)
    {
        description = "You spot a pheasant darting through the grass and successfully catch it!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance to get mauled by bear
    if(chance < 10 && chance > 5)
    {
        description = "You are attacked by a hungry grizzly bear after the same pheasant as you!";
        p.setHealth(p.getHealth() - 2);
    }
    
    // Chance to get double mauled
    if(chance < 5)
    {
        description = "You are attacked by a pack of wolves!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }

    return description;
}

// River
string River::getShortDescription()
{
    
    return "River";
}

string River::getLongDescription()
{
    return "You arrive at the bank of a wide river";
}

string River::visit(Player& p)
{
    string description = "You explore up and down the bank.";
    
    int chance = rand() % 100;
    
    // Chance to find food
    if(chance > 50)
    {
        description = "You catch a rather large river trout.";
        p.setHunger(p.getHunger() + 2);
        return description;
    }
    
    // Chance to find a small village
    if(chance < 10 && chance > 5)
    {
        description = "You find a small village on the bank of the river. You get a full night's rest at the inn.";
        p.setHealth(p.getHealth() + 1);
    }
    
    // Chance to get attacked by small black bear
    if(chance < 5)
    {
        description = "You are attacked by a small black bear protecting her cubs!";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    
    
    return description;
}


// Beach
string Beach::getShortDescription()
{
    
    return "beach";
}

string Beach::getLongDescription()
{
    return "You arrive on the shore of a vast warm ocean.";
}

string Beach::visit(Player& p)
{
    string description = "The water is too salty to drink.";
    
    int chance = rand() % 100;
    
    // Chance to find food
    if (chance > 50)
    {
        description = "You spend all day fishing, and finally snag a rather small grouper!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance of getting bitten by a shark
    if (chance < 25)
    {
        description = "You wade out into the water to catch a fish, but instead bitten by a small shark!";
        p.setHealth(p.getHealth() - 2);
        
    }
    return description;
}

    


// Taiga
string Taiga::getShortDescription()
{
    return "taiga";
}

string Taiga::getLongDescription()
{
    return "You arrive at a snowy forest filled with tall pine trees.";
}
string Taiga::visit(Player& p)
{
    string description = "You explore the area but get cold quickly.";
    
    int chance = rand() % 100;
    
    // Chance to find a village
    
    if (chance >= 55)
    {
        description = "You find a small village nestled among the pine trees and are given a warm place to sleep for the night and a warm meal.";
        p.setHunger(p.getHunger() + 1);
        p.setHealth(p.getHealth() + 1);
        return description;
    }
    if (chance < 55)
    {
        description = "You are unabled to find anything more than a small cave to spend the night in. You wake up hungry and thirsty.";
        p.setHunger(p.getHunger() - 1);
        p.setThirst(p.getThirst() - 1);
        return description;
    }
}



// Tundra
string Tundra::getShortDescription()
{
    
    return "tundra";
}

string Tundra::getLongDescription()
{
    return "You arrive in an extremely cold and desolate stretch of tundra.";
}

string Tundra::visit(Player& p)
{
    string description = "The lack of water and food make you weak.";
    
    p.setThirst(p.getThirst() - 1);
    p.setHunger(p.getHunger() - 1);
    p.setHealth(p.getHealth() -1);

    return description;
}
