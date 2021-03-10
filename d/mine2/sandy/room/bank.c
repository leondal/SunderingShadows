// Writen by Fire Dragon. (Disciptions by Melnmarn)

#include <std.h>
#include "abolition.h"

inherit BANK;

void create() 
{
  ::create();
  set_short("Sandy Bank.");
  set_long("This is the Sandy Bank.  "
           "This bank is filled with many large vaults of money.  "
           "There are several large fighters standing infront of the vaults "
           "to keep any thiefs who are boared out of them.  There is a monk "
           "who is sitting at a desk, and must be the one who deals with your "
           "Money."
           "There is a note of what can be done here by the door.");
  set_items(
	(["bank" : "You are in its huge lobby. There is a counter in "
	    "front of you\nand and exit behind you.",
	  "other banks" : "There are several other banks connected to this one.",
	  "note" : "Try reading it!",
	  "teller" : "She is dressed up in a black suit.",
	  "line" : "There is a short line right now.",
	  "money" : "You see several people flapping their money around in the air."]));
  set_exits( ([ "out" : "/d/mine2/sandy/room/sandy5" ]) );
  set_smell("default","You smell the melted gold.");
  set_listen("default","You hear the sound of coins all around you.");
}
