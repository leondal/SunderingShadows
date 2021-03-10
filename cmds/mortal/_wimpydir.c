/*
// command: wimpydir
// Sets the direction in which one will flee in.
// Written by Buddha@TMI on 2/16/92
// This file is a part of the TMI distribution mudlib.
// Please retain this header if you use it.
   */

#include <std.h>

inherit DAEMON;

int help();

int cmd_wimpydir(string str) {
   if(!str) {
      write("Wimpydir set to: "+ (string)previous_object()->query_wimpydir() +
         ".\n");
      return 1;
   }
   if(!stringp(str)) {
      help();
      return 1;
   }
   previous_object()->set_wimpydir(str);
   write("Wimpydir now set to "+str+".\n");
   return 1;
}

void help() {
    write(
"
%^CYAN%^NAME%^RESET%^

wimpydir - choose where to run

%^CYAN%^SYNOPSIS%^RESET%^

wimpydir [%^ORANGE%^%^ULINE%^DIRECTION%^RESET%^|retreat]

%^CYAN%^DESCRIPTION%^RESET%^

This command will set the direction you will flee in when in combat.

If the direction isn't set or doesn't work, you will flee in a random direction.

If no direction is specified, it will tell you the current setting.

If 'retreat' is specified it will return you to the previous room if possible.

%^CYAN%^SEE ALSO%^RESET%^

wimpy, flee, kill
"
        );
}

