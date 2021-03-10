#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_short("Tanar at the sea's edge");
  set_long(
   "Tanar at the sea's edge.\n"+
   " Tanar road continues to the north and west from here, curving along the"+
   " north side of Torm's Harbor. To the east is the grand entrance of Torm's incredible amphitheatre"+
   " that is perched at the very edge of the city, overlooking the Dagger Sea. There is a wide arched doorway"+
   " that is inviting to all who wish to enjoy the theatrical arts.");
  set("night long",
  "%^BLUE%^"
   "You're standing at the entrance of Torm's great amphitheatre. Twin lanterns hang on either side of the"+
   " arched entrance way, they are lit and invite all who wish to enjoy the theatrical arts to come inside."+
   " Tanar road curves here, leading off to the west and north."
  );
  set_exits(([
  "north":TCITY+"c29",
  "west":TCITY+"c37",
   "east" : TCITY+"ampitheatre",
  ]));
}
