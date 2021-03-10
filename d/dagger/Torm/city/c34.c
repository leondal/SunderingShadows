#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("State road");
  set_long(
  "State road.\n"
  "  Just south of here you can see the central marketplace of Torm bustling with activity."
   " State road continues to the north where it intersects with the city walls and Tanar road."
  );
  set("night long",
  "%^BLUE%^"
   "State road is covered in a light fog that can make finding your"+
   " way a bit difficult. The wall around Torm's park to the east rises"+
   " above the fog, and gives you a better idea of where you are."
  );
  set_exits(([
  "north":TCITY+"c24",
  "south":TCITY+"c43",
  ]));
}
