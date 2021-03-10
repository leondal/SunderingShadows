//      /bin/dev/_vis.c
//      from the Nightmare mudlib
//      created by Descartes of Borg october 1992

#include <std.h>

inherit DAEMON;

varargs int cmd_vis(string str)
{
   if(!this_player()->query_invis()) {
	notify_fail("You are already visible.\n");
	return 0;
    }
    this_player()->set_invis();
   return 1;
}


int help()
{
  write( @EndText
Syntax: vis
Effect: Makes you visible if you wern't already.
EndText
  );
  return 1;
}
