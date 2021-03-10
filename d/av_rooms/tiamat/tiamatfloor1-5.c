#define TEMP "/d/av_rooms/tiamat/"+
#include <std.h>

inherit "/d/av_rooms/tiamatkeep";

void create(){
   ::create();
   set_exits(([
      "north" : TEMP"tiamatfloor1-4",
      "west" : TEMP"tiamatfloor1-6",
      "south" : TEMP"tiamatfloor1-7",
      "east" : TEMP"tiamatfloor1-8"
   ]));
}