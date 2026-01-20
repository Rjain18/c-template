#include "flags.h"

static char *args[] = { "./flags", "-flags-", "-h", "-v" };

int
main ()
{
	initFlags (3, args);

	if (isFlagName ())
		return 1;
	return 0;
}
