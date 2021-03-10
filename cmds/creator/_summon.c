/*
// Author: Descartes
*/

/* patched by Valodin jan 15,  1993
   ob is forced to look around
   and trash strings are  filtered a little better
*/
// added restriction from builder positions using it (last changed 7/20/98) *Styx*  4/11/03

#include <move.h>
#include <std.h>

inherit DAEMON;

int help();

int
cmd_summon(string str) {
  object      ob, prev;
  int         result;
  if((string)TP->query_position() == "builder" || (string)TP->query_position() == "apprentice")
    return notify_fail("Sorry but you aren't supposed to be summoning anyone.\n");

  if(!str) {
    return help();
  }
    ob=find_living(lower_case(str));
    if(!ob) return help();

    if(interactive(ob) && (ob->query_level() > TP->query_level()) &&
        !archp(TP) )
        return notify_fail("You can't summon a higher level wiz!\n");
    if(environment(ob)==environment(this_player()))
    {
      write("You twitch.\n");
      say(this_player()->query_cap_name()+" twitches.\n");
      return 1;
    }

    tell_object(ob, "You are magically teleported somewhere.\n");
    ob->move_player(environment(this_player()));
    return 1;
}

int help() {
  write("Command: summon\nSyntax: summon <player>\n"+
        "If the name of an active player is passed then this "+
        "command summons that player to you.\n\n"+
        "See also: move\n"+
        "");
  return 1;
}
