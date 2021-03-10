/*
// A useful command from the people at Portals.
// I think Huthar wrote this one.
*/

#include <std.h>

inherit DAEMON;

int cmd_gauge(string cmd)
{
   object act_ob;
   int cpu;
   
      act_ob = previous_object();

   if(!cmd) {
      notify_fail("usage: gauge <command>\n");
      return 0;
   }
    seteuid(getuid(previous_object()));
    catch(cpu = (int)act_ob->force_me(cmd));
    seteuid(getuid());
   write("\nThat command took: "+cpu+" CPU cycles.\n");
   return 1;
}

string query_position() { return "admin"; }

int help()
{
  write( @EndText
Syntax: gauge <command>
Effect: Gauges how many CPU cycles <command> takes to execute.
EndText
  );
  return 1;
}
