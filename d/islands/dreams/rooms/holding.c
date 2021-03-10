#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(BARREN);
   set_travel(PAVED_ROAD);
  set_property("indoors",1);
  set_property("light",1);
   set_property("no scry",1);
   set_property("no teleport",1);
  set_short("");
  set_long("");
}
