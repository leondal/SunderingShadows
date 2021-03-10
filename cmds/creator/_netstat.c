//	/bin/dev/_netstat.c
//	Command for checking network sockets
//	coded by Descartes of Borg 23 Nov 1992

#include <std.h>
inherit DAEMON;

int cmd_netstat() { dump_socket_status(); return 1; }

int help()
{
  write( @EndText
Syntax: netstat
Effect: Lists the status of the mud's internet sockets.
See man: dump_socket_status
See also: mstatus, cache, callouts, dumpallobj, opcprof, fdinfo
EndText
  );
  return 1;
}
