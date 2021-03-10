#define TEMP "/d/av_rooms/tiamat/"+
#include <std.h>

inherit "/d/av_rooms/tiamatkeep";

void create(){
   ::create();
   set_exits(([
      "west" : TEMP"tiamatfloor2-2",
      "east" : TEMP"tiamatfloor2-6",
      "down" : TEMP"tiamatfloor1-2"
   ]));
}