#include <std.h>
#include "../tormdefs.h"
inherit VAULT;
void create()
  {
  ::create();
  set_property("light",2);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_short("West Tanar just south of the city gates");
  set_long(
  "West Tanar just south of the city gates.\n"
  "  Torm's west city gates lie open to the north of you from here, a"+
  " few guards watch the travelers pass by.  You can hear the sounds"+
  " of a market to the east, and see the city wall to the south."+
  "  A sign with a lyre and a drum hangs over the door to the east."
  );
  set("night long",
  "%^BLUE%^"
  "A light fog has settled over the city, obscuring the ground from"+
  " view.  There is hardly any of it around here, and the open door"+
  " to the west spills light out onto the street, further chasing it"+
  " away.  The door has the sign of a lyre and a drum hanging over the"+
  " shop, and it is one of the few places that is opened at night it"+
  " seems.  You can make out the city wall to the south, and Tanar road"+
  " continues to the north."
  );
  set_smell("default","You smell salt in the air from the Dagger Sea.");
  set_listen("default","The waves of the sea wash against the docks.");

  set_exits(([
  "north":TCITY+"c40",
  "south":TCITY+"c59",
  "west" : TCITY+"c53",
  ]));
  set_door("door",TCITY+"c53","west",0);
  set_open("door",1);
}
