// Writen by Fire Dragon. (Disciptions by Melnmarn)

#include <std.h>
#include "zeek.h"

inherit BANK;

void create() 
{
  ::create();
  set_short("Beach Bank.");
  set_long("This is the Beach Bank.  "
           "There are several tellers lined up ready to take your requests.  "
           "This bank is one that is connected to others banks.  "
           "There are several people in here talking with tellers and recieving"
           " money from them.  One teller looks at you and stands tall ready "
           "to take your request."
           "There is a small note that has the commands that will work in here.");
  set_items(
	(["bank" : "You are in its huge lobby. There is a counter in "
	    "front of you\nand and exit behind you.",
	  "other banks" : "There are several other banks connected to this one.",
	  "note" : "Try reading it!",
	  "teller" : "She is dressed up in a black suit.",
	  "line" : "There is a short line right now.",
	  "money" : "You see several people flapping their money around in the air."]));
  set_exits( ([ "out" : "/d/shadow/room/beach/park1" ]) );
  set_smell("default","You smell the melted gold.");
  set_listen("default","You hear the sound of coins all around you.");
}
