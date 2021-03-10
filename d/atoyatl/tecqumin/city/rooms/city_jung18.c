#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit TECBASE + "jung_base.c";


void create() {
  ::create();

  add_item( ({"river", "", "water"}), 
    "Only glimpses of the fast flowing water are available from here.");

  set_exits(([
      "east" : JUNG_ROOM6 + "ragged_road_connection",
      "west" : CITY_ROOM + "city_jung17"
   ]));
}

string long_desc(){
  return ::base_desc() + " To the east, occasional flashes and sparkles hint at a river running through the jungle.";
}
