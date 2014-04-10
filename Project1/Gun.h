#include "Item.h"

class Gun : public Item
{
public:
	Gun();
	Gun(int x);

private:

	int m_Damage;
	int m_Accuracy;
	int m_Range;
	int m_Recoil;
	int m_FireType;
};

Gun::Gun()
{
}

