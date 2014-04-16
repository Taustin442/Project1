#include <vector>
#include "Wound.h"
using namespace std;

class Actor
{
public:
	Actor();

private:
	//contants
	int m_Blood;
	vector<Wound> m_Wounds;
};

Actor::Actor()
{
}

