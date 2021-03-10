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
