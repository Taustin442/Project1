#include <conio.h>
#include "Console.h"
int main(void)
{
	console.Clear();
	int nPlayerX = 40, nPlayerY = 12;
	while (true)
	{
		// Output phase
		console.Position(nPlayerX, nPlayerY);
		console << '@';
		// Input phase goes here
		// @@@ TODO @@@

		// Processing phase goes here
		// @@@ TODO @@@
	}
	return 0;
}