#pragma once
#include "../stdafx.h"

class EntityAction
{
public:
	~EntityAction() {}
	virtual void charge() = 0;
	virtual void retreat() = 0;
	virtual void stab() = 0;
};

class AlphaUser : public EntityAction
{
private:
	string _name;
public:
	AlphaUser(string name) : _name(name) {}
	void charge();
	void retreat();
	void stab();
};

class BravoUser : public EntityAction
{
private:
	string _name;
public:
	BravoUser(string name) : _name(name) {}
	void charge();
	void retreat();
	void stab();
};

template <class T>
class Command
{
public:
	virtual ~Command() {};
	virtual void execute(T& action) = 0;
};


class ChargeCommand : public Command<EntityAction>
{
public:
	void execute(EntityAction& action) { action.charge(); }
};
class RetreatCommand : public Command<EntityAction>
{
public:
	void execute(EntityAction& action) { action.retreat(); }
};
class StabCommand : public Command<EntityAction>
{
public:
	void execute(EntityAction& action) { action.stab(); }
};


class InputMap 
{
private:
	map<string, Command<EntityAction>*> _inputList;
public:
	InputMap();
	void handle(string command, EntityAction& actor);
	~InputMap();
};