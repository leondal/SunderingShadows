#include <std.h>
#include "../farm.h"

inherit BARNYARD;

void create(){
   ::create();
   set_exits(([
      "northwest" : PATHS"farm4",
      "north" : PATHS"farm5",
      "northeast" : PATHS"farm6",
      "west" : PATHS"farm7",
      "east" : PATHS"farm9",
      "southwest" : PATHS"farm11",
      "south" : PATHS"farm12",
      "southeast" : PATHS"farm13"
   ]));
}