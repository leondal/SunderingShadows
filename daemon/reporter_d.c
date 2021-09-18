//ACTIVELY USED
//Not sure why error() function isn't used instead, though...

// PLEASE DON'T MOVE THIS FILE. IT'S NOT AREA-SPECIFIC. IT'S A GENERAL-USE DEBUGGING TOOL. Lots of my things break if you move it. Ta. Lujke
// Lujke's new code reporter daemon.
//
// This daemon is intended for allowing code to report issues direct to the coder's screen.
// It's really just a work-around for mobs not being able to sell tells to imms

#include <std.h>
#include "/realms/lujke/tecqumin/tecqumin.h"
inherit DAEMON;


void report (string who, string str){
  object ob;
  ob = find_player(who);
  if (objectp(ob)){
    tell_object(ob, "%^BOLD%^%^RED%^Report: "+ str);
  }
}
