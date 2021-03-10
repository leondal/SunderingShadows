#include <std.h>
#include "../../undead.h"

inherit INH+"tomb_five.c";

void create() 
{
 ::create();

    set_long("%^BLUE%^You are in a faintly lit Chamber\n"
        "%^BOLD%^%^BLACK%^You find yourself surrounded by weapons and armor "
        "of Kartakass's undead army. Maps line several of the the walls with "
        "detailed layouts of castles and battlefields from days of old.  "
        "Perhaps these were the maps Kartakass used to plan his war so many "
        "years ago. In one corner of the room you see a small rocking chair.  "
        "This strikes you as a very odd thing to put in a war room so you "
        "look at it further, and notice that it is still rocking. You realize "
        "that you are not alone and you stand ready for combat just as the "
        "first blow hits you!");
 
    set_exits(([
        "up":HALL+"chamber"
             ]));

}

void reset() 
{
  ::reset();
  if(!present("seer")) { new(MON+"seer")->move(TO); }
  return;
}
