//  An attempt at an su command, by Kriton
//  July 26, 1994

#include <std.h>

inherit DAEMON;

int cmd_su(string who)    {
  object old_bod, new_bod;
  int x;

  if(!wizardp(this_player())) return 0;
  if(!who)    {
    write("syntax: su <monster>");
    return 1;
  }
  if(!present(who,environment(this_player())))    {
    write("There is no "+capitalize(who)+" present!");
    return 1;
  }
  new_bod = present(who,environment(this_player()));
  if(interactive(new_bod))   {
    write("You cannot su into a non-interactive body!");
    return 1;
  }
  old_bod = this_player();
  x = exec(new_bod,old_bod);
  if(x == 0)    {
    write("su failed.");
    return 1;
  }
  write("You transfer your soul into "+new_bod->query_short()+"!");
  return 1;
}

void help()    {
write(
@TEXT
Command: su
Syntax:  su <monster name>

'su' allows a wizard to switch into a monster's body and move
around.
TEXT
);
}
