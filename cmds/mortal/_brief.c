/*
// The "brief" command.
// toggle your verbosity.
// Part of the TMI mudlib, of course!
// Written by Buddha(2-19-92)
*/

#include <std.h>

inherit DAEMON;

int cmd_brief() {
   this_player()->set_brief();
   if(this_player()->query_verbose()) write("Verbose mode.\n");
   else write("Brief mode.\n");
   return 1;
}

void help()
{
  write( "
%^CYAN%^NAME%^RESET%^

brief - toggle brief mode

%^CYAN%^DESCRIPTION%^RESET%^

Toggles you between brief and verbose modes. In brief mode you get shorter room descriptions on entering them. Useful when going through a lot of well known rooms fast

%^CYAN%^SEE ALSO%^RESET%^

look, lines, set
"
  );
}
