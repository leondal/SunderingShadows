//      /bin/dev/_localcmds.c
//      from the Nightmare Mudlib
//      a command to check what commands are now available
//      created by Plura@Nightmare 9301??

#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_localcmds() {
    mixed *cmds;
    object ob;
    string result;
    int i, tmp;

    seteuid(UID_USERACCESS);
    catch(cmds = (mixed *)this_player()->local_commands());
    seteuid(getuid());
    if(!cmds || !sizeof(cmds)) {
        notify_fail("No commands available.\n");
        return 0;
   }
   result = file_name(cmds[0][2]) + ":\n";
   while(i<sizeof(cmds))
   {
      result += cmds[i][0] + " ";
      if((i++<(sizeof(cmds)-1)) && cmds[i-1][2] != cmds[i][2])
         result += "\n\n" + file_name(cmds[i][2]) + ":\n";
   }
    write(wrap(result, (tmp=(string)this_player()->getenv("LINES") ?
      atoi(tmp) : 75))+"\n");
   return 1;
}

int help()
{
  write( @EndText
Syntax: localcmd
Effect: Lists all commands added to you by objects
See also: from
EndText
  );
  return 1;
}
