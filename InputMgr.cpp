#include <algorithm>
#include <iostream>
#include "InputMgr.h"


std::vector<bool> InputMgr::downKeys(sf::Keyboard::KeyCount, false);
std::vector<bool> InputMgr::heldKeys(sf::Keyboard::KeyCount, false);
std::vector<bool> InputMgr::upKeys(sf::Keyboard::KeyCount, false);

void InputMgr::Init()
{

}
void InputMgr::Clear()
{
	for (int i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		downKeys[i] = false;
		upKeys[i] = false;
	}
}

void InputMgr::UpdateEvent(const sf::Event& ev)
{
	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		if (!heldKeys[ev.key.code])
		{
			downKeys[ev.key.code] = true;
			heldKeys[ev.key.code] = true;
		}
		break;

	case sf::Event::KeyReleased:
		heldKeys[ev.key.code] = false;
		upKeys[ev.key.code] = true;
		break;
	}
}
void InputMgr::Update(float dt)
{}

bool InputMgr::GetKeyDown(sf::Keyboard::Key key)
{
	return downKeys[key];
}
bool InputMgr::GetKeyUp(sf::Keyboard::Key key)
{
	return upKeys[key];
}
bool InputMgr::GetKey(sf::Keyboard::Key key)
{
	return heldKeys[key];
}