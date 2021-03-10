#define TEMP "/d/av_rooms/tiamat/"+
#include <std.h>

inherit "/d/av_rooms/tiamatkeep";

void create(){
   ::create();
   set_exits(([
      "east" : TEMP"tiamatfloor2-1",
      "south" : TEMP"tiamatfloor2-3"
   ]));
}