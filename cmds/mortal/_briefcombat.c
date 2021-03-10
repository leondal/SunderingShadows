/*
// The "brief" command.
// toggle your verbosity.
// Part of the TMI mudlib, of course!
// Written by Buddha(2-19-92)
*/

#include <std.h>

inherit DAEMON;

int cmd_briefcombat() {
   this_player()->set_brief_combat();
   if(this_player()->query_verbose_combat()) write("Verbose combat mode.\n");
   else write("Brief combat mode.\n");
   return 1;
}

void help()
{
  write( "
%^CYAN%^NAME%^RESET%^

briefcombat - toggle briefcombat mode

%^CYAN%^DESCRIPTION%^RESET%^

Toggles you between brief combat and verbose combat modes. In brief combat mode you get shorter combat descriptions.

%^CYAN%^SEE ALSO%^RESET%^

look, lines, set, brief
"
  );
}
