#pragma once
#ifndef LANDS_H
#define LANDS_H

#include <string>
#include <stdlib.h>
#include "player.h"

using namespace std;

enum LandTypes {LAKE, FOREST, DESERT, PLAINS, RIVER, BEACH, TAIGA, TUNDRA, MAX_NUM_LANDS};

// Template Class
class Land 
{
    public:
    virtual string getShortDescription() = 0;
    virtual string getLongDescription() = 0;
    virtual string visit(Player &p) = 0;
    
    private:
};

// Begin derived classes
class Lake : public Land 
{
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
};

class Forest : public Land 
{
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
};

class Desert : public Land 
{
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
};

class Plains : public Land 
{
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
};

class River : public Land 
{
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
};

class Beach : public Land 
{
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
};

class Taiga : public Land 
{
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
};

class Tundra : public Land 
{
    public:
    string getShortDescription();
    string getLongDescription();
    string visit(Player &p);
    
    private:
};





Land* getRandomLand(void);


#endif