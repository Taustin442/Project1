#include "Actor.h"

class Human : public Actor{
public:
	Human();

private:
	//attributes
	int m_Strength;
	int m_Agility;
	int m_Dexterity;
	int m_Endurance;
	int m_Perception;
	int m_Charisma;
	int m_Inteligence;
	int m_Willpower;

	//skills
	int m_GunsRifles;
	int m_GunsHandGuns;
	int m_GunsShotgun;
	int m_Archery;
	int m_MovRunning;
	int m_MovSneaking;
	int m_MovSwimming;
};