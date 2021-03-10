#include <std.h>
inherit VAULT;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
set_door("door", "/d/koenig/town/house1.c", "door", "open_door");
  set_open("door", 0);
  set_string("door", "open", "The door opens soundlessly on its hinges as you proceed to leave the house.");
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("The Entrance Way");
  set_long("%^RESET%^%^CYAN%^You find yourself standing in an entrance way. The place looks very warm and inviting. To your east is the %^ORANGE%^kitchen%^RESET%^%^CYAN%^, to the west is a %^ORANGE%^sitting room%^RESET%^%^CYAN%^, and to the south you can see some %^MAGENTA%^carpeted%^RESET%^%^CYAN%^ stairs leading up.\n");
  set_smell("default", "You can smell wood burning in the fireplace.");
  set_listen("default", "You hear a woman's sultry laughter coming from upstairs.");
  set_exits( ([
     "door" : "/d/koenig/town/house1",
     "east" : "/d/koenig/town/house3",
     "west" : "/d/koenig/town/house4",
     "south" : "/d/koenig/town/house5"
]) );
}
