#include "flags.h"

int
main ()
{
	char *args[] = { "./flags", "-flags-", "-h", "-v" };
	initFlags (3, args);
	if (isFlagName ())
		return 1;
	args[1] = "--flagName";
	initFlags (3, args);
	if (!isFlagName ())
		return 1;
	return 0;
}
