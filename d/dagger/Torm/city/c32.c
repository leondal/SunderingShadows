#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("West Tanar just north of the city gates");
  set_door("door",TCITY+"c33","east","masterkey");
  set_long(
  "West Tanar just north of the city gates.\n"
    "  You can see Torm's west city gates south of you from here."
  "  A well made building to the east has a healers sign over it."
   "  This road continues along the edges of the city to the north."
  );
  set("night long",
  "%^BLUE%^"
  "A light fog has settled over the city this night.  There is a"+
  " building to the east here with a healer's sign on the door.  It"+
  " appears to be closed at night, but for emergencies you're sure"+
  " the healer wouldn't mind.  Tanar road continues north and"+
  " south and you think you can almost make out Torm's west gates"+
  " further south of here."
  );
   add_item("building","There is a building to the east here with the sign of a healer on it.");
  set_exits(([
  "north":TCITY+"c22",
  "south":TCITY+"c40",
  "east":TCITY+"c33",
  ]));
}
