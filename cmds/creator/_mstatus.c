#include <std.h>

inherit DAEMON;

int
cmd_mstatus(string arg)
{
	int flag, memory;

	flag = !!arg;
	mud_status(flag);
	memory = memory_info() / 512;
	write(" Total memory in K Byes: " + memory + "K");
        write(" Total memory used in Megabytes: " + memory = (memory / 1024 ) + "Megs");
        write(" Reboot Limit (Megabytes): " + "adm/daemon/shutdown_d"->query_max_memory() + " Megs");
	return 1;
}

int help()
{
  write( @EndText
Syntax: mstatus [<arg>]
Effect: Give you statistics on the driver and mudlib
If the optional argument is given, you also get:
  add_message statistics
  Hash table of living objects
  Function cache information
  Heart beat information
  Shared string hash table
  Call out information
  Object name hash table status
See man: mud_status
See also: netstat, fdinfo, cache, callouts, dumpallobj, opcprof
EndText
  );
  return 1;
}
