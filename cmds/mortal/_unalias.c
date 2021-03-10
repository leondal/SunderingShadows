/*
// The wonderful unalias command.
*/

#include <std.h>

inherit DAEMON;

int cmd_unalias(string str)
{
   object act_ob;
   mapping alias;

   if(!str)
   {
      notify_fail("usage: unalias <alias>\n");
      return 0;
   }

   act_ob = previous_object();
   alias = (mapping)act_ob->query_aliases();

   if(!alias[str])
   {
      write(str+": alias not found.\n");
      return 1;
   }

   write("alias: "+str+" ("+alias[str]+") Removed.\n");
   act_ob->remove_alias(str);
   return 1;
}

int help()
{
   return (int)"/cmds/mortal/_alias"->help();
}
