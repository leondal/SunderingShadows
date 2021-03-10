#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit TRAILBASE;

void create() {
  ::create();
  set_exits( ([  "northwest" : ROOMS + "trail07",
                 "southeast" : ROOMS + "trail05",
                 "southwest" : ROOMS + "lake22"]) );
  set_monsters(({MOB +"mungrraff"}), 1); 
  set_repop(100);
}
