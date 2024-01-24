#pragma once
#include "Weapon.h"
class Pistol :
    public Weapon
{
public:
	Pistol(int rounds, int magCap, int range, int damage) : 
		Weapon(range, damage)
	{	
		MagCapacity(magCap);
		Rounds(rounds);
	}

	int Rounds() { return rounds_; }
	void Rounds(int rounds) {
		if (rounds >= 0 && rounds <= magCapacity_)
			rounds_ = rounds;
	}

	int MagCapacity() {
		return magCapacity_;
	}
	void MagCapacity(int magCap) {
		if (magCap >= 1 && magCap <= 32)
			magCapacity_ = magCap;
	}

private:
	int rounds_, magCapacity_;
};

