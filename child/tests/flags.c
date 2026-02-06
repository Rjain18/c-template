#include "flags.h"

int
main ()
{
	char *args[] = { "./flags", "-flags-", "-h", "-v" };
	initFlags (3, args);
	const Flags *flags = getFlags();
	if (flags->flagName)
		return 1;
	args[1] = "--flagName";
	initFlags (3, args);
	if (flags->flagName)
		return 1;
	return 0;
}
