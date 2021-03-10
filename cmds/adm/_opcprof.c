#include <std.h>


inherit DAEMON;

int
cmd_opcprof(string arg)
{
   if(!archp(previous_object())) return 0;
        opcprof();
	return 1;
}

int help()
{
  write( @EndText
Syntax: opcprof
Effect: Puts a list of efuns and eoperators in /log/dumps/opcprof
See man: opcprof
See also: fdinfo, netstat, mstatus, cache, callouts, dumpallobj,
EndText
  );
  return 1;
}
