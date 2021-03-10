#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_short("State road in south Torm");
  set_long(
  "State road in south Torm.\n"
  "  State road here just south of the marketplace of Torm is still loud from the calls of the vendors there."
   "  Just a little further south State road intersects with Tanar at the city walls."
   "  A walled compound blocks the sight to the west and an ornate, although a small, church is to the east."
  );
  set("night long",
   "There is a light fog that has settled over the city of Torm.  The"+
  " ornate church on the east stands tall above the fog and you can"+
  " see a soft light within the walls."
  );
   add_item("church","There is a small but ornate church to the east here.");
  set_exits(([
  "north":TCITY+"c62",
  "south":TCITY+"c79",
  "east":TCITY+"c101",
  ]));
  set_door("door",TCITY+"c101","east","Torm masterkey");
  set_open("door",1);
  "/d/dagger/Torm/city/c101"->set_open("door",1);
}

