#include <std.h>
#include "../dragon.h";

inherit BTOWN;

void create() {
   ::create();
   set_light(0);
   set_indoors(1);
   set_short("Ruined shop");
   set_long(
      "%^BOLD%^%^BLACK%^The roof of this once modest shop seems to have been hit with devastating force,"+
      " evidenced by the numerous holes that are now present. Most of the walls lay in ruin and"+
      " barely support what is left of the structure. This was once %^RED%^Sanctuary's Armory%^BOLD%^%^BLACK%^."+
      " Many forms of armor are now scattered about the rubble that is the floor."+
      " The large forge that was located in the corner of the room has been ripped out and upturned."+
      " A ripped up, decaying, and wooden %^YELLOW%^sign%^BLACK%^ is on the floor in front of what"+
      " used to be the counter."
   );
   set_exits(([
      "west":TOWN+"roadS1"
   ]));
   set_items(([
     "forge" : "The forge that has been ripped out the wall is testimony to the destruction that took place here.",
     "sign" : "The only thing you can make out from the sign is the word %^BOLD%^%^RED%^armor%^RESET%^.",
     ({"walls","floor","ceiling"}) : "The stucture is barely holding up. It looks like it could fall in at any moment."
 ] ));
  }
