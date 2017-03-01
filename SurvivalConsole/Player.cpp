#include <iostream>
#include "Player.h"

Player::Player() {

}

Player::~Player() {

}

int Player::show_hp()
{
	return hp;
}

int Player::show_dmg()
{
	return dmg;
}

int Player::show_bag()
{
	return bag_size;
}
