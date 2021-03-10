#include <std.h>
inherit VAULT;

void create()
{
  ::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
  set_door("gate", "/d/koenig/town/room12.c", "gate", "open_gate");
  set_open("gate", 0);
  set_string("gate", "open", "The gates hinges creak loudly as they work to open the gate.");
  set_door("door", "/d/koenig/town/house2.c", "door", "open_door");
  set_open("door", 0);
  set_string("door", "open", "The door opens soundlessly on its hinges.");
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("The Front Yard");
  set("day long", "%^RESET%^%^ORANGE%^You stand in front of a house that looks very warm and welcoming. You have traveled such a long way, maybe you can go inside and rest a spell. The door is before you, and all around you can see %^GREEN%^climbing ivy%^ORANGE%^ and %^GREEN%^hedges%^ORANGE%^ surrounding the small yard. You notice %^BOLD%^%^BLACK%^smoke%^RESET%^%^ORANGE%^ coming from the chimney.%^RESET%^\n");
   set("night long", "%^RESET%^%^BLUE%^You stand before a home that looks very warm and welcoming. There must be a %^BOLD%^%^RED%^fire%^RESET%^%^BLUE%^ in the fireplace for there is %^BOLD%^%^BLACK%^smoke%^RESET%^%^BLUE%^ coming from the chimney. Mmmm, you can smell food cooking as well. You have traveled far and it would be so nice to rest a spell, maybe they would welcome you inside? At least until morning surely.%^RESET%^\n");
  set_smell("default", "It smells of only green things here, it smells good.");
  set_listen("default", "You can hear a woman's sultry laughter coming from inside the house.");
  set_exits( ([
     "gate" : "/d/koenig/town/room12",
     "door" : "/d/koenig/town/house2"
]) );
}
