#pragma once

class Player {
private:
	int hp;
	int dmg;
	int bag_size;
public:
	int show_hp();
	int show_dmg();
	int show_bag();
	Player();
	~Player();
};
