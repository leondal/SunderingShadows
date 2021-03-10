#define TEMP "/d/av_rooms/tiamat/"+
#include <std.h>

inherit "/d/av_rooms/tiamatkeep";

void create(){
   ::create();
   set_exits(([
      "north" : TEMP"tiamatfloor2-6",
      "east" : TEMP"tiamatfloor2-8",
      "south" : TEMP"tiamatfloor2-9"
   ]));
   set_door("door",TEMP"tiamatfloor2-8","east","Tiamat_keep_key","lock");
   set_open("door",0);
   set_locked("door", 1, "lock");
   lock_difficulty("door",-90, "lock");
   set_door("battered door",TEMP"tiamatfloor2-9","south","Tiamat_keep_key","lock");
   set_open("battered door",0);
   set_locked("battered door", 1, "lock");
   lock_difficulty("battered door",-90, "lock");
}