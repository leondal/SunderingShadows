#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
  set_short(
    "Beneath the Torm townhall"
  );
  set_property("indoors",1);
  set_long(
  "  This dark stone hallway goes north and east."
  "  A low walled well is in the southwest corner supplies fresh water to the mansion above."
  "  A chill rises from the stones of this hallway and you feel like there is always something standing behind you."
  );
  set_exits(([
  "north":TCITY+"c151",
  "east":TCITY+"c154",
  ]));
  set_items(([
  "walls":"The walls here are dull grey stone.",
  "floor":"The floor here is rough grey stone.",
  ({"ceiling","roof"}):"The ceiling here is rough grey stone.",
  "well":"The well is in the southwest corner of the hall and is surrounded by a short stone wall, although not high enough to offer much protection from falling in it.",
  "bucket":"There is a steel bucket resting on the edge of the well connected to a rope thats tied to a ring in the wall.",
  ]));
}
