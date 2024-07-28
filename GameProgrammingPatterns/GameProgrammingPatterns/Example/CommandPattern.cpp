#include "../stdafx.h"

void AlphaUser::charge()
{ 
	cout << _name << " moved forward!" << endl; 
}

void AlphaUser::retreat()
{ 
	cout << _name << " moved backward!" << endl; 
}

void AlphaUser::stab()
{ 
	cout << _name << " did stab forward!" << endl; 
}

void BravoUser::charge()
{ 
	cout << _name << " moved forward!" << endl; 
}

void BravoUser::retreat()
{ 
	cout << _name << " moved backward!" << endl; 
}

void BravoUser::stab()
{ 
	cout << _name << " did stab forward!" << endl; 
}




InputMap::InputMap()
{
	_inputList["charge"] = new ChargeCommand();
	_inputList["retreat"] = new RetreatCommand();
	_inputList["stab"] = new StabCommand();
}


void InputMap::handle(string command, EntityAction& actor)
{
	if (_inputList.find(command) != _inputList.end())
	{
		_inputList[command]->execute(actor);
	}
	else
	{
		cout << "Unknown command!" << endl;
	}
}

InputMap::~InputMap()
{
	for (auto& pair : _inputList)
	{
		delete pair.second;
	}
}