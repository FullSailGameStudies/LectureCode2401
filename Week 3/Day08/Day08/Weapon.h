#pragma once
class Weapon
{
protected:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	void showMe();
	//int calcDamage();
	int calcDamage(int modifier = 0);

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

