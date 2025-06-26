#pragma once
#include <vector> //순차 컨테이너 find 하려면 처음부터 돌려봐야함
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>

class InputMgr
{
private:
	static std::vector<bool> downKeys;
	static std::vector<bool> heldKeys;
	static std::vector<bool> upKeys;

public:
	static void Init();
	static void Clear();

	static void UpdateEvent(const sf::Event& ev);
	static void Update(float dt);

	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);
};
